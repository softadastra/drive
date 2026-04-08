#include <memory>
#include <string>

#include <drive/api/ApiServer.hpp>
#include <softadastra/cli/cli.hpp>
#include <softadastra/cli/command/CliCommand.hpp>
#include <softadastra/cli/command/ICommandHandler.hpp>
#include <softadastra/cli/core/CliConfig.hpp>
#include <softadastra/cli/parser/ParsedCommand.hpp>
#include <softadastra/cli/types/CliCommandType.hpp>
#include <softadastra/cli/types/CliErrorCode.hpp>

namespace drive_api = drive::api;
namespace sa_cli = softadastra::cli;
namespace sa_cmd = softadastra::cli::command;
namespace sa_core = softadastra::cli::core;
namespace sa_parser = softadastra::cli::parser;
namespace sa_types = softadastra::cli::types;

namespace
{
  class ServeCommandHandler : public sa_cmd::ICommandHandler
  {
  public:
    sa_types::CliErrorCode handle(const sa_parser::ParsedCommand &command) override
    {
      if (command.has_option("help"))
      {
        return sa_types::CliErrorCode::CommandNotFound;
      }

      drive_api::ApiServer server;
      return server.run() == 0
                 ? sa_types::CliErrorCode::None
                 : sa_types::CliErrorCode::CommandExecutionFailed;
    }
  };
}

int main(int argc, char **argv)
{
  sa_core::CliConfig config;
  config.app_name = "drive-api";
  config.version = "0.1.0";
  config.interactive = false;
  config.show_banner = false;

  sa_cli::CliService service(config);

  service.register_command(
      sa_cmd::CliCommand{
          "serve",
          "Start the Drive API service",
          "serve [--host HOST] [--port PORT] [--help]",
          sa_types::CliCommandType::Custom,
          {},
          {
              {"help", "h", "Show help for this command", "", false},
              {"host", "", "Bind host address", "HOST", true},
              {"port", "p", "Bind port", "PORT", true},
          }},
      std::make_shared<ServeCommandHandler>());

  sa_cli::CliOptions options;
  options.interactive = false;

  if (argc <= 1)
  {
    options.command = "serve";
  }
  else
  {
    std::string command;
    for (int i = 1; i < argc; ++i)
    {
      if (!command.empty())
      {
        command += " ";
      }
      command += argv[i];
    }
    options.command = command;
  }

  return service.run(options);
}

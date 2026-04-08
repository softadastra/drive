#include <iostream>

#include <drive/api/ApiServer.hpp>

namespace drive::api
{
  int ApiServer::run()
  {
    std::cout << "Drive API server bootstrap OK\n";
    std::cout << "Backend is ready for future HTTP integration\n";
    return 0;
  }
}

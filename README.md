# softadastra/app

> Application orchestration layer for Softadastra systems.

The `app` module is the **orchestrator of the entire system**.

It connects all modules together and defines:

> How the system starts, runs, and stops.

---

## Purpose

The goal of `softadastra/app` is simple:

> Assemble all modules into a working system.

---

## Core Principle

> Compose, don’t implement.

The `app` module:

* Does not implement core logic
* Does not store data
* Does not handle sync decisions

👉 It wires everything together.

---

## Responsibilities

The `app` module provides:

* System bootstrap
* Module initialization
* Dependency wiring
* Runtime management
* Lifecycle control (start / stop)

---

## What this module does NOT do

* No sync logic (sync module)
* No storage logic (store module)
* No network implementation (transport module)
* No filesystem observation (fs module)

👉 It orchestrates, nothing more.

---

## Design Principles

### 1. Composition over logic

All business logic lives in modules.

The app only connects them.

---

### 2. Explicit wiring

All dependencies must be:

* Visible
* Configurable
* Replaceable

---

### 3. Lifecycle control

The app defines:

* Startup order
* Shutdown order
* Runtime coordination

---

### 4. Isolation

Modules should not depend on each other implicitly.

The app connects them explicitly.

---

## Module Structure

```id="appx1"
modules/app/
├── include/softadastra/app/
│   ├── DriveApp.hpp
│   ├── Runtime.hpp
│   ├── Bootstrap.hpp
│   └── ServiceContainer.hpp
└── src/
```

---

## Core Components

### DriveApp

Main application entry.

Responsible for:

* Initializing modules
* Starting the system
* Managing runtime

---

### Runtime

Handles:

* Execution loop
* Background tasks
* System state

---

### Bootstrap

Responsible for:

* Loading configuration
* Initializing services
* Preparing environment

---

### ServiceContainer

Dependency container.

Provides:

* Module instances
* Dependency injection
* Access to shared services

---

## Example Usage

```cpp id="ex11"
#include <softadastra/app/DriveApp.hpp>

using namespace softadastra::app;

int main()
{
    DriveApp app;

    app.start();

    return 0;
}
```

---

## System Initialization Flow

1. Load configuration
2. Initialize core services
3. Initialize modules:

   * fs
   * wal
   * metadata
   * discovery
   * transport
   * store
   * sync
4. Start runtime
5. System becomes active

---

## Shutdown Flow

1. Stop runtime
2. Flush pending operations
3. Close connections
4. Persist state
5. Shutdown modules

---

## Integration

The `app` module connects:

* core
* fs
* wal
* metadata
* discovery
* transport
* sync
* store
* cli

---

## Dependencies

### Internal

* All Softadastra modules

### External

* Standard C++ libraries

---

## MVP Scope

* Single runtime instance
* Basic module wiring
* Simple lifecycle management
* No advanced configuration system

---

## Roadmap

* Advanced configuration system
* Dependency injection improvements
* Multi-instance support
* Plugin system
* Observability (metrics, tracing)
* Service health monitoring

---

## Rules

* Never implement business logic
* Never hide dependencies
* Always keep wiring explicit
* Always control lifecycle cleanly

---

## Philosophy

The app is not the system.

> It is the conductor of the system.

---

## Summary

* Assembles modules
* Controls lifecycle
* Manages runtime
* Connects everything together

---

## License

See root LICENSE file.

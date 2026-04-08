# Changelog - softadastra/app

All notable changes to the **app module** are documented in this file.

The `app` module is responsible for **orchestrating the system**, including module wiring, lifecycle management, and runtime coordination.

---
## [v0.2.0]

### Improvements

- introduce CLI-based entrypoint for `drive_api`
- integrate Softadastra CLI for command handling (`serve`, `help`, `version`)
- improve project structure:
  - add `apps/` and `services/` modular layout
  - add dedicated CMake configuration for services
- improve build system consistency across components and services

### Fixes

- fix Softadastra dependency resolution in adapter (use `find_package`)
- fix build failures due to missing CMake targets and sources
- fix command routing (proper handling of CLI arguments)

## [0.1.0] - Initial Application Orchestrator

### Added

* `DriveApp` main application entry point
* `Runtime` for execution control
* `Bootstrap` for initialization logic
* `ServiceContainer` for dependency management
* Basic startup and shutdown lifecycle
* Initial module wiring:

  * core
  * fs
  * wal
  * metadata
  * discovery
  * transport
  * store
  * sync

### Design

* Composition-first architecture
* Explicit dependency wiring
* No business logic inside app

---

## [0.1.1] - Lifecycle Stability

### Improved

* More reliable startup sequence
* Safer shutdown handling
* Better ordering of module initialization

### Fixed

* Edge cases during early shutdown
* Missing cleanup of certain services

---

## [0.2.0] - Runtime Improvements

### Added

* Improved runtime loop management
* Background task handling support

### Improved

* Stability of long-running sessions
* Better coordination between modules

---

## [0.3.0] - Dependency Management Refinement

### Added

* Enhanced `ServiceContainer`
* Clearer dependency registration and resolution

### Improved

* Reduced coupling between modules
* More predictable initialization behavior

---

## [0.4.0] - Configuration Handling

### Added

* Basic configuration loading via `Bootstrap`
* Config structure for application setup

### Improved

* Flexibility of system initialization
* Separation between config and runtime

---

## [0.5.0] - Integration Enhancements

### Added

* Stronger integration with CLI layer
* Clear entry points for command-driven execution

### Improved

* Communication between CLI and app
* Execution flow consistency

---

## [0.6.0] - Observability Foundations

### Added

* Basic logging hooks in runtime
* Lifecycle event tracing (start, stop, errors)

### Improved

* Debug visibility of system behavior
* Troubleshooting support

---

## [0.7.0] - Extraction Ready

### Added

* Namespace stabilization (`softadastra::app`)
* Public API cleanup
* Documentation for orchestration interfaces

### Improved

* Decoupling from product-specific assumptions
* Prepared for reuse in:

  * Softadastra SDK
  * Future applications
  * Other runtimes

---

## Roadmap

### Planned

* Advanced dependency injection system
* Plugin/module loading system
* Multi-runtime support
* Advanced configuration (profiles, environments)
* Metrics and tracing integration
* Health monitoring system

---

## Philosophy

The app does not define the system.

> It defines how the system runs.

---

## Rules

* Never contain business logic
* Always wire dependencies explicitly
* Always control lifecycle deterministically
* Always remain replaceable

---

## Summary

The `app` module ensures:

* System orchestration
* Lifecycle management
* Module integration

It is the **central conductor of Softadastra**.

#ifndef STANDOFF2_DUMPER_CORE_H
#define STANDOFF2_DUMPER_CORE_H

#include <memory>

#include "Dumper.h"
#include "Il2CppApi.h"
#include "Injection.h"
#include "Log.h"
#include "Memory.h"

class Context {
public:
  std::unique_ptr<Log> log;
  std::unique_ptr<Injection> injection;
  std::unique_ptr<Dumper> dumper;
  std::unique_ptr<Memory> memory;
  std::unique_ptr<Il2CppApi> il2cpp;

  explicit Context(std::unique_ptr<Log> log, std::unique_ptr<Injection> injection,
                   std::unique_ptr<Dumper> dumper, std::unique_ptr<Memory> memory,
                   std::unique_ptr<Il2CppApi> il2cpp)
      : log(std::move(log)),
        injection(std::move(injection)),
        dumper(std::move(dumper)),
        memory(std::move(memory)),
        il2cpp(std::move(il2cpp)) {
  }
  ~Context() = default;

  bool initialize(bool inject);
};

Context& g();

#endif

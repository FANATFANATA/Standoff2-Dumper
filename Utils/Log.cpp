#include "Log.h"

#include <android/log.h>

#include <cstdarg>
#include <iostream>

void Log::info(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  va_list args_copy;
  va_copy(args_copy, args);

  __android_log_vprint(ANDROID_LOG_INFO, "[Dumper]", fmt, args);

  char buffer[4096];
  vsnprintf(buffer, sizeof(buffer), fmt, args_copy);
  std::cout << "[INFO] " << buffer << std::endl;

  va_end(args_copy);
  va_end(args);
}

void Log::debug(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  va_list args_copy;
  va_copy(args_copy, args);

  __android_log_vprint(ANDROID_LOG_DEBUG, "[Dumper]", fmt, args);

  char buffer[4096];
  vsnprintf(buffer, sizeof(buffer), fmt, args_copy);
  std::cout << "[DEBUG] " << buffer << std::endl;

  va_end(args_copy);
  va_end(args);
}

void Log::error(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  va_list args_copy;
  va_copy(args_copy, args);

  __android_log_vprint(ANDROID_LOG_ERROR, "[Dumper]", fmt, args);

  char buffer[4096];
  vsnprintf(buffer, sizeof(buffer), fmt, args_copy);
  std::cout << "[ERROR] " << buffer << std::endl;

  va_end(args_copy);
  va_end(args);
}

void Log::warning(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  va_list args_copy;
  va_copy(args_copy, args);

  __android_log_vprint(ANDROID_LOG_WARN, "[Dumper]", fmt, args);

  char buffer[4096];
  vsnprintf(buffer, sizeof(buffer), fmt, args_copy);
  std::cout << "[WARN] " << buffer << std::endl;

  va_end(args_copy);
  va_end(args);
}

void Log::fatal(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  va_list args_copy;
  va_copy(args_copy, args);

  __android_log_vprint(ANDROID_LOG_FATAL, "[Dumper]", fmt, args);

  char buffer[4096];
  vsnprintf(buffer, sizeof(buffer), fmt, args_copy);
  std::cout << "[FATAL] " << buffer << std::endl;

  va_end(args_copy);
  va_end(args);
}

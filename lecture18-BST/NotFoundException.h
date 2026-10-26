#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H

#include <stdexcept>
#include <string>

// Exception thrown when a requested entry is not present in a tree.
class NotFoundException : public std::runtime_error
{
public:
   explicit NotFoundException(const std::string& message)
      : std::runtime_error(message)
   {
   }
};

#endif

#ifndef PRECOND_VIOLATED_EXCEP_H
#define PRECOND_VIOLATED_EXCEP_H

#include <stdexcept>
#include <string>

// Exception thrown when a method's precondition is violated.
class PrecondViolatedExcep : public std::runtime_error
{
public:
   explicit PrecondViolatedExcep(const std::string& message)
      : std::runtime_error(message)
   {
   }
};

#endif

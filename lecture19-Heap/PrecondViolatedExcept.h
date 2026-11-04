#ifndef PRECOND_VIOLATED_EXCEPT_H
#define PRECOND_VIOLATED_EXCEPT_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::runtime_error
{
public:
   explicit PrecondViolatedExcept(const std::string& message)
      : std::runtime_error(message)
   {
   }
};

#endif

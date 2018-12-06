#include "lib_source.h"

namespace cpplib
{
    BuildNumber createBuildNumber()
    {
        return 25;
    }
    
    BuildNumber buildNumber()
    {
        return createBuildNumber();
    }
} // namespace cpplib


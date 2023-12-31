#include "Configure.hpp"

void buildSpecification()
{

    DSC<CppSourceTarget> &app = GetCppExeDSC("app");
    app.getSourceTarget().MODULE_FILES("main.cpp");

    DSC<CppSourceTarget> &stdhu = GetCppObjectDSC("stdhu");
    stdhu.getSourceTarget().assignStandardIncludesToPublicHUDirectories();

    DSC<CppSourceTarget> &sum = GetCppObjectDSC("sum").PRIVATE_LIBRARIES(&stdhu);
    sum.getSourceTarget().MODULE_FILES("sum.cpp");

    DSC<CppSourceTarget> &multiply = GetCppObjectDSC("multiply").PRIVATE_LIBRARIES(&stdhu);
    multiply.getSourceTarget()
        .MODULE_FILES("multiply.cpp").PRIVATE_COMPILE_DEFINITION("MULTIPLY");

    app.PRIVATE_LIBRARIES(&sum, &multiply, &stdhu);
}

MAIN_FUNCTION
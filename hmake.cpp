#include "Configure.hpp"

void buildSpecification()
{

    DSC<CppSourceTarget> &app = GetCppExeDSC("app");
    app.getSourceTarget().setModuleScope().MODULE_FILES("main.cpp");

    DSC<CppSourceTarget> &stdhu = GetCppObjectDSC("stdhu");
    stdhu.getSourceTarget().setModuleScope(app.getSourceTargetPointer()).assignStandardIncludesToHUIncludes();

    DSC<CppSourceTarget> &sum = GetCppObjectDSC("sum").PRIVATE_LIBRARIES(&stdhu);
    sum.getSourceTarget().setModuleScope(app.getSourceTargetPointer()).MODULE_FILES("sum.cpp");

    DSC<CppSourceTarget> &multiply = GetCppObjectDSC("multiply").PRIVATE_LIBRARIES(&stdhu);
    multiply.getSourceTarget()
        .setModuleScope(app.getSourceTargetPointer())
        .MODULE_FILES("multiply.cpp").PRIVATE_COMPILE_DEFINITION("MULTIPLY");

    app.PRIVATE_LIBRARIES(&sum, &multiply);
}

MAIN_FUNCTION
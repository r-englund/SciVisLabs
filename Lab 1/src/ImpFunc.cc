
#include "vtkImplicitFunction.h"

class ImpFunc : public vtkImplicitFunction {
public:
    vtkTypeMacro(ImpFunc,vtkImplicitFunction);
    void PrintSelf(ostream& os, vtkIndent indent);

    // Description
    // Create a new function
    static ImpFunc * New(void);

    // Description
    // Evaluate function
    double EvaluateFunction(double x[3]);
    double EvaluateFunction(double x, double y, double z) {
	return this->vtkImplicitFunction::EvaluateFunction(x, y, z);
    }
    
    // Description
    // Evaluate gradient for function
    void EvaluateGradient(double x[3], double n[3]);

    // If you need to set parameters, add methods here

protected:
    ImpFunc();
    ~ImpFunc() {}
    ImpFunc(const ImpFunc&) {}
    void operator=(const ImpFunc&) {}

    // Add parameters/members here if you need
};

//------------------------------------------------------------------------------
ImpFunc * ImpFunc::New()
{
    // Skip factory stuff - create class
    return new ImpFunc;
}


// Create the function
ImpFunc::ImpFunc()
{
    // Initialize members here if you need
}

// Evaluate function
double ImpFunc::EvaluateFunction(double x[3])
{
    // Put your code here
    return 0;    // the value of the function
}

// Evaluate gradient for function
void ImpFunc::EvaluateGradient(double x[3], double n[3])
{
    // Not use and thus not needed
}

void ImpFunc::PrintSelf(ostream& os, vtkIndent indent)
{
    vtkImplicitFunction::PrintSelf(os,indent);
}

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

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
	double n,l,m;
	double Z,a0;
};

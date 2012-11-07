#include "ImpFunc.h"

void CartesianCoords2SphericalCoords(double x,double y,double z,double &r,double &theta,double &phi){
	r = sqrt(x*x+y*y+z*z);
	if(r == 0){
		theta = 0;
		phi = 0;
		return;
	}
	theta = acos(z/r);
	phi = atan2(y,x);
}

//------------------------------------------------------------------------------
ImpFunc * ImpFunc::New()
{
    // Skip factory stuff - create class
    return new ImpFunc;
}


// Create the function
ImpFunc::ImpFunc()
{
	n = 2;
	l = 1;
	m = 0;

	Z = 1;
	a0 = 1;// 0.53;// (Bohr radius)

    // Initialize members here if you need
}

// Evaluate function
double ImpFunc::EvaluateFunction(double x[3])
{
	double d,r,theta,phi;
	CartesianCoords2SphericalCoords(x[0],x[1],x[2],r,theta,phi);
	d  = 1.0/(4.0*sqrt(2*M_PI));
	d *= pow((Z/a0),1.5);
	d *= ((Z*r)/a0);
	d *= exp(-((Z*r)/(2*a0)));
	d *= cos(theta);//*/


    // Put your code here
    return d*d;    // the value of the function
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

#ifndef _SUBPLANE_H_
#define _SUBPLANE_H_

#include "Matrix.h"

class SubPlane {
public:
	/*
	 * Индексная строка симплексной таблицы
	*/

	double * indexString;

 	/*
	 * Значения базисных переменных
	 * в симплекс теблице.
	*/

	matrix* basisVars;

	/*
	 * Коэффициенты при  переменных
	 * в симплекс-таблице.
	*/

	matrix* varsFactors;

SubPlane(unsigned int _vars) : vars(_vars)
	{
		basisVars = new matrix(2, vars);
		varsFactors = new matrix(vars, vars*2);
		indexString = new double[vars*2];
	}

	void operator=(SubPlane& sp)
	{
		memcpy(indexString, sp.indexString, vars*2*sizeof(double));
		*basisVars = *sp.basisVars;
		*varsFactors = *sp.varsFactors;
	}
private:
	unsigned int vars;
};

#endif /* _SUBPLANE_H_ */

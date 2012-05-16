#ifndef _LOGISTICREGRESSIONSCORETEST_H_
#define _LOGISTICREGRESSIONSCORETEST_H_

#include "MathMatrix.h"
#include "MathCholesky.h"
#include "StringHash.h"
#include "StringArray.h"
#include <cmath>
#include "MathStats.h"
#include "MathSVD.h"

#include "LogisticRegression.h"

class LogisticRegressionScoreTest{
  public:
    LogisticRegressionScoreTest();
    /**
     * @param colToTest: 0-based
     */
	bool FitLogisticModel(Matrix &X, Vector &y, int colToTest, int nRound);

    bool FitNullModel(Matrix& Xnull, Vector& y, int nRound);
    bool TestCovariate(Matrix& Xnull, Vector& y, Vector& Xcol);

    /**
     * Test H0: \beta = 0  (\beta is multiple dimension).
     * y ~ \beta * Xcol + \gamma * Xnull  
     */
    bool TestCovariate(Matrix& Xnull, Vector& y, Matrix& Xcol);
    
    
    // fit y~1+ beta*x  (no covariate)
    bool TestCovariate(Vector& x, Vector& y);
    /**
     * Test y~ 1 + \beta * X (no covariate)
     */
    bool TestCovariate(Matrix& x, Vector& y);

    double GetPvalue() const {return this->pvalue;};
  private:
	void splitMatrix(Matrix& x, int col, Matrix& xnull, Vector& xcol); 
	double pvalue;
    LogisticRegression lr;
};


#endif /* _LOGISTICREGRESSIONSCORETEST_H_ */

#ifndef XAPPLICATION
#define XAPPLICATION
#include "GraphX.h"

class XApplication : public GraphXApp
{
public:
	XApplication();
	~XApplication();

	//@Override
	virtual int Run() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;

	//Here is your methods

protected:

private:
	//Here is your properties
};

#endif


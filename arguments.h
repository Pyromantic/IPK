#pragma once

class arguments {
public:
	arguments();

	~arguments();

protected:
	virtual void argcCheck(const int);

	static const char *errors[];

	enum arguments_argc {
		NO_ARGUMENTS = 2,
	};

	enum errorFlags {
		FEW =	0,
		MANY =	1,
	};
};

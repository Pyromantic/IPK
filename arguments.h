#pragma once

class arguments {
public:
	arguments();

	~arguments();

protected:
	virtual inline void argcCheck(const int argc) {	// method of arguments numeric check
		if (argc < NO_ARGUMENTS)
			throw errors[FEW];
	}

	static const char *errors[];

	enum arguments_argc {
		NO_ARGUMENTS = 2,
	};

	enum errorFlags {
		FEW =	0,
		MANY =	1,
	};
};

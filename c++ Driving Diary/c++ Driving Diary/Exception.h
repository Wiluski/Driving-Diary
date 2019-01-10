#pragma once


class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};
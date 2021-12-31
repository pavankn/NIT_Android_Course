#include "gdbexample_lib_3.h"

int lib3_func1(int value1, int value2, int value3, int value4)
{
#if 1
	int tmp1 = 0, tmp2 = 0;
	int res =  (value1 - (value4 - value3));
	if(res != 0){
		tmp1 = value2 / res;
	}
	tmp2 = value3 * value4;
	return tmp1 * tmp2;
#else
	int tmp1 = 0, tmp2 = 0;
	tmp1 = value2 / (value1 - (value4 - value3));
	tmp2 = value3 * value4;
	return tmp1 * tmp2;
#endif
}

int lib3_func2(int value1, int value2, int value3, int value4)
{
	int tmp1 = 0, tmp2 = 0;
	tmp1 = value1 + value2 + 2*value1;
	tmp2 = value3 + value4 + 2*value1;
	return tmp1 + tmp2;
}

int lib3_func3(int value1, int value2, int value3, int value4)
{
	float tmp = 0.0f;
	for (int i = 0; i < value3; i++){
		tmp += (value1--)*(value2--)*(value4--);
	}
	return (int)tmp;
}

int lib3_func4(int value1, int value2, int value3, int value4)
{
	float tmp = 0.0f;
#if 1
	for (int i = 0; i < value3; i++){
		if(value4 != 1){
			tmp += value2/(value4--);
		}
	}
#else
	for (int i = 0; i < value3; i++){
		tmp += value2/(value4--);
	}
#endif
	return (int)tmp;
}

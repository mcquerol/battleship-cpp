/*
 * part3tests.h
 *
 *  Created on: 11 Jan 2024
 *      Author: mateo
 */

#ifndef PART3TESTS_H_
#define PART3TESTS_H_

#include <string>

class part3tests
{
public:
	part3tests();
	void assertTrue(bool condition, std::string failedMessage);

	void part3test();
};

#endif /* PART3TESTS_H_ */

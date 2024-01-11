/*
 * part1tests.h
 *
 *  Created on: 11 Jan 2024
 *      Author: mateo
 */

#ifndef PART1TESTS_H_
#define PART1TESTS_H_

#include <string>

class part1tests
{
public:
	void assertTrue(bool condition, std::string failedMessage);
	void part1test();
};

#endif /* PART1TESTS_H_ */

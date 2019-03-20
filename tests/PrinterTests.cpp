//
// Created by barto on 19.03.19.
//

#include <gtest/gtest.h>
#include "../src/Printer.hpp"

class PrinterTests : public testing::Test {
public:
	Printer uut;
};

TEST_F(PrinterTests, shouldPrintHelloWorld) {
	ASSERT_EQ(uut.printHelloWorld(), "Hello, World!");
}

TEST_F(PrinterTests, shouldPrint420) {
	ASSERT_EQ(uut.print420(), "Smoke weed everyday");
}

TEST_F(PrinterTests, shouldPrint420Diffrently) {
	ASSERT_EQ(uut.print420(), "420");
}

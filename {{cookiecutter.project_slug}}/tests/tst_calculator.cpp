#include <catch.hpp>
#include <trompeloeil.hpp>

#include <QSignalSpy>
#include <calculator.h>

extern template struct trompeloeil::reporter<trompeloeil::specialized>;

TEST_CASE("Calculator sum is calculated correctly", "[app]")
{
    Calculator calculator;

    SECTION("1 + 1 = 2")
    {
        calculator.setA(1.0);
        calculator.setB(1.0);
        REQUIRE(qFuzzyCompare(calculator.sum(), 2.0));
    }
}

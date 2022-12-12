#include <gtest/gtest.h>
#include <calc/calc2args.h>

TEST (CalcTestSuite, ValidPlus) {
    const auto a = ArgParser("1 + 2");
    const auto b = ArgParser("-10 + -10");
    const auto c = ArgParser("111 + 222");
    const auto d = ArgParser("0 + 2.9");
    const auto e = ArgParser("12345 + 12345.64");
    const auto f = ArgParser("0.5 + 0.6");

    ASSERT_TRUE(a.isValid());
    ASSERT_TRUE(b.isValid());
    ASSERT_TRUE(c.isValid());
    ASSERT_TRUE(d.isValid());
    ASSERT_TRUE(e.isValid());
    ASSERT_TRUE(f.isValid());

    ASSERT_EQ(a.Calc(), 3);
    ASSERT_EQ(b.Calc(), -20);
    ASSERT_EQ(c.Calc(), 333);
    ASSERT_EQ(d.Calc(), 2.9);
    ASSERT_EQ(e.Calc(), 12345 * 2 + 0.64);
    ASSERT_EQ(f.Calc(), 1.1);
}

TEST (CalcTestSuite, ValidMinus) {
    const auto a = ArgParser("1.1 - 2");
    const auto b = ArgParser("-10 - -10");
    const auto c = ArgParser("111 - 222");
    const auto d = ArgParser("0 - 2.9");
    const auto e = ArgParser("12345678 - 12345678");
    const auto f = ArgParser("0 - 0");

    ASSERT_TRUE(a.isValid());
    ASSERT_TRUE(b.isValid());
    ASSERT_TRUE(c.isValid());
    ASSERT_TRUE(d.isValid());
    ASSERT_TRUE(e.isValid());
    ASSERT_TRUE(f.isValid());

    ASSERT_EQ(a.Calc(), 1.1 - 2);
    ASSERT_EQ(b.Calc(), 0);
    ASSERT_EQ(c.Calc(), -111);
    ASSERT_EQ(d.Calc(), -2.9);
    ASSERT_EQ(e.Calc(), 0);
    ASSERT_EQ(f.Calc(), 0);
}

TEST (CalcTestSuite, ValidMult) {
    const auto a = ArgParser("1 * 2");
    const auto b = ArgParser("-10 * -10");
    const auto c = ArgParser("111 * 222");
    const auto d = ArgParser("0 * 2");
    const auto e = ArgParser("12345.1 * 10");
    const auto f = ArgParser("0.1235 * 0");

    ASSERT_TRUE(a.isValid());
    ASSERT_TRUE(b.isValid());
    ASSERT_TRUE(c.isValid());
    ASSERT_TRUE(d.isValid());
    ASSERT_TRUE(e.isValid());
    ASSERT_TRUE(f.isValid());

    ASSERT_EQ(a.Calc(), 2);
    ASSERT_EQ(b.Calc(), 100);
    ASSERT_EQ(c.Calc(), 111 * 222);
    ASSERT_EQ(d.Calc(), 0);
    ASSERT_EQ(e.Calc(), 123451);
    ASSERT_EQ(f.Calc(), 0);
}

TEST (CalcTestSuite, ValidDiv) {
    const auto a = ArgParser("1 / 2");
    const auto b = ArgParser("-10 / -10");
    const auto c = ArgParser("1234567 / 10");
    const auto d = ArgParser("0 / 2");
    const auto e = ArgParser("12345 / -1");
    const auto f = ArgParser("-1 / 1");

    ASSERT_TRUE(a.isValid());
    ASSERT_TRUE(b.isValid());
    ASSERT_TRUE(c.isValid());
    ASSERT_TRUE(d.isValid());
    ASSERT_TRUE(e.isValid());
    ASSERT_TRUE(f.isValid());

    ASSERT_EQ(a.Calc(), 0.5);
    ASSERT_EQ(b.Calc(), 1);
    ASSERT_EQ(c.Calc(), 123456.7);
    ASSERT_EQ(d.Calc(), 0);
    ASSERT_EQ(e.Calc(), -12345);
    ASSERT_EQ(f.Calc(), -1);
}

TEST (CalcTestSuite, WrongOperator) {
    const auto a = ArgParser("1 -- -2");
    const auto b = ArgParser("1 ** 2");
    const auto c = ArgParser("1 i 2");
    const auto d = ArgParser("1 2 2");
    const auto e = ArgParser("1 % 2");

    ASSERT_FALSE(a.isValid());
    ASSERT_FALSE(b.isValid());
    ASSERT_FALSE(c.isValid());
    ASSERT_FALSE(d.isValid());
    ASSERT_FALSE(e.isValid());
}

TEST (CalcTestSuite, WrongValues) {
    const auto a = ArgParser("1.2b + 2");
    const auto b = ArgParser("1 * ab");
    const auto c = ArgParser("1 / Kak zhit' etu zhizn'?..");
    const auto d = ArgParser("NEVER GONNA GIVE YOU UUUP + []");
    const auto e = ArgParser("12ab - 1b");

    ASSERT_FALSE(a.isValid());
    ASSERT_FALSE(b.isValid());
    ASSERT_FALSE(c.isValid());
    ASSERT_FALSE(d.isValid());
    ASSERT_FALSE(e.isValid());
}

TEST (CalcTestSuite, MergedWriting) {
    const auto a = ArgParser("1.2+ 2");
    const auto b = ArgParser("1*1");
    const auto c = ArgParser("1 /1");
    const auto d = ArgParser("13+ 2");
    const auto e = ArgParser("12-1");

    ASSERT_FALSE(a.isValid());
    ASSERT_FALSE(b.isValid());
    ASSERT_FALSE(c.isValid());
    ASSERT_FALSE(d.isValid());
    ASSERT_FALSE(e.isValid());
}
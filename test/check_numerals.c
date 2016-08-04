#include <stdlib.h>
#include <check.h>
#include "../src/numerals.h"

START_TEST(add_i_and_i_returns_ii) {
    char first[] = "i";
    char second[] = "i";
    char expected[] = "ii";
    char result[sizeof(expected)];
    add(first, second, result);
	ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(add_i_and_ii_returns_iii) {
    char first[] = "i";
    char second[] = "ii";
    char expected[] = "iii";
    char result[sizeof(expected)];
    add(first, second, result);
	ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(single_char_translates_to_numeric_value) {
    char numeral[] = "i";
    int expected = 1;
    ck_assert_int_eq(charToDigit(numeral), expected);

    strcpy(numeral, "v");
    expected = 5;
    ck_assert_int_eq(charToDigit(numeral), expected);

    strcpy(numeral, "x");
    expected = 10;
    ck_assert_int_eq(charToDigit(numeral), expected);

    strcpy(numeral, "l");
    expected = 50;
    ck_assert_int_eq(charToDigit(numeral), expected);

    strcpy(numeral, "c");
    expected = 100;
    ck_assert_int_eq(charToDigit(numeral), expected);

    strcpy(numeral, "d");
    expected = 500;
    ck_assert_int_eq(charToDigit(numeral), expected);

    strcpy(numeral, "m");
    expected = 1000;
    ck_assert_int_eq(charToDigit(numeral), expected);

}
END_TEST

START_TEST(numeral_ii_translates_to_value_2) {
    char ii[] = "ii";
    char *ptr = ii;
    int expected = 2;
    ck_assert_int_eq(numeralToNumericValue(ptr), expected);
}
END_TEST

Suite * numerals_suite(void) {
    Suite *s;
    TCase *tc_basic;

    s = suite_create("numerals");
    tc_basic = tcase_create("basic");
    tcase_add_test(tc_basic, add_i_and_i_returns_ii);
    tcase_add_test(tc_basic, add_i_and_ii_returns_iii);
    tcase_add_test(tc_basic, single_char_translates_to_numeric_value);
    tcase_add_test(tc_basic, numeral_ii_translates_to_value_2);
    suite_add_tcase(s, tc_basic);

    return s;
}

int main(void) {
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = numerals_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

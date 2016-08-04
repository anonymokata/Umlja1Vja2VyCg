#include <stdlib.h>
#include <check.h>
#include "../src/numerals.h"

START_TEST(test_add_i_and_i_returns_ii) {
    char first[] = "i";
    char second[] = "i";
    char expected[] = "ii";
    char result[sizeof(expected)];
    add(first, second, result);
	ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_add_i_and_ii_returns_iii) {
    char first[] = "i";
    char second[] = "ii";
    char expected[] = "iii";
    char result[sizeof(expected)];
    add(first, second, result);
	ck_assert_str_eq(result, expected);
}
END_TEST

Suite * numerals_suite(void) {
    Suite *s;
    TCase *tc_basic;

    s = suite_create("numerals");
    tc_basic = tcase_create("basic");
    tcase_add_test(tc_basic, test_add_i_and_i_returns_ii);
    tcase_add_test(tc_basic, test_add_i_and_ii_returns_iii);
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

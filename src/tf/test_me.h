#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_decimal.h"

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_mul(void);
Suite *suite_mod(void);
Suite *suite_div(void);

Suite *suite_is_less(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);

Suite *suite_from_int_to_decimal(void);
Suite *suite_from_decimal_to_float(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_float_to_decimal(void);

Suite *suite_truncate(void);
Suite *suite_truncate2(void);
Suite *suite_floor(void);
Suite *suite_round(void);
Suite *suite_round2(void);
Suite *suite_negate(void);
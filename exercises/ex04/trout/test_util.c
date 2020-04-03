#include "util.h"
#include "minunit.h"
#include <stdio.h>
#include <string.h>

 int tests_run = 0;

 static char * test_0() {
     mu_assert("error, code 0 should return 'network unreachable'", strcmp(icmpcode_v4(0), "network unreachable") == 0);
     return 0;
 }

 static char * test_1() {
     mu_assert("error, code 1 should return 'host unreachable'", strcmp(icmpcode_v4(1), "host unreachable") == 0);
     return 0;
 }

 static char * test_2() {
     mu_assert("error, code 2 should return 'protocol unreachable'", strcmp(icmpcode_v4(2), "protocol unreachable") == 0);
     return 0;
 }

 static char * test_3() {
     mu_assert("error, code 3 should return 'port unreachable'", strcmp(icmpcode_v4(3), "port unreachable") == 0);
     return 0;
 }

 static char * test_4() {
     mu_assert("error, code 4 should return 'fragmentation required but DF bit set'", strcmp(icmpcode_v4(4), "fragmentation required but DF bit set") == 0);
     return 0;
 }

 static char * test_5() {
     mu_assert("error, code 5 should return 'source route failed'", strcmp(icmpcode_v4(5), "source route failed") == 0);
     return 0;
 }

 static char * test_6() {
     mu_assert("error, code 6 should return 'destination network unknown'", strcmp(icmpcode_v4(6), "destination network unknown") == 0);
     return 0;
 }

 static char * test_7() {
     mu_assert("error, code 7 should return 'destination host unknown'", strcmp(icmpcode_v4(7), "destination host unknown") == 0);
     return 0;
 }

 static char * test_8() {
     mu_assert("error, code 8 should return 'source host isolated (obsolete)'", strcmp(icmpcode_v4(8), "source host isolated (obsolete)") == 0);
     return 0;
 }

 static char * test_9() {
     mu_assert("error, code 9 should return 'destination network administratively prohibited'", strcmp(icmpcode_v4(9), "destination network administratively prohibited") == 0);
     return 0;
 }

 static char * test_10() {
     mu_assert("error, code 10 should return 'destination host administratively prohibited'", strcmp(icmpcode_v4(10), "destination host administratively prohibited") == 0);
     return 0;
 }

 static char * test_11() {
     mu_assert("error, code 11 should return 'network unreachable for TOS'", strcmp(icmpcode_v4(11), "network unreachable for TOS") == 0);
     return 0;
 }

 static char * test_12() {
     mu_assert("error, code 12 should return 'host unreachable for TOS'", strcmp(icmpcode_v4(12), "host unreachable for TOS") == 0);
     return 0;
 }

 static char * test_13() {
     mu_assert("error, code 13 should return 'communication administratively prohibited by filtering'", strcmp(icmpcode_v4(13), "communication administratively prohibited by filtering") == 0);
     return 0;
 }

 static char * test_14() {
     mu_assert("error, code 14 should return 'host recedence violation'", strcmp(icmpcode_v4(14), "host recedence violation") == 0);
     return 0;
 }

 static char * test_15() {
     mu_assert("error, code 15 should return 'precedence cutoff in effect'", strcmp(icmpcode_v4(15), "precedence cutoff in effect") == 0);
     return 0;
 }

static char * test_unknown1() {
     mu_assert("error, code greater than 15 should return '[unknown code]'", strcmp(icmpcode_v4(16), "[unknown code]") == 0);
     return 0;
}

static char * test_unknown2() {
     mu_assert("error, code less than 0 should return '[unknown code]'", strcmp(icmpcode_v4(-1), "[unknown code]") == 0);
     return 0;

}
 static char * all_tests() {
     mu_run_test(test_0);
     mu_run_test(test_1);
     mu_run_test(test_2);
     mu_run_test(test_3);
     mu_run_test(test_4);
     mu_run_test(test_5);
     mu_run_test(test_6);
     mu_run_test(test_7);
     mu_run_test(test_8);
     mu_run_test(test_9);
     mu_run_test(test_10);
     mu_run_test(test_11);
     mu_run_test(test_12);
     mu_run_test(test_13);
     mu_run_test(test_14);
     mu_run_test(test_15);
     mu_run_test(test_unknown1);
     mu_run_test(test_unknown2);

     return 0;
 }

 int main(int argc, char **argv) {
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);

     return result != 0;
 }

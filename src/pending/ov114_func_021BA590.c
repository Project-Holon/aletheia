/*
 * function: func_021BA590
 * address:  0x021BA590
 * packet:   pkt_ov114_021BA590
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF  (parked; case-fold scheduling)
 *
 * Case-insensitive compare: fold both chars to lower case, mismatch -> -1,
 * either NUL or ' ' terminates as equal (return 0).
 *
 * BLOCKER (codegen): the original folds the *second* string first
 * (`c2 = *s2; if (c2>='A'&&c2<='Z') c2+=0x20;` with three `mov rX,#1`
 * predicates materialised before the loop), and reloads both pointers only
 * on the equality arm (the `if (c1 != c2) return -1;` uses the folded
 * values, not a re-read), whereas this front end requires the source to
 * re-read a pointer for the terminator test (`if (*s1 == 0 || *s1 == ' ')`)
 * and always emits a compact register-native loop (88 bytes vs 144).  Tried:
 * reading *s1 once into a local and testing the local, folding the second
 * string first and second, and using a helper; none reproduce the original's
 * materialised `mov r5,#1 / mov lr,#0` predicate pair or its 144-byte
 * footprint.  Left parked as a documented near miss.
 */

int func_021BA590(char *s1, char *s2)
{
    int c1;
    int c2;

    for (;;) {
        c2 = *s2;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 0x20;
        c1 = *s1;
        if (c1 >= 'A' && c1 <= 'Z') c1 += 0x20;
        if (c1 != c2) return -1;
        if (*s1 == 0 || *s1 == ' ') return 0;
        s1++;
        s2++;
    }
}
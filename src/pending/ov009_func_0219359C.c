/*
 * function: func_0219359C
 * address:  0x0219359C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 *
 * gpiReadKeyAndValue.  The behaviour and the control flow are recovered:
 * expect an opening '\\' at *index, copy the key up to the next '\\' (max
 * 511 bytes), NUL-terminate, copy the value up to the next '\\' or NUL (max
 * 511 bytes), NUL-terminate, then fold the consumed count into *index.  Each
 * of the four malformed cases inlines its own error tail (gpiSetError with
 * result 1 and string 0x021A57B8 "Parse Error.", then func_02189D78 with
 * callback type 3 and return 3) -- they are NOT a shared block in the
 * original, so a `goto error` spelling is wrong.
 *
 * BLOCKER (codegen, ~4 bytes): with the four error tails written out the
 * function compiles to 368 bytes against 372, but the register allocation
 * is cyclically shifted from the original:
 *   original  idx r6, p lr,  q r1, i r6, value ip, c r5, key r3
 *   compiled  idx r6, p r6, q lr, i ip, value r1, c r5, key r3
 * The whole diff is one register rotation (p/i/q/value) and the resulting
 * four-byte tail difference; no amount of operand reordering changed it in a
 * handful of attempts.  Useful as a witness for its 20 call sites once the
 * rotation is cracked.
 *
 * symbols:
 *   func_02193710  0x02193710  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   g_021A57B8     0x021A57B8  data
 */

extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern char g_021A57B8[];

int func_0219359C(int *connection, const char *buffer, int *index, char *key, char *value)
{
    int idx = *index;
    char *p = (char *)buffer + idx;
    char *q;
    int c = p[0];
    int i;
    int v;

    if (c != '\\') {
        func_02193710(connection, 1, (int)g_021A57B8);
        func_02189D78(connection, 3, 1);
        return 3;
    }
    c = p[1];
    q = p + 2;
    i = 0;
    if (c != '\\') {
        do {
            if (c == 0) {
                func_02193710(connection, 1, (int)g_021A57B8);
                func_02189D78(connection, 3, 1);
                return 3;
            }
            if (i == 0x1ff) {
                func_02193710(connection, 1, (int)g_021A57B8);
                func_02189D78(connection, 3, 1);
                return 3;
            }
            *key++ = c;
            c = *q++;
            i++;
        } while (c != '\\');
    }
    *key = 0;
    v = 0;
    for (;;) {
        c = *q++;
        if (c == '\\')
            break;
        if (c == 0)
            break;
        if (v == 0x1ff) {
            func_02193710(connection, 1, (int)g_021A57B8);
            func_02189D78(connection, 3, 1);
            return 3;
        }
        *value++ = c;
        v++;
    }
    *value = 0;
    *index += (int)(q - p) - 1;
    return 0;
}

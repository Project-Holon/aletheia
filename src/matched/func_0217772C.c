/*
 * function: func_0217772C
 * address:  0x0217772C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at the state object, then tail calls its initialiser.
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 *   func_02176B80  0x02176B80  arm  ov009
 */

extern char g_021AB180[];
extern void func_02176B80(char *p);

void func_0217772C(void)
{
    *(int *)g_021AB180 = 0;

    func_02176B80(g_021AB180);
}


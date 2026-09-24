/*
 * function: func_02156C60
 * address:  0x02156C60
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets the two slots and marks the flag at +0x7a6.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   func_02156BD8  0x02156BD8  thumb  ov009
 */

extern char *g_021A8264;
extern void func_02156BD8(int v);

void func_02156C60(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_02156BD8(i);
    }

    *(unsigned char *)(g_021A8264 + 0x7a6) = 1;
}


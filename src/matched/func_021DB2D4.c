/*
 * function: func_021DB2D4
 * address:  0x021DB2D4
 * packet:   pkt_021DB2D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021E2EF8  0x021E2EF8  data
 *
 * Compare the caller's first word with the current 0x0203D1A4 handle of the 0x020399A8 block; a match releases the 0x021E2EF8 pair through 0x02034714, a mismatch yields the +0x218 sub-block.
 */

typedef unsigned long u32;
extern int func_020399A8(void);
extern int func_0203D1A4(int);
extern void func_02034714(int, int, int);
extern u32 g_021E2EF8[];
int func_021DB2D4(int a, char *b)
{
    if (func_0203D1A4(func_020399A8()) == a) {
        func_02034714((int)g_021E2EF8, 0, (int)g_021E2EF8);
        return 0;
    }
    return (int)(b + 0x218);
}


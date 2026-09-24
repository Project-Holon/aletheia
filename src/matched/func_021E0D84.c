/*
 * function: func_021E0D84
 * address:  0x021E0D84
 * packet:   pkt_021E0D84
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C24B4  0x021C24B4  arm  ov114
 *   g_021E4370    0x021E4370  data
 *   g_021E4378    0x021E4378  data
 *
 * Hand the +0x40/+0x44 pair of the source block to 0x021C24B4 together with
 * the 0x021E4370 and 0x021E4378 tables.
 */

typedef unsigned long u32;

extern void func_021C24B4(char *, u32, int, int, u32, u32);
extern u32 g_021E4370[];
extern u32 g_021E4378[];

void func_021E0D84(char *a, char *b)
{
    func_021C24B4(a, (u32)g_021E4370, *(int *)(b + 0x40), *(int *)(b + 0x44),
                  (u32)g_021E4370, (u32)g_021E4378);
}


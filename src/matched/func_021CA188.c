/*
 * function: func_021CA188
 * address:  0x021CA188
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021CF248  0x021CF248  data
 *   g_021D3C20  0x021D3C20  data
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021CF7AC  0x021CF7AC  data
 *   func_021BF880  0x021BF880  arm  ov114
 *
 *
 * Cancels the armed resource and clears the 0x021CF7AC head word.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 g_021CF7AC[];
extern void func_021BF880(int);

void func_021CA188(void)
{
    int v = *(int *)(g_021CF7AC + 8);
    if (v >= 0)
        func_021BF880(v);
    *(u32 *)g_021CF7AC = 0;
}

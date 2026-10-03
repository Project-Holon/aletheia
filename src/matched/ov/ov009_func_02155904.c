/*
 * function: func_02155904
 * address:  0x02155904
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets 0xd through func_02155374 when the word at +0x754 is 0xc, else 0xb.
 *
 * symbols:
 *   func_02155374  0x02155374  thumb  ov009
 *   g_021A8264  0x021A8264  data

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_02155904(void)
{
    extern char *g_021A8264;
    void func_02155374(int v);
    if (*(u32 *)(g_021A8264 + 0x754) == 0xc) {
        func_02155374(0xd);
        return;
    }
    func_02155374(0xb);
}

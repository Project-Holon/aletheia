/*
 * function: func_020267FC
 * address:  0x020267FC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_0217778C  0x0217778C  thumb
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char *g_02146940;

extern u32 func_0203CD98(void);
extern void func_0217778C(void);

void func_020267FC(void)
{
    if (*(u8 *)(g_02146940 + 0x62) == 1) {
        if (func_0203CD98() == 1) {
            func_0217778C();
            *(u8 *)(g_02146940 + 0x62) = 0;
        }
    }
}

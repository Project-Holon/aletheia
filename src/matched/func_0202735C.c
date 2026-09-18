/*
 * function: func_0202735C
 * address:  0x0202735C
 * packet:   pkt_0202735C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char *g_02146940;
extern void  func_0202737C(void *p, u32 a1, u32 a2);

void func_0202735C(u32 a0, u32 a1)
{
    func_0202737C(g_02146940 + 4, a0, a1);
    *(u8 *)(g_02146940 + 0x62) = 1;
}

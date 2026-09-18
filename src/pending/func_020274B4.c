/*
 * function: func_020274B4
 * address:  0x020274B4
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02027460 label
 *
 * symbols:
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char *g_02146940;
extern void  func_02027460(void *p, u32 a0);

void func_020274B4(u32 a0)
{
    func_02027460(g_02146940 + 4, a0);
}

/*
 * function: func_02022518
 * address:  0x02022518
 * packet:   pkt_02022490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +004C ABS32 func_020225B4 -> no witness outside 02022518..02022568.
 *           The only branch reaching 0x020225B4 image-wide is this pool word; 0x020225B4
 *           itself is src/pending/func_020225B4.c, MATCH-capped on 0x02022490, so the
 *           'matched' class has nothing to offer. Every concrete byte is identical
 *           (0 concrete diffs, 4/4 relocations correct, 3 resolved).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_020225B4  0x020225B4  thumb
 *   g_020A73C8     0x020A73C8  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a0, u32 a1, u32 a2, void *a3, u32 a4);
extern void  func_020056A0(void *a0, void *a1, u32 a2);
extern void  func_020225B4(void);
extern char  g_020A73C8[];

void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 *p;

    p = (u32 *)func_02030734((u16)(((u16)a4 & 0x7FFF) | 0x8000), 0x10, 0,
                             g_020A73C8, 0x3E8);
    p[0] = a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    func_020056A0((void *)func_020225B4, p, 0x400);
}

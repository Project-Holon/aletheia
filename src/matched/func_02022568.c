/*
 * function: func_02022568
 * address:  0x02022568
 * packet:   pkt_02022490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020225D4  0x020225D4  thumb
 *   func_02030734  0x02030734  arm
 *   g_020A73C8     0x020A73C8  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void  *func_02030734(u32 heap, u32 size, u32 flags, void *file, u32 line);
extern void   func_020056A0(void *fn, void *p, u32 n);
extern void   func_020225D4(void);
extern char   g_020A73C8[];

void func_02022568(u32 a0, u32 a1, u32 a2)
{
    u32 *p = func_02030734((u16)(((u16)a2 & 0x7fff) | 0x8000), 8, 0, g_020A73C8, 0x401);

    p[0] = a0;
    p[1] = a1;
    func_020056A0((void *)func_020225D4, p, 8 << 7);
}

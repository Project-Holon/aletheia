/*
 * function: func_02025318
 * address:  0x02025318
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_020A7484     0x020A7484  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void *func_02030734(u32 heap, u32 size, u32 flags, void *file, u32 line);
extern char  g_020A7484[];

u8 *func_02025318(u32 a0, u8 a1, u8 a2)
{
    u8 *p = func_02030734(a0, 0x28, 1, g_020A7484, 0x51);
    int i, j;

    p[4] = a1;
    p[5] = a2;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 0x10; j++) {
            p[i * 0x10 + j + 6] = 0xff;
        }
    }
    return p;
}

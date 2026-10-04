/*
 * function: func_021FDAE4
 * address: 0x021FDAE4
 * packet: pkt_ov135_021FDAE4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02203D80 0x02203D80 data a4
 *   d_02203D46 0x02203D46 data a2
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 *   func_021FE9B0 0x021FE9B0 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 */
#include "../include/Obj00018.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, a, b; } Pos;
extern int (*const d_02203D80[])(void *);
extern const Pos d_02203D46[];
extern void func_021F4EA0(u32, int, int);
extern int func_021FE9B0(void *);
extern void func_021F4FF4(u32, u32, u32);
int func_021FDAE4(unsigned char *p)
{
    int result;
    int i;
    int x, y;
    result = d_02203D80[*(int *)(p + 0x28)](p);
    for (i = 0; i < 8; ++i)
        func_021F4EA0(*(u32 *)(p + i * 4 + 0xd0c), *(short *)(p + i * 4 + 0xec4), *(short *)(p + i * 4 + 0xec6) + ((struct Obj00018 *)p)->fD3C);
    x = func_021FE9B0(p);
    y = func_021FE9B0(p);
    func_021F4FF4(((struct Obj00018 *)p)->fBF4, d_02203D46[x].x, d_02203D46[y].y - ((struct Obj00018 *)p)->fD3C);
    func_021F4EA0(((struct Obj00018 *)p)->fD38, 55, ((struct Obj00018 *)p)->fD3C + 168);
    return result;
}

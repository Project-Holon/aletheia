/*
 * function: FIELD_MSGBG_InitCursor
 * address:  0x021927C0
 * packet:   pkt_ov021_021927C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_CreateFromBuffer  0x020436FC  arm  arm9
 *   func_02082BCC  0x02082BCC  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00126.h"
#include "../include/Obj19604.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u32 f08;
} Fx;

typedef struct G {
    u32 f00;
    u32 f04;
} G;

extern void func_02082BCC(void *p, int v, int n);
struct Bmp;
extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);

void FIELD_MSGBG_InitCursor(G *g, Fx *a)
{
    func_02082BCC(g, 0, 8);
    g->f04 = (u32)BMP_CreateFromBuffer((void *)(((struct Obj19604 *)(*(u8 * *)&((struct Obj00126 *)a)->f178))->f14), 1, 1, 0x20, a->f00);
}

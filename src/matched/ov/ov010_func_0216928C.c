/*
 * function: FIELD_G3D_MAP_Destroy
 * address:  0x0216928C
 * packet:   pkt_ov010_0216928C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAP_CloseArchive  0x021693A0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 */
#include "../include/Obj12384.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void FIELD_G3D_MAP_CloseArchive(int a0);
extern u32 func_020307B0(void *p);
extern void (*d_020A814C)(u32);
extern void (*d_020A8144)(u32);

#define F(o) (*(u32 *)((char *)p + (o)))

void FIELD_G3D_MAP_Destroy(void *p)
{
    FIELD_G3D_MAP_CloseArchive((int)p);
    if (F(0x20) != 0) {
        d_020A814C(F(0x90));
        d_020A8144(F(0x8c));
    }
    func_020307B0((void *)F(0x88));
    func_020307B0((void *)F(0x84));
    func_020307B0((void *)F(0xd4));
    if (((struct Obj12384 *)p)->fA4 != 0)
        func_020307B0((void *)F(0x9c));
    if (((struct Obj12384 *)p)->fA6 != 0)
        func_020307B0((void *)F(0xa0));
    func_020307B0((void *)((u32)p));
}

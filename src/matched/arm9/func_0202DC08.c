/*
 * function: PMS_DRAW_Delete
 * address:  0x0202DC08
 * packet:   pkt_0202DAA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*

 *
 * symbols:
 *   PMS_DRAW_ReleaseResources  0x0202DFD4  thumb
 *   PMS_DRAW_DeleteElem  0x0202E0C8  thumb
 */
#include "../include/Obj08809.h"

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj {
    u8  pad00[0xC];
    u8 *f0C;
    u8  pad10[0x20];
};

struct Obj0202DFD4;
struct Obj0202E0C8;
extern void PMS_DRAW_DeleteElem(struct Obj0202E0C8 *p);
extern void PMS_DRAW_ReleaseResources(struct Obj0202DFD4 *p);
extern u32 func_020307B0(void *p);

void PMS_DRAW_Delete(struct Obj *p)
{
    int i;

    for (i = 0; i < ((struct Obj08809 *)p)->f30; i++) {
        PMS_DRAW_DeleteElem((struct Obj0202E0C8 *)(p->f0C + i * 0x28));
    }

    func_020307B0(p->f0C);
    PMS_DRAW_ReleaseResources((struct Obj0202DFD4 *)((u8 *)p + 0x10));
    func_020307B0(p);
}

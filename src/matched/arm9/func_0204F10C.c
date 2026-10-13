/*
 * function: BILLBOARD_TrimImageResource
 * address:  0x0204F10C
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Hand the 0x28-stride entry's payload buffer to func_020307E0 with its
 * length.  The payload pointer is a named local, not an inline call argument,
 * or the entry pointer would have to stay live in a third callee-saved
 * register across both calls.  Same shape as src/matched/sub_02046FCC.c.
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   G3D_SYSTEM_GetResourceTex  0x02047250  arm
 *   func_020307E0  0x020307E0  arm
 */
#include "../include/Obj16122.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct Record {
    u8  pad00[0x14];
    u32 size;
};

struct Entry {
    void *payload;
    u8    pad04[0x28 - 4];
};

extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern struct Record *G3D_SYSTEM_GetResourceTex(void *p);
extern void func_020307E0(void *p, u32 size);

void BILLBOARD_TrimImageResource(void *table, u32 idx)
{
    struct Entry  *e       = &((struct Entry *)((struct Obj16122 *)table)->f4)[idx];
    void          *payload = e->payload;
    void          *buf     = G3D_SYSTEM_GetResourceFile(payload);
    struct Record *last    = G3D_SYSTEM_GetResourceTex(payload);

    func_020307E0(buf, (u32)((u8 *)last + last->size - (u8 *)buf));
}

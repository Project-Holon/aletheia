/*
 * function: func_021C660C
 * address: 0x021C660C
 * packet: pkt_ov136_021C660C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor input preserves load and stack-store scheduling.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 */
#include "../include/Obj03835.h"
#include "../include/Obj23594.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 x, y; u16 value; u8 flag, mode; } Descriptor;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
void *func_021C660C(u8 *p, const u8 *cfg)
{
    Descriptor d;
    d.x = ((struct Obj03835 *)cfg)->f0;
    d.y = ((struct Obj03835 *)cfg)->f2;
    d.value = ((struct Obj03835 *)cfg)->f6;
    d.flag = 0;
    d.mode = ((struct Obj03835 *)cfg)->f2C;
    return CLACT_CreateActor((void *)((struct Obj23594 *)p)->f1EC, *(u32 *)(p + 0x210 + ((struct Obj03835 *)cfg)->f14 * 4), *(u32 *)(p + 0x230 + ((struct Obj03835 *)cfg)->f18 * 4), *(u32 *)(p + 0x250 + ((struct Obj03835 *)cfg)->f1C * 4), &d, ((struct Obj03835 *)cfg)->f10, 102);
}

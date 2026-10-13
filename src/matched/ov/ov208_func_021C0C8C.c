/*
 * function: ov208_func_021C0C8C
 * address:  0x021C0C8C
 * packet:   pkt_ov208_021C0C8C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C0C14  0x021C0C14  thumb  ov208
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj10904.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u8   ov208_func_021C0C14(u16 *heap, u8 *p, int key);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *obj, u32 on);

void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on)
{
    if (on) {
        if (ov208_func_021C0C14(heap, p, key) != 0xff) {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj10904 *)p)->fD4), 6);
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj10904 *)p)->fD4, 1);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj10904 *)p)->fD4, 0);
    }
}

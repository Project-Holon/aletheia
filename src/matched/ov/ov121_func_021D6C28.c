/*
 * function: MYSTERY_DeleteClact
 * address: 0x021D6C28
 * packet: pkt_ov121_021D6C28
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj10404.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void MYSTERY_DeleteClact(u8 *p)
{
    int i;
    void *q;
    for(i=0;i<35;i++){
        q=*(void **)(p+i*4+12);
        if(q) CLACT_DeleteActor(q);
    }
    CLACT_ReleasePalette((u32)(((struct Obj10404 *)p)->f0));
    CLACT_ReleaseCharacter((u32)(((struct Obj10404 *)p)->f4));
    CLACT_ReleaseCellAnim((u32)(((struct Obj10404 *)p)->f8));
}

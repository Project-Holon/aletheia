/*
 * function: ZUKAN_Delete
 * address: 0x021C8F58
 * packet: pkt_ov212_021C8F58
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ZUKAN_FreeIdList 0x021C8F7C thumb ov212
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 */
#include "../include/Obj08416.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020314B8; struct S020315D4;
extern void ZUKAN_FreeIdList(u8 *);
extern void func_0203133C(struct S020314B8 *);
extern void func_020315D4(struct S020315D4 *);
extern void GFL_HEAP_DeleteChecked(u32 heap);
int ZUKAN_Delete(struct S020315D4 *obj, void *b, void *c, u8 *p) {
    ZUKAN_FreeIdList(p);
    func_0203133C(*(struct S020314B8 * *)&((struct Obj08416 *)p)->f4);
    func_020315D4(obj);
    GFL_HEAP_DeleteChecked(105);
    return 1;
}

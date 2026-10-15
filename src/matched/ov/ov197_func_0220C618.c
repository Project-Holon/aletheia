/*
 * function: B_BAG_MAIN_DisplaySelected
 * address: 0x0220C618
 * packet: pkt_ov197_0220C618
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * caller-width: BB98 takes full signed short promotion; no u16 truncation in this caller.
 * symbols:
 *   B_BAG_MAIN_GetSlotItem 0x0220BB98 thumb ov197
 *   B_BAG_MAIN_GetItemFlag 0x0220BBD8 thumb ov197
 *   B_BAG_MAIN_LoadItemGraphic 0x0220C180 thumb ov197
 *   B_BAG_MAIN_PlaceActor 0x0220C4D4 thumb ov197
 *   B_BAG_MAIN_DrawItemRow 0x0220C724 thumb ov197
 *   B_BAG_MAIN_StartFingerCursor 0x0220C6F8 thumb ov197
 *   d_0220DB80 0x0220DB80 data a4
 */
#include "../include/Obj01075.h"
#include "../include/Obj25042.h"
#include "../include/Obj25043.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Pair { short x, y; };
extern const struct Pair d_0220DB80[];
extern unsigned B_BAG_MAIN_GetSlotItem(const char *p, unsigned n);
typedef unsigned int   u32;
extern int B_BAG_MAIN_GetItemFlag(u32 key);
extern void B_BAG_MAIN_LoadItemGraphic(char *, unsigned, unsigned, unsigned);
extern void B_BAG_MAIN_PlaceActor(int, int);
extern void B_BAG_MAIN_DrawItemRow(char *, u16, u8, u8, const struct Pair *);
extern void B_BAG_MAIN_StartFingerCursor(u8 *, unsigned, unsigned);
void B_BAG_MAIN_DisplaySelected(char *p)
{
    unsigned item = B_BAG_MAIN_GetSlotItem(p, *(short *)(*(char * *)&((struct Obj01075 *)p)->f0 + ((struct Obj01075 *)p)->f533 * 2 + 0x30));
    B_BAG_MAIN_LoadItemGraphic(p, item, 6, 6);
    B_BAG_MAIN_PlaceActor(((struct Obj01075 *)p)->f43C, (int)&d_0220DB80[0]);
    if (((struct Obj25042 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
        B_BAG_MAIN_DrawItemRow(p, 7, B_BAG_MAIN_GetItemFlag(item), 0, &d_0220DB80[1]);
    if (((struct Obj25043 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 2) B_BAG_MAIN_StartFingerCursor((u8 *)p, 0x68, 0x98);
}

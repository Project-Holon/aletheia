/*
 * function: B_BAG_MAIN_DisplayList
 * address: 0x0220C574
 * packet: pkt_ov197_0220C574
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_GetSlotItem 0x0220BB98 thumb ov197
 *   B_BAG_MAIN_GetItemFlag 0x0220BBD8 thumb ov197
 *   B_BAG_MAIN_LoadItemGraphic 0x0220C180 thumb ov197
 *   B_BAG_MAIN_LoadItemPalette 0x0220C220 thumb ov197
 *   B_BAG_MAIN_PlaceActor 0x0220C4D4 thumb ov197
 *   B_BAG_MAIN_DrawItemRow 0x0220C724 thumb ov197
 *   B_BAG_MAIN_StartFingerCursor 0x0220C6F8 thumb ov197
 *   d_0220DB88 0x0220DB88 data a4
 */
#include "../include/Obj01075.h"
#include "../include/Obj25037.h"
#include "../include/Obj25038.h"
#include "../include/Obj25039.h"
#include "../include/Obj25040.h"
#include "../include/Obj25041.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Pair { short x, y; };
extern const struct Pair d_0220DB88[];
extern unsigned B_BAG_MAIN_GetSlotItem(const char *, unsigned);
typedef unsigned int   u32;
extern int B_BAG_MAIN_GetItemFlag(u32 key);
extern void B_BAG_MAIN_LoadItemGraphic(char *, unsigned, unsigned, unsigned);
extern void B_BAG_MAIN_LoadItemPalette(char *, unsigned, unsigned);
extern void B_BAG_MAIN_PlaceActor(int, int);
extern void B_BAG_MAIN_DrawItemRow(char *, u16, u8, u8, const struct Pair *);
extern void B_BAG_MAIN_StartFingerCursor(u8 *, unsigned, unsigned);
void B_BAG_MAIN_DisplayList(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned item = B_BAG_MAIN_GetSlotItem(p, i);
        if (item) {
            B_BAG_MAIN_LoadItemGraphic(p, item, i, i);
            B_BAG_MAIN_LoadItemPalette(p, item, i);
            B_BAG_MAIN_PlaceActor(*(int *)(p + i * 4 + 0x424), (int)&d_0220DB88[i]);
            if (((struct Obj25037 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
                B_BAG_MAIN_DrawItemRow(p, i * 8 + 7, B_BAG_MAIN_GetItemFlag(item), 0, &d_0220DB88[i + 6]);
        }
    }
    if (((struct Obj25038 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 1)
        B_BAG_MAIN_DrawItemRow(p, 55, ((struct Obj25039 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f14, ((struct Obj25040 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f15, &d_0220DB88[i + 6]);
    if (((struct Obj25041 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8 == 2) B_BAG_MAIN_StartFingerCursor((u8 *)p, 64, 16);
}

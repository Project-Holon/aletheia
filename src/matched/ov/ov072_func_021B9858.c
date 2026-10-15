/*
 * function: TOWNMAP_Destroy
 * address:  0x021B9858
 * packet:   pkt_ov072_021B9858
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   TOWNMAP_GRH_ClearTouch  0x021BB5E0  thumb  ov072
 *   TOWNMAP_ExitSelection  0x021BB204  thumb  ov072
 *   TOWNMAP_ClearScroll  0x021BAF9C  thumb  ov072
 *   TOWNMAP_MapFree  0x021BA570  thumb  ov072
 *   TOWNMAP_CursorClear  0x021BA0D8  thumb  ov072
 *   TOWNMAP_GRH_ExitLabel  0x021BB534  thumb  ov072
 *   TOWNMAP_GRH_ExitTextBox  0x021BB42C  thumb  ov072
 *   TOWNMAP_BackButtonFree  0x021B9F20  thumb  ov072
 *   TOWNMAP_ProcClear  0x021B9938  thumb  ov072
 *   TOWNMAP_GRH_FreeTownInfo  0x021BBB34  thumb  ov072
 *   TOWNMAP_GRH_Delete  0x021BB738  thumb  ov072
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov067_id       0x00000043  data
 */
#include "../include/Obj04342.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Node;
struct Rec;
struct S020315D4;
extern void func_02030EAC(struct Node *n);
extern void TOWNMAP_GRH_ClearTouch(void *a);
extern void TOWNMAP_ExitSelection(void **p);
extern void TOWNMAP_ClearScroll(void *a);
extern void TOWNMAP_MapFree(char *p);
extern void TOWNMAP_CursorClear(void *a);
extern void TOWNMAP_GRH_ExitLabel(void *a);
extern void TOWNMAP_GRH_ExitTextBox(void **p);
extern void TOWNMAP_BackButtonFree(unsigned *p);
extern void TOWNMAP_ProcClear(void *a);
extern void TOWNMAP_GRH_FreeTownInfo(void *a);
extern void TOWNMAP_GRH_Delete(u32 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void func_02034A5C(s32 handle);
extern char ov067_id[];

int TOWNMAP_Destroy(void *a, int b, int c, u8 *o)
{
    func_02030EAC(((struct Obj04342 *)o)->f13C);
    TOWNMAP_GRH_ClearTouch(o + 0xf4);
    TOWNMAP_ExitSelection((void **)(o + 0xb0));
    TOWNMAP_ClearScroll(o + 0x78);
    TOWNMAP_MapFree((char *)(o + 0x50));
    TOWNMAP_CursorClear(o + 0x38);
    TOWNMAP_GRH_ExitLabel(o + 0xd4);
    if (**(int * *)&((struct Obj04342 *)o)->f130 != 1) {
        TOWNMAP_GRH_ExitTextBox((void **)(o + 0xc4));
    }
    TOWNMAP_BackButtonFree((unsigned int *)(o + 0x14));
    TOWNMAP_ProcClear(o + 4);
    TOWNMAP_GRH_FreeTownInfo(((struct Obj04342 *)o)->f34);
    TOWNMAP_GRH_Delete(((struct Obj04342 *)o)->f0);
    MSGDATA_Delete(((struct Obj04342 *)o)->f12C);
    MSGDATA_Delete(((struct Obj04342 *)o)->f128);
    GF_FONT_Delete(((struct Obj04342 *)o)->f124);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x44);
    func_02034A5C((u32)ov067_id);
    return 1;
}

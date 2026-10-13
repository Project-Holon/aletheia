/*
 * function: func_021FB3DC
 * address:  0x021FB3DC
 * packet:   pkt_ov094_021FB3DC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0204047C  0x0204047C  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_021F8700  0x021F8700  thumb  ov094
 *   BTLV_BG_SetScroll  0x02209784  thumb  ov094
 */
#include "../include/Obj04398.h"
typedef unsigned short u16;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern void func_0204047C(int idx, unsigned short val);
extern u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
struct PalAnmSlot;
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 func_020407E8(u32 layer);
extern u32 func_02040804(u32 layer);
extern int func_021F86E0(void);
extern int func_021F8700(void);
extern void BTLV_BG_SetScroll(int a, int b, int c);

int func_021FB3DC(struct Cursor *a, char *b)
{
    int t;

    t = VM_GetU32(a);
    func_0204047C(3, 1);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x5f, (void *)(t + 1), (void *)3, 0, 0, 0, (((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000);
    func_0204989C(0x5f, t, 3, 0, 0, 0, (((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), (int)0x5f, (int)(t + 2), (u16)((((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000), (int)0, (int)0, (int)0x80, (int)0);
    ((struct Obj04398 *)b)->f264 = func_020407E8(3);
    ((struct Obj04398 *)b)->f268 = func_02040804(3);
    BTLV_BG_SetScroll(func_021F8700(), 0, 0);
    ((struct Obj04398 *)b)->f0 |= 0x10;
    return ((struct Obj04398 *)b)->f23C;
}

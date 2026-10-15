/*
 * function: POKELIST_InitWork
 * address:  0x021B660C
 * packet:   pkt_ov091_021B660C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x160 table is indexed as `p + i * 4 + 0x160` (base plus scaled
 * index, then the field offset) and the list lookup goes through a temp:
 * that is what puts the row address after POKEPARTY_GetMember and keeps the
 * three 0x160 offsets as spilled loop invariants.
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_020355C4  0x020355C4  arm
 *   FILE_UTIL_Get_12B0  0x020212B0  thumb
 *   POKELIST_SetupDisplay  0x021B6D90  thumb  ov091
 *   POKELIST_LoadGraphics  0x021B7298  thumb  ov091
 *   POKELIST_CreateFonts  0x021B71E4  thumb  ov091
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   PLIST_PLATE_Create  0x021BA6A0  thumb  ov091
 *   PLIST_PLATE_CreateEmpty  0x021BA81C  thumb  ov091
 *   PLIST_PLATE_GetLabelState  0x021BB43C  thumb  ov091
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   POKELIST_CreateClactUnit  0x021B709C  thumb  ov091
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   PLIST_MENU_InitTimer  0x021BCCCC  thumb  ov091
 *   func_020056A0  0x020056A0  thumb
 *   POKELIST_UpdateWindowMaskTask  0x021B6D64  thumb  ov091
 *   PLIST_MESSAGE_Create  0x021BB594  thumb  ov091
 *   PLIST_MENU_Create  0x021BBA8C  thumb  ov091
 *   POKELIST_StartMode  0x021B7698  thumb  ov091
 *   func_02041B6C  0x02041B6C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 */
#include "../include/Obj04352.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 POKEPARTY_GetCount(void *);
extern u8 func_020355C4(void);
extern u16 FILE_UTIL_Get_12B0(u16 id);
extern void POKELIST_SetupDisplay(u8 *p);
extern void POKELIST_LoadGraphics(u8 *p);
extern void POKELIST_CreateFonts(char *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u8 *PLIST_PLATE_Create(u8 *p, int k, void *mon);
extern int PLIST_PLATE_CreateEmpty(u8 *p, int k);
struct R;
extern int PLIST_PLATE_GetLabelState(int *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void POKELIST_CreateClactUnit(u8 *p);
extern int POKELIST_IsItemMode(u32 p);
extern void PLIST_MENU_InitTimer(int p);
extern int func_020056A0(void (*cb)(void *, u8 *), u8 *p, int pri);
extern void POKELIST_UpdateWindowMaskTask(void *tcb, u8 *p);
extern u32 *PLIST_MESSAGE_Create(u16 *h);
extern u32 *PLIST_MENU_Create(u16 *h);
extern void POKELIST_StartMode(u8 *p);
extern void func_02041B6C(u32 id);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

int POKELIST_InitWork(u8 *p)
{
    u8 n;
    u8 i;
    u8 *q;
    int e;

    n = POKEPARTY_GetCount((void *)*(int *)W(0x280));
    W(8) = func_020355C4();
    W(0x3c) = 0x17;
    p[0xc] = 0;
    p[0xe] = 0;
    W(0x2c) = 0;
    W(0x38) = 0;
    W(0x30) = 9;
    W(0x34) = 9;
    W(0x14) = 0;
    W(0x10) = 0;
    p[0x105] = 0;
    p[0x100] = 0;
    H(0x102) = 0;
    H(0x110) = 0;
    p[0x114] = 0;
    W(0x120) = 0;
    W(0x130) = 0;
    W(0x1e8) = 0;
    W(0x108) = 0;
    W(0x10c) = 0;
    W(0x118) = 0;
    W(0x264) = 0;
    W(0x250) = 0;
    W(0x278) = 0;
    *(u8 *)(W(0x280) + 0x63) = 0;
    W(0x28) = 1;
    W(0x24) = 0;
    for (i = 0; i < 0x17; i++)
        ((int *)(p + 0x178))[i] = -1;
    W(0x1c) = *(int *)(W(0x280) + 0x34) == 0x19 ? 1 : 0;
    q = (u8 *)W(0x280);
    if (((struct Obj04352 *)q)->f34 == 0x18) {
        ((struct Obj04352 *)q)->f34 = 3;
        W(0x18) = 1;
    } else {
        W(0x18) = 0;
    }
    q = (u8 *)W(0x280);
    if (((struct Obj04352 *)q)->f34 == 0x1a) {
        ((struct Obj04352 *)q)->f34 = 1;
        W(0x20) = 1;
    } else {
        W(0x20) = 0;
    }
    q = (u8 *)W(0x280);
    if (((struct Obj04352 *)q)->f34 == 6 && ((struct Obj04352 *)q)->f46 == 0)
        *(u16 *)(W(0x280) + 0x46) = FILE_UTIL_Get_12B0(((struct Obj04352 *)q)->f44);
    POKELIST_SetupDisplay(p);
    POKELIST_LoadGraphics(p);
    POKELIST_CreateFonts((char *)p);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            e = (int)POKEPARTY_GetMember(*(void **)W(0x280), i);
            *(int *)(p + i * 4 + 0x160) = (int)PLIST_PLATE_Create(p, i, (void *)e);
        } else
            *(int *)(p + i * 4 + 0x160) = PLIST_PLATE_CreateEmpty(p, i);
        if (PLIST_PLATE_GetLabelState((int *)(*(int *)(p + i * 4 + 0x160))) <= 5)
            p[0x105]++;
    }
    W(0x254) = (int)APP_TASKMENU_RES_Create(0, 1, W(0x138), W(0x140), H(0));
    POKELIST_CreateClactUnit(p);
    if (POKELIST_IsItemMode((u32)p) == 1)
        PLIST_MENU_InitTimer((int)p);
    W(4) = func_020056A0(POKELIST_UpdateWindowMaskTask, p, 8);
    W(0x150) = (int)PLIST_MESSAGE_Create((u16 *)p);
    W(0x154) = (int)PLIST_MENU_Create((u16 *)p);
    POKELIST_StartMode(p);
    func_02041B6C(3);
    func_02041B6C(2);
    func_02041B6C(7);
    GFL_NET_RestartWithDefaultTimeout(1, H(0));
    return 1;
}

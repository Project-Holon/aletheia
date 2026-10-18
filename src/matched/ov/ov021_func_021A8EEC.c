/*
 * function: FIELD_MENU_HandleKeys
 * address:  0x021A8EEC
 * packet:   pkt_ov021_021A8EEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   FIELD_MENU_StartLeave  0x021A90A4  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   FIELD_MENU_MoveCursor  0x021A8E80  thumb  ov021
 *   FIELD_MENU_GetSlotIndex  0x021A8E78  thumb  ov021
 *   UI_SetInputMode  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x34 - 0x30];
    Item items[7];
    int fF8;
    u8 padFC[0x124 - 0xFC];
    u32 f124;
} Obj;

extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern void FIELD_MENU_StartLeave(Obj *p, int k);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
struct W;
extern u32 FIELD_MENU_MoveCursor(struct W *w, u32 dir);
extern int FIELD_MENU_GetSlotIndex(u32 a, u32 b);
extern void UI_SetInputMode(u8 v);

void FIELD_MENU_HandleKeys(Obj *p)
{
    u32 trg;
    u32 rep;

    trg = KEY_GetTrg();
    rep = KEY_GetRepeat();
    if (p->f2C == 0 && (trg | rep) != 0) {
        if ((trg & 2) || (trg & 0x400)) {
            FIELD_MENU_StartLeave(p, 1);
            return;
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        p->f2C = 1;
        p->fF8 = 0;
        p->f24 = 1;
        CLACT_SetActorDrawEnable((struct Obj *)p->f124, 1);
        return;
    }
    if (rep & 0x40) {
        if (FIELD_MENU_MoveCursor((struct W *)p, 0) != 0) {
            p->f24 = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if (rep & 0x80) {
        if (FIELD_MENU_MoveCursor((struct W *)p, 1) != 0) {
            p->f24 = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if (rep & 0x20) {
        if (FIELD_MENU_MoveCursor((struct W *)p, 2) != 0) {
            p->f24 = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if (rep & 0x10) {
        if (FIELD_MENU_MoveCursor((struct W *)p, 3) != 0) {
            p->f24 = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if ((trg & 2) || (trg & 0x400)) {
        FIELD_MENU_StartLeave(p, 1);
    } else if (trg & 1) {
        if (p->items[FIELD_MENU_GetSlotIndex(p->f1E, p->f1F)].f08 != 7) {
            FIELD_MENU_StartLeave(p, 0);
            UI_SetInputMode(0);
        }
    }
}

/*
 * function: WORLDTRADE_BOX_UpdateKeyCursor
 * address:  0x021F5E44
 * packet:   pkt_021F5E44
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
 * symbols:
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   WORLDTRADE_BOX_GetColumnIndex  0x021F5F9C  thumb
 *   WORLDTRADE_BOX_LoadBoxIcons  0x021F68A4  thumb
 *   WORLDTRADE_BOX_MoveCursorToSlot  0x021F5F60  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   UI_SetInputMode  0x020355D8  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0xC4];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xD2C - 0xBF8];
    u32 arrows[2];
} Work;

extern const u8 tbl_02202DA4[][4];

extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void UI_SetInputMode(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WORLDTRADE_BOX_GetColumnIndex(int a, int b, int c);
extern void WORLDTRADE_BOX_LoadBoxIcons(Work *p, int box);
extern void WORLDTRADE_BOX_MoveCursorToSlot(u32 cursor, int i);

void WORLDTRADE_BOX_UpdateKeyCursor(Work *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        UI_SetInputMode(moved);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return;
    }
    if (KEY_GetTrg() & 0x40) {
        dir = 1;
    } else if (KEY_GetTrg() & 0x80) {
        dir = 2;
    } else if (KEY_GetTrg() & 0x20) {
        dir = 3;
    } else if (KEY_GetTrg() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                CLACT_SetActorAutoAnim((struct Obj *)p->arrows[k], 1);
                CLACT_SetActorAnimSeq((struct Obj *)p->arrows[k], k + 0x26);
                p->box = WORLDTRADE_BOX_GetColumnIndex(p->box, p->boxes, dir - 0x64);
                WORLDTRADE_BOX_LoadBoxIcons(p, p->box);
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        GFL_USE_PlaySeDefaultVolume(0x548);
    }
    WORLDTRADE_BOX_MoveCursorToSlot(p->cursor, p->slot);
}

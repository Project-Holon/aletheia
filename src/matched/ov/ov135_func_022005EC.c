/*
 * function: WORLDTRADE_TITLE_StateMainInput
 * address:  0x022005EC
 * packet:   pkt_022005EC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_TITLE_HitTestMenu  0x0220052C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   tbl_022038E0   0x022038E0  data  a2
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0xC0 - 0x2C];
    u16 sel;
    u8 padC2[0xBF4 - 0xC2];
    u32 cursor;
} Work;

extern const Pos tbl_022038E0[];

extern int WORLDTRADE_TITLE_HitTestMenu(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
struct Actor;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void CLACT_RestartActorAnim(struct Actor *a);

int WORLDTRADE_TITLE_StateMainInput(Work *p)
{
    int r;

    r = WORLDTRADE_TITLE_HitTestMenu();
    if (r != -1) {
        p->sel = r;
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 1);
        p->state = 0xE;
        UI_SetInputMode(1);
        if (p->sel == 2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return 2;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return 2;
    }
    if (KEY_GetTrg() & 2) {
        p->sel = 2;
        WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 1);
        p->state = 0xE;
        GFL_USE_PlaySeDefaultVolume(0x551);
    } else if (KEY_GetTrg() & 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 1);
        p->state = 0xE;
        GFL_USE_PlaySeDefaultVolume(0x54C);
    } else if (KEY_GetTrg() & 0x40) {
        if (p->sel != 0) {
            p->sel--;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            CLACT_RestartActorAnim((struct Actor *)p->cursor);
            WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    } else if (KEY_GetTrg() & 0x80) {
        if (p->sel < 2) {
            p->sel++;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            CLACT_RestartActorAnim((struct Actor *)p->cursor);
            WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    }
    return 2;
}

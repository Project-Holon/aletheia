/*
 * function: WORLDTRADE_SEARCH_StateMainInput
 * address:  0x021FE338
 * packet:   pkt_021FE338
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SEARCH_HitTestButtons  0x021FE254  thumb
 *   UI_SetInputMode  0x020355D8  arm
 *   WORLDTRADE_SEARCH_SelectButton  0x021FEAE0  thumb
 *   WORLDTRADE_SEARCH_GetSelectedButton  0x021FE9B0  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   WORLDTRADE_DEPOSIT_SetGenderFromEvent  0x021F7B9C  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   WORLDTRADE_SEARCH_CompareRecords  0x021FF4D0  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   WORLDTRADE_SEARCH_UpdateKeyCursor  0x021FE9DC  thumb
 *   tbl_02203D46   0x02203D46  data  a2
 *
 * Menu input handler. A touch on an entry (WORLDTRADE_SEARCH_HitTestButtons) selects it and
 * acts at once; otherwise the d-pad moves the cursor (WORLDTRADE_SEARCH_UpdateKeyCursor) and A
 * acts on the current entry, B jumps to the last entry of page 1. Entry 1
 * hands the +0xB56 record to WORLDTRADE_DEPOSIT_SetGenderFromEvent, entry 5 compares the two
 * records, entry 4 depends on the +0xD0 word; every path picks the next
 * state (+0x28) and a sound. Always returns 2.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
    u16 anim2;
} CurPos;

typedef struct {
    s16 a;
    s8 b;
    s8 c;
    s8 d;
    s8 pad;
} Rec;

typedef struct {
    u8 pad0[0x20];
    u32 f20;
    int page;
    int row0;
    int row1;
} State;

typedef struct {
    u8 pad0[0x28];
    int next;
    u8 pad2C[0xD0 - 0x2C];
    u32 fD0;
    u8 padD4[0xB56 - 0xD4];
    Rec rec[2];
    u16 padB62;
    u32 fB64;
    u8 padB68[0xBF4 - 0xB68];
    u32 cursor;
    u8 padBF8[0xE00 - 0xBF8];
    State *st;
    u8 padE04[0xF84 - 0xE04];
    u32 fF84;
} Work;

extern const CurPos tbl_02203D46[];

extern int WORLDTRADE_SEARCH_HitTestButtons(void);
extern void UI_SetInputMode(u8 v);
extern void WORLDTRADE_SEARCH_SelectButton(Work *p, int i);
extern int WORLDTRADE_SEARCH_GetSelectedButton(Work *p);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 heap);
struct Obj;
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern int WORLDTRADE_DEPOSIT_SetGenderFromEvent(u8 *p, int event);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern int WORLDTRADE_SEARCH_CompareRecords(Rec *x, Rec *y, u32 m, u32 n);
extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void WORLDTRADE_SEARCH_UpdateKeyCursor(Work *p);

int WORLDTRADE_SEARCH_StateMainInput(Work *p)
{
    int sel = WORLDTRADE_SEARCH_HitTestButtons();

    if (sel != -1) {
        UI_SetInputMode(1);
        WORLDTRADE_SEARCH_SelectButton(p, sel);
        sel = WORLDTRADE_SEARCH_GetSelectedButton(p);
        switch (sel) {
        case 1:
            if (p->rec[0].a != 0) {
                u32 h = (u32)POKE_PERSONAL_Create((u16)p->rec[0].a, 0, 0x48);
                u32 v = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
                POKE_PERSONAL_Delete((void *)h);
                p->st->f20 = v;
                if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)(&p->rec[0]), p->st->f20) != 0) {
                    CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    GFL_USE_PlaySeDefaultVolume(0x557);
                    return 2;
                }
            }
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            GFL_USE_PlaySeDefaultVolume(0x54C);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->next = 0x23;
            break;
        case 5:
            if (p->rec[0].a == 0 || WORLDTRADE_SEARCH_CompareRecords(&p->rec[0], &p->rec[1], p->fF84, p->fB64) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x557);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->next = 0x23;
            break;
        case 4:
            if (p->fD0 != 0) {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                GFL_USE_PlaySeDefaultVolume(0x54C);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->next = 0x23;
            } else {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                GFL_USE_PlaySeDefaultVolume(0x557);
                p->next = 0x25;
            }
            break;
        default:
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            if (sel == 6) {
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->next = 0x23;
            break;
        }
    } else if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return 2;
    } else {
        WORLDTRADE_SEARCH_UpdateKeyCursor(p);
        if (KEY_GetTrg() & 1) {
            sel = WORLDTRADE_SEARCH_GetSelectedButton(p);
            switch (sel) {
            case 1:
                if (p->rec[0].a != 0) {
                    u32 h = (u32)POKE_PERSONAL_Create((u16)p->rec[0].a, 0, 0x48);
                    u32 v = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
                    POKE_PERSONAL_Delete((void *)h);
                    p->st->f20 = v;
                    if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)(&p->rec[0]), p->st->f20) != 0) {
                        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                        GFL_USE_PlaySeDefaultVolume(0x557);
                        return 2;
                    }
                }
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                GFL_USE_PlaySeDefaultVolume(0x54C);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->next = 0x23;
                break;
            case 5:
                if (p->rec[0].a == 0 || WORLDTRADE_SEARCH_CompareRecords(&p->rec[0], &p->rec[1], p->fF84, p->fB64) != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x557);
                } else {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                }
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->next = 0x23;
                break;
            case 4:
                if (p->fD0 != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    p->next = 0x23;
                } else {
                    CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    GFL_USE_PlaySeDefaultVolume(0x557);
                    p->next = 0x25;
                }
                break;
            default:
                if (sel == 6) {
                    GFL_USE_PlaySeDefaultVolume(0x551);
                } else {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                }
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->next = 0x23;
                break;
            }
        } else if (KEY_GetTrg() & 2) {
            p->st->page = 1;
            p->st->row1 = 2;
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->next = 0x24;
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
    }
    return 2;
}

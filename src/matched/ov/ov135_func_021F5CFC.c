/*
 * function: WORLDTRADE_BOX_StateMainInput
 * address:  0x021F5CFC
 * packet:   pkt_021F5CFC
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
  *
 * symbols:
 *   WORLDTRADE_BOX_CheckArrowTouch  0x021F5CA4  thumb
 *   WORLDTRADE_BOX_GetColumnIndex  0x021F5F9C  thumb
 *   WORLDTRADE_BOX_LoadBoxIcons  0x021F68A4  thumb
 *   WORLDTRADE_BOX_MoveCursorToSlot  0x021F5F60  thumb
 *   WORLDTRADE_BOX_SelectMonForOffer  0x021F5A7C  thumb
 *   WORLDTRADE_BOX_SelectMonForRequest  0x021F5B8C  thumb
 *   WORLDTRADE_BOX_UpdateKeyCursor  0x021F5E44  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    int mode;
    u8 pad24[0x28 - 0x24];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xBFC - 0xBF8];
    u32 marker;
    u8 padC00[0xD2C - 0xC00];
    u32 arrows[2];
} Work;

extern int WORLDTRADE_BOX_CheckArrowTouch(Work *p);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
struct Actor;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WORLDTRADE_BOX_GetColumnIndex(int a, int b, int c);
extern void WORLDTRADE_BOX_LoadBoxIcons(Work *p, int box);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void WORLDTRADE_BOX_MoveCursorToSlot(u32 cursor, int i);
extern void WORLDTRADE_BOX_SelectMonForOffer(Work *p);
extern void WORLDTRADE_BOX_SelectMonForRequest(Work *p);
extern void WORLDTRADE_BOX_UpdateKeyCursor(Work *p);
extern u32 KEY_GetTrg(void);

int WORLDTRADE_BOX_StateMainInput(Work *p)
{
    int r = WORLDTRADE_BOX_CheckArrowTouch(p);

    if (r != -1) {
        switch (r) {
        case 0x1F:
            CLACT_SetActorAutoAnim((struct Obj *)p->arrows[0], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[0], 0x26);
            p->box = WORLDTRADE_BOX_GetColumnIndex(p->box, p->boxes, 1);
            WORLDTRADE_BOX_LoadBoxIcons(p, p->box);
            GFL_USE_PlaySeDefaultVolume(0x548);
            break;
        case 0x20:
            CLACT_SetActorAutoAnim((struct Obj *)p->arrows[1], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[1], 0x27);
            p->box = WORLDTRADE_BOX_GetColumnIndex(p->box, p->boxes, -1);
            WORLDTRADE_BOX_LoadBoxIcons(p, p->box);
            GFL_USE_PlaySeDefaultVolume(0x548);
            break;
        case 0x1E:
            CLACT_SetActorDrawEnable((struct Obj *)p->marker, 1);
            CLACT_RestartActorAnim((struct Actor *)p->marker);
            p->state = 0x11;
            p->slot = r;
            GFL_USE_PlaySeDefaultVolume(0x551);
            WORLDTRADE_BOX_MoveCursorToSlot(p->cursor, p->slot);
            break;
        default:
            p->slot = r;
            WORLDTRADE_BOX_MoveCursorToSlot(p->cursor, p->slot);
            if (p->mode == 5) {
                WORLDTRADE_BOX_SelectMonForOffer(p);
            } else if (p->mode == 6) {
                WORLDTRADE_BOX_SelectMonForRequest(p);
            }
            break;
        }
    } else {
        WORLDTRADE_BOX_UpdateKeyCursor(p);
        if (p->mode == 5) {
            if (KEY_GetTrg() & 2) {
                CLACT_SetActorDrawEnable((struct Obj *)p->marker, 1);
                CLACT_RestartActorAnim((struct Actor *)p->marker);
                p->state = 0x11;
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else if (KEY_GetTrg() & 1) {
                WORLDTRADE_BOX_SelectMonForOffer(p);
            }
        } else if (p->mode == 6) {
            if (KEY_GetTrg() & 2) {
                CLACT_SetActorDrawEnable((struct Obj *)p->marker, 1);
                CLACT_RestartActorAnim((struct Actor *)p->marker);
                p->state = 0x11;
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else if (KEY_GetTrg() & 1) {
                WORLDTRADE_BOX_SelectMonForRequest(p);
            }
        }
    }
    return 2;
}

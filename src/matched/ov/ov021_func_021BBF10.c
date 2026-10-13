/*
 * function: FLDEFF_FOOTMARK_UpdateTask
 * address:  0x021BBF10
 * packet:   pkt_ov021_021BBF10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Witnesses: arm9 leaves BILLBOARD_ACT_GetBoard, BILLBOARD_ACT_GetEntryFlags, BILLBOARD_ACT_SetEntryEnabled,
 * BILLBOARD_ACT_GetEntryElemId, BILLBOARD_GetElemCell filed in src/matched/arm9 (wave A1).
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_GetEntryElemId  0x020508C4  arm
 *   BILLBOARD_SetElemAlpha  0x0204F6B4  arm
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;

typedef struct Head {
    int h0;
    int h4;
} Head;

typedef struct Obj {
    Head *head;
    int pad4;
    u16 h8;
    u16 hA;
    u16 padC;
    s16 h0e;
    int i10;
} Obj;

extern void FIELD_EFFECT_DeleteObject(int a);
typedef unsigned int   u32;
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern int BILLBOARD_ACT_GetEntryElemId(int a, int b);
extern void BILLBOARD_SetElemAlpha(u8 *a0, int i, u8 *px);

void FLDEFF_FOOTMARK_UpdateTask(int a0, Obj *p)
{
    u8 c;
    int r4, r6;
    u16 t;

    switch (p->hA) {
    case 0:
        p->i10 = p->i10 + 1;
        if (p->i10 >= 0x10) {
            p->hA = p->hA + 1;
        }
        break;
    case 1:
        p->h0e = p->h0e - 2;
        if (p->h0e < 0) {
            FIELD_EFFECT_DeleteObject(a0);
            return;
        }
        c = p->h0e;
        r4 = p->head->h4;
        r6 = BILLBOARD_ACT_GetBoard((u32 *)r4);
        t = BILLBOARD_ACT_GetEntryElemId(r4, p->h8);
        BILLBOARD_SetElemAlpha((u8 *)r6, t, &c);
        break;
    }
}

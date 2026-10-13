/*
 * unit:     yes
 * address:  0x0200B67C
 * packet:   pkt_0200B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_SaveSeq, BATTLE_REC_Save
 *
 * 264 bytes, 0x0200B67C..0x0200B784, 2 functions, both labelled.  Every
 * concrete byte reproduces.
 *
 * What held it open, and what closed it.  Two call targets have exactly one
 * caller in the whole image and that caller is here:
 *
 *   0x02007324  reached only from 0x0200B6A6, inside BATTLE_REC_SaveSeq
 *   0x0200B7D8  reached only from 0x0200B71A, inside BATTLE_REC_Save
 *
 * Shrinking the range to one function keeps the call that needs the witness in
 * it, which is the limit `docs/MATCHING.md` states for the cut remedy, so no
 * image class could carry either site.  Both are now `matched`:
 * 0x02007324 is src/matched/unit_02007324.c and 0x0200B7D8 is
 * src/matched/unit_0200B7D8.c, two EXACT entries proved byte for byte against
 * the original over ranges this file does not touch.  Pulling either function
 * across the boundary into this range is no longer needed, and would have been
 * wrong anyway: the two belong to different original files.
 *
 * alias: inside "battle_rec.c"; the two steps of the record-save state machine
 * that BATTLE_REC_LoadToWork and BATTLE_REC_CheckSaved read back.
 *
 * Three things cost time here.
 *
 *  - GAME_DATA_GetSaveControl is declared with **one** parameter, not four.  The call
 *    leaves r1 through r3 holding this function's own second, third and fourth
 *    arguments, which reads like a four-argument call and is not one: declaring
 *    four parameters keeps `b` live from the entry and the whole of
 *    BATTLE_REC_Save's case 0 is then allocated the other way round, with the two
 *    sub-record pointers sharing registers with `b` instead of with `a`.  Seven
 *    bytes, and none of them in the arithmetic.  src/matched/unit_0200C9EC.c
 *    declares the same extern with one parameter.
 *  - inside case 0 the two sub-record pointers have to be assigned
 *    `q = &p->unk80;` first and `r = &p->unkC4;` second.  The second assignment
 *    is the last use of `p`, so it takes over `p`'s register and the first one
 *    gets the copy; writing them the other way round swaps which of the two is
 *    the `adds rD, rP, #0` and is five bytes.
 *  - the state word is read with `switch (*state)` over the constants 0 and 1,
 *    which is the `cmp #0` / `beq` / `cmp #1` / `beq` / `b` chain the original
 *    has; an `if` / `else if` inverts the first test.
 *
 * symbols:
 *   func_0203F1FC  0x0203F1FC  arm
 *   pBattleRec  0x0214616C  data
 *   BATTLE_REC_MakeHeader  0x0200B7D8  thumb
 *   BATTLE_REC_Encode  0x0200B908  thumb
 *   BATTLE_REC_SetBodyCrc  0x0200BA44  thumb
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0203F1FC(const u8 *src, u32 len);

struct QRec {
    u16 unk00[0x0C];
    u8  unk18[0x0C];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u8  unk2A;
    u8  unk2B;
    u8  unk2C[0x0C];
    u8  unk38[8];
    u16 unk40;
    u16 unk42;
};

struct RecC4 {
    u8  unk0000[0x17D8];
    u16 unk17D8;
    u16 unk17DA;
    u16 unk17DC;
    u16 unk17DE;
};

struct BattleRec {
    u8  unk00[0x80];
    struct QRec unk80;
    struct RecC4 unkC4;
};

extern struct BattleRec *pBattleRec;

struct Big;
struct Sub02007324Ctrl;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void func_02007324(struct Sub02007324Ctrl *ctrl, u32 id, u32 heap, u32 a, u32 b);
extern void  GAME_DATA_PartSaveStart(u8 *a, u32 c);
extern int GAME_DATA_PartSaveMain(char *p, int a1);
extern void func_0200734C(struct Sub02007324Ctrl *ctrl, u32 id);
extern void  BATTLE_REC_SetBodyCrc(struct RecC4 *p);
extern void  BATTLE_REC_Encode(void *a, u32 b, u32 c);
extern void  BATTLE_REC_MakeHeader(void *h, struct QRec *q, const struct RecC4 *src,
                           u32 mode, u32 e);

u32 BATTLE_REC_SaveSeq(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e)
{
    void *h = GAME_DATA_GetSaveControl(a);
    u32 r;

    switch (*state) {
    case 0:
        func_02007324(h, c, e, (u32)pBattleRec, 0x2000);
        GAME_DATA_PartSaveStart(a, c);
        (*state)++;
        break;
    case 1:
        r = GAME_DATA_PartSaveMain(a, c);
        if (r == 2 || r == 3) {
            func_0200734C(h, c);
            return r;
        }
        break;
    }
    return 0;
}

u32 BATTLE_REC_Save(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub)
{
    void *h;
    struct BattleRec *p;
    struct QRec *q;
    struct RecC4 *r;
    u16 v;

    h = GAME_DATA_GetSaveControl(a);

    switch (*state) {
    case 0:
        p = pBattleRec;
        if (p == 0) {
            return 3;
        }
        q = &p->unk80;
        r = &p->unkC4;
        BATTLE_REC_MakeHeader(h, q, r, c, d);
        q->unk28 = 0xE281;
        q->unk40 = func_0203F1FC((const u8 *)q, 0x38);
        r->unk17D8 = 0xE281;
        BATTLE_REC_SetBodyCrc(r);
        v = r->unk17DC;
        BATTLE_REC_Encode(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
        *sub = 0;
        (*state)++;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(a, pBattleRec, e, sub, b);
    }
    return 0;
}

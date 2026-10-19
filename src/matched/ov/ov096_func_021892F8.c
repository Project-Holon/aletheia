/*
 * unit: yes
 * function: TR_AI_CompareKnowsMoveEffectSequence,TR_AI_CmdNop2,TR_AI_CmdSetNoMoveFlag,TR_AI_CmdNop3,TR_AI_CmdNop4
 * address: 0x021892F8
 * packet: pkt_ov096_021892F8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extent contains four followers at 021893AC, 021893B4, 021893CC, 021893D4.
 * Followers have 6,22,6,6 code bytes with 2 zero alignment bytes each.
 * Lever: bind each comparison's call result before comparing, per existing cmp idiom.
 * Caller-visible return overrides the tail-forwarder's void declaration.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_GetPosition 0x0218A160 thumb ov096
 *   TR_AI_GetMoveParam 0x0218A378 thumb ov096
 *   TR_AI_Compare 0x0218A0F4 thumb ov096
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x4c]; u16 values[8]; u8 pad2[0xb0-0x5c]; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; } Obj;
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern int TR_AI_GetMoveParam(Obj *, int, int);
struct QG;
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
int TR_AI_CompareKnowsMoveEffectSequence(struct Cursor *a, Obj *b, int c)
{
    int k, z, y, r, i, t;
    unsigned int value;
    k = VM_GetU32(a);
    value = VM_GetU32(a);
    z = VM_GetU32(a);
    y = TR_AI_GetPosition((u8 *)b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
            t = TR_AI_GetMoveParam(b, (int)BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i), 28);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] != 0) {
                t = TR_AI_GetMoveParam(b, b->values[y * 4 + i], 28);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    }
    return TR_AI_Compare((u8 *)a, c, r, 1, z);
}
int TR_AI_CmdNop2(int a, Obj *b) { return b->fc4; }
int TR_AI_CmdSetNoMoveFlag(int a, Obj *b) {
    ((u8 *)b)[0x44] |= 2;
    return b->fc4;
}
int TR_AI_CmdNop3(int a, Obj *b) { return b->fc4; }
int TR_AI_CmdNop4(int a, Obj *b) { return b->fc4; }

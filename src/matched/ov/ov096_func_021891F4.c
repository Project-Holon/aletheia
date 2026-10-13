/*
 * function: TR_AI_CompareKnowsMove
 * address: 0x021891F4
 * packet: pkt_ov096_021891F4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: u16 value/result locals plus result binding give the original cmp operand order.
 * Caller-visible return/second arguments override tail-forwarder declarations.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_GetPosition 0x0218A160 thumb ov096
 *   TR_AI_GetPoke 0x0218A2FC thumb ov096
 *   TR_AI_Compare 0x0218A0F4 thumb ov096
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
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
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
struct QG;
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
int TR_AI_CompareKnowsMove(struct Cursor *a, Obj *b, int c)
{
    u16 value, t;
    int k, z, r, i;
    u8 *s;
    int y;
    k = VM_GetU32(a);
    value = VM_GetU32(a);
    z = VM_GetU32(a);
    y = TR_AI_GetPosition((u8 *)b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)b->fbc); i++) {
            t = BTL_POKEPARAM_GetMoveId(b->fbc, (u8)i);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 3:
        s = TR_AI_GetPoke((u8 *)b, TR_AI_GetPosition((u8 *)b, 3));
        if (BTL_POKEPARAM_IsFainted(s) == 0) {
            for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)s); i++) {
                t = BTL_POKEPARAM_GetMoveId(s, (u8)i);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] == value) {
                r = 1;
                break;
            }
        }
        break;
    }
    return TR_AI_Compare((u8 *)a, c, r, 1, z);
}

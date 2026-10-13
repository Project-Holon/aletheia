/*
 * function: BTL_CLIENT_SetStruggleIfNoMoves
 * address:  0x021CF524
 * packet:   pkt_ov093_021CF524
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_CLIENT_IsMoveSelectionBlocked  0x021CF5B0  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   BTL_CLIENT_SetStruggleAction  0x021CF58C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
struct UtilWork;
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int BTL_CLIENT_IsMoveSelectionBlocked(u8 *g, void *m, u32 move, void *out);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
struct Unk021D82D0;
extern void BTL_CLIENT_SetStruggleAction(struct Unk021D82D0 *out, u8 *p, void *q);

u32 BTL_CLIENT_SetStruggleIfNoMoves(u32 x, void *q, u32 y)
{
    u32 n = BTL_POKEPARAM_GetMoveCount(q);
    u32 c = 0;
    u32 i = 0;
    for (; i < n; i++) {
        if (BTL_CLIENT_IsMoveSelectionBlocked((u8 *)x, q, (u32)BTL_POKEPARAM_GetMoveId(q, (u8)i), 0) == 0) {
            if ((u32)BTL_POKEPARAM_GetMovePPChecked(q, (u8)i) != 0) {
                c++;
            }
        }
    }
    if (c == 0) {
        BTL_CLIENT_SetStruggleAction((struct Unk021D82D0 *)y, (u8 *)x, q);
        return 1;
    }
    return 0;
}

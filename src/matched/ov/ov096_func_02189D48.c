/*
 * function: func_02189D48
 * address: 0x02189D48
 * packet: pkt_ov096_02189D48
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * 2026-10-05 (wD5 lane16): EXACT*. BTL_SERVER_FLOW_CalcPredictedMoveDamage takes u8 position arguments (a, b), and x, y, z are
 *   u8 locals (BTL_POKEPARAM_GetPokeId returns u8). That moves the `adds r1,rX` before the y reload at both calls.
 *   The ov093 callee also compiles EXACT with `u8 a, u8 b` (scratch test only, file not changed).
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   BTL_SLOT_FindPoke 0x021B9C98 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTL_SERVER_FLOW_CalcPredictedMoveDamage 0x021C7E14 thumb ov093
 *   func_0218A308 0x0218A308 thumb ov096
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern u8 *BTL_SIDE_GetSlotOfClientThunk(u8 *, int);
struct QG;
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
extern int BTL_SLOT_FindPoke(u8 *p, u32 v);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern u16 BTL_SERVER_FLOW_CalcPredictedMoveDamage(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
extern u8 *func_0218A308(void *p, u32 i);
u32 func_02189D48(struct Cursor *a, u8 *p)
{
    int t, k;
    u8 x, z;
    u8 *g;
    int j, sel;
    u8 y;
    u32 best;
    int n;
    t = VM_GetU32(a);
    k = BTL_MAIN_GetSlotClientIdThunk((char *)(*(u8 **)(p + 0xB0)), p[0x94]);
    g = BTL_SIDE_GetSlotOfClientThunk(*(u8 **)(p + 0xB8), k);
    n = BTL_MAIN_GetPositionsPerClientThunk(*(u8 **)(p + 0xB0), k);
    sel = BTL_SLOT_FindPoke(g, (u32)(*(u8 **)(p + 0xBC)));
    x = BTL_POKEPARAM_GetPokeId(*(u8 **)(p + 0xBC));
    y = BTL_POKEPARAM_GetPokeId(*(u8 **)(p + 0xC0));
    best = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    if (sel < 0 || best == 0) {
        *(u32 *)(p + 0x38) = 0;
        return *(u32 *)(p + 0xC4);
    }
    for (j = 0; j < n; j++) {
        u8 *m = func_0218A308(g, (u8)j);
        z = BTL_POKEPARAM_GetPokeId(m);
        if (BTL_POKEPARAM_IsAbleToBattle(m) != 0 && j != sel) {
            int i;
            *(u32 *)(p + 0x38) = 2;
            for (i = 0; i < (int)BTL_POKEPARAM_GetMoveCount((struct QG *)m); i++) {
                u16 c = BTL_POKEPARAM_GetMoveId(m, (u8)i);
                if (i != p[1]) {
                    u32 r = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(p + 0xB4), z, y, c, 1, t);
                    if (r > best) {
                        *(u32 *)(p + 0x38) = 1;
                        break;
                    }
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}

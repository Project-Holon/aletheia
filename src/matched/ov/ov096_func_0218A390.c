/*
 * function: func_0218A390
 * address: 0x0218A390
 * packet: pkt_ov096_0218A390
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes, size 98 vs 100). Image order in the loop call: str r7,[sp,#4]; ldr r0,[sp,#8]; ldr r1,[sp,#0x10]; adds r0,#0xb4; ldr r0,[r0]; ldr r2. Ours loads a first, then the field, then x. Also tried const-qualified first parameter (callee and function) and a split pointer/xx copy; the compiler folds them back.
 * note: 2026-10-04 Residue: store order only. Original stores the stack arg d ([sp,#4]) before reloading spilled a ([sp,#8]) for the first call argument; ours loads a first. Tried: struct field, ptr casts, local hoist, u32/int d, u16 callee return, while loop, temp for the 54C0 result.
 * note: 2026-10-05 (wD4 lane20): tried the first argument and the 54C0 result as separate locals before the call (c = f(b,i); q = *(a+0xB4); g(q,x,y,c,1,d)) and a u32 first parameter; same 10 bytes (ldr r0,[sp,#8] still ahead of str r7,[sp,#4]).
 * 2026-10-05 (wD5 lane20): no new variant closed it. Reading: original emits the stack argument store (str r7,[sp,#4]) before the spilled-a reload and the field address chain; ours starts the chain first. Same 10 bytes as before; the sibling func_02188D5C shows the same tie-break in its loop call, so a common cause (IR order of stack-argument stores versus argument 0) is likely.
 * 2026-10-05 (wD6 lane15): EXACT*. BTL_SERVER_FLOW_CalcPredictedMoveDamage takes u8 a, u8 b (as in matched func_02189D48)
 *   and x, y are u8 locals; that fixes the stack-argument store order in the loop call.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_SERVER_FLOW_CalcPredictedMoveDamage 0x021C7E14 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
struct QG;
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u16 BTL_SERVER_FLOW_CalcPredictedMoveDamage(u8 *, u8, u8, u32, int, int);
u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d)
{
    u32 best = 0;
    u8 x = BTL_POKEPARAM_GetPokeId(b);
    u8 y = BTL_POKEPARAM_GetPokeId(c);
    int i;
    for (i = 0; i < (int)BTL_POKEPARAM_GetMoveCount((struct QG *)b); i++) {
        u32 r = BTL_SERVER_FLOW_CalcPredictedMoveDamage(*(u8 **)(a + 0xB4), x, y, (u32)BTL_POKEPARAM_GetMoveId(b, (u8)i), 1, d);
        if (r > best)
            best = r;
    }
    return best;
}

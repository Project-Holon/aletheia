/*
 * function: func_02188D5C
 * address: 0x02188D5C
 * packet: pkt_ov096_02188D5C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (4 bytes). Loop call func_021C7E14 schedules 'adds r0,r5' before 'str r6,[sp,#4]'; the image stores t first, as the first call does. Also tried r declared before c; no change. Same family as func_02189D48 (stack-argument store versus argument-0 address order).
 * note: 2026-10-04 Residue: second call of func_021C7E14 in the loop schedules 'adds r0,r5' before 'str r6,[sp,#4]'; original stores t first (as in the first call). Rest is identical. Tried: and/continue forms, u32/u16 c, int/u32 t and best, static inline helper for either call, fused nested call.
 * note: 2026-10-05 (wD4 lane20): tried an int copy of t used only by the loop call (t2 = t); same 4 bytes ('adds r0,r5' before 'str r6,[sp,#4]' in the loop call). Residue unchanged.
 * 2026-10-05 (wD5 lane20): 4 bytes, the same store-versus-chain order in the loop call only (the call before the loop gets the original order). Not closed; the only difference between the two calls is that the loop call has c in r3 from a prior call and sits under the i != p[1] test. No new variant tried beyond the earlier notes.
 * 2026-10-05 (wD6 lane15): EXACT*. func_021C7E14 takes u8 a, u8 b (as in matched func_02189D48)
 *   and x, y are u8 locals; that fixes the stack-argument store order in the loop call.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021C7E14 0x021C7E14 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern u8 func_021D5440(u8 *);
struct QG;
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
u32 func_02188D5C(struct Cursor *a, u8 *p)
{
    int t = func_0201134C(a);
    u8 x = func_021D5440(*(u8 **)(p + 0xBC));
    u8 y = func_021D5440(*(u8 **)(p + 0xC0));
    u32 best = func_021C7E14(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    int i;
    if (best == 0) {
        *(u32 *)(p + 0x38) = 0;
    } else {
        *(u32 *)(p + 0x38) = 2;
        for (i = 0; i < func_021D5448((struct QG *)(*(u8 **)(p + 0xBC))); i++) {
            u16 c = func_021D54C0(*(u8 **)(p + 0xBC), (u8)i);
            if (i != p[1]) {
                u32 r = func_021C7E14(*(u8 **)(p + 0xB4), x, y, c, 1, t);
                if (r > best) {
                    *(u32 *)(p + 0x38) = 1;
                    break;
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}

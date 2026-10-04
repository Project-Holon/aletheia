/*
 * function: func_02188D5C
 * address: 0x02188D5C
 * packet: pkt_ov096_02188D5C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-04 Residue: second call of func_021C7E14 in the loop schedules 'adds r0,r5' before 'str r6,[sp,#4]'; original stores t first (as in the first call). Rest is identical. Tried: and/continue forms, u32/u16 c, int/u32 t and best, static inline helper for either call, fused nested call.
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
extern int func_0201134C(int);
extern u8 func_021D5440(u8 *);
extern u8 func_021D5448(u8 *);
extern u16 func_021D54C0(u8 *, u8);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);
u32 func_02188D5C(int a, u8 *p)
{
    int t = func_0201134C(a);
    int x = func_021D5440(*(u8 **)(p + 0xBC));
    int y = func_021D5440(*(u8 **)(p + 0xC0));
    u32 best = func_021C7E14(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    int i;
    if (best == 0) {
        *(u32 *)(p + 0x38) = 0;
    } else {
        *(u32 *)(p + 0x38) = 2;
        for (i = 0; i < func_021D5448(*(u8 **)(p + 0xBC)); i++) {
            u16 c = func_021D54C0(*(u8 **)(p + 0xBC), i);
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

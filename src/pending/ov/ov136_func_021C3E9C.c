/*
 * function: func_021C3E9C
 * address:  0x021C3E9C
 * packet:   pkt_ov136_021C3E9C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note:     2026-10-02 12 bytes differ: case 1 branch layout (orig beq to the state=2 block, then cmp 0xFFFF, bne, b next) and case 2 loads ctx[4] into r1 not r0; tried goto, ternary, nested else, ||, u16 local
 *
 * symbols:
 *   ov110_id 0x0000006E data a1
 *   func_021C3E9C 0x021C3E9C thumb
 *   func_021C3FC8 0x021C3FC8 thumb
 *   func_021C414C 0x021C414C thumb
 *   func_02031330 0x02031330 arm
 *   func_02031348 0x02031348 arm
 *   func_02008C58 0x02008C58 thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0202411C 0x0202411C thumb
 *   func_02024134 0x02024134 thumb
 *   func_02024124 0x02024124 thumb
 *   func_020240FC 0x020240FC thumb
 *   d_021C7750 0x021C7750 data a1
 *   d_021C775C 0x021C775C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 ov110_id[];
extern const u32 d_021C7750[];
extern const u32 d_021C775C[];
extern int func_02031330(u32 h);
extern void func_02031348(u32 h, int a, const void *t, u32 c);
extern void func_021C3FC8(void *ctx, void *a);
extern void func_021C414C(u32 v);
extern void *func_02008C58(u32 v);
extern void func_02008DF0(void *v, u32 id);
extern void func_02034AC4(u32 v);
extern void func_02034A5C(u32 v);
extern int func_0202411C(u32 v);
extern void func_02024134(u32 a, void *b);
extern u32 func_02024124(u32 a);
extern void func_020240FC(u32 a);
int func_021C3E9C(void *a, u32 *state, u16 *arg, u32 *ctx)
{
    u32 r;
    int s;
    int st;
    st = func_02031330(ctx[7]);
    switch (*state) {
    case 0:
        *(u16 *)ctx[4] = arg[0];
        func_02031348(ctx[7], -1, d_021C7750, ctx[4]);
        *state = 1;
        break;
    case 1:
        if (st != 1) {
            r = *(u16 *)ctx[4];
            if (r == 4) *state = 2;
            else if (r == 0xFFFF) *state = 2;
            else *state = 3;
        }
        break;
    case 2:
        if (arg[0] == 1) {
            if (*(u16 *)ctx[4] == 4) {
                func_021C414C(((u32 *)arg)[5]);
                func_02008DF0(func_02008C58(((u32 *)arg)[4]), 0x1d);
                s = 1;
            } else s = 0;
            ((u32 *)arg)[1] = s;
        }
        return 1;
    case 3:
        func_02034AC4((u32)ov110_id);
        func_021C3FC8(ctx, arg);
        func_02031348(ctx[7], -1, d_021C775C, ctx[2]);
        *state = 4;
        break;
    case 4:
        if (st != 1) {
            if (func_0202411C(ctx[2]) == 0) {
                u32 k = ((u8 *)ctx[4])[2];
                if (k < 3) func_02024134(ctx[2], (u8 *)ctx[4] + 0x16 + k * 8);
                else *(u16 *)((u8 *)ctx[4] + 0x32) = func_02024124(ctx[2]);
            }
            func_020240FC(ctx[2]);
            func_02034A5C((u32)ov110_id);
            *state = 0;
        }
        break;
    }
    return 0;
}

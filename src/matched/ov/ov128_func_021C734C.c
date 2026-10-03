/*
 * function: func_021C734C
 * address: 0x021C734C
 * packet: pkt_ov128_021C734C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202EB04 0x0202EB04 thumb
 *   func_021CA154 0x021CA154 thumb ov128
 *   func_021CA184 0x021CA184 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
struct CodeIn;
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern void func_0202EB04(struct CodeIn *p);
extern void func_021CA154(u8 *, int);
extern void func_021CA184(u8 *, int, int);
int func_021C734C(u32 *p, int *q, u8 *ctx)
{
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021CA154(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 3;
        return 1;
    }
    if (func_020362DC() & 1024) {
        func_020061E4(0x556);
        func_021CA154(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 4;
        return 1;
    }
    if (*q == 1) {
        if (func_020362DC() & 0xcf3) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p, *p);
            func_020355D8(0);
            *q = 0;
        }
        return 0;
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54c);
        func_0202EB04(*(void **)(ctx + 0x184));
        return 1;
    }
    if (func_0203633C() & 64) {
        if (*p != 0) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p - 1, *p);
            --*p;
            return 0;
        }
    } else if (func_0203633C() & 128) {
        if (*p < 2) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p + 1, *p);
            ++*p;
            return 0;
        }
    }
    return 0;
}

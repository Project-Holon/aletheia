/*
 * function: func_021C6BF8
 * address:  0x021C6BF8
 * packet:   pkt_ov093_021C6BF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave P13 B10): the older DIFF (12 B, p and h/r in each other's
 *   r4/r5) closed with #pragma opt_lifetimes off around the function, see
 *   docs/idioms/a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md.
 *   Source is unchanged from the old draft. Plain literals already (11952, 0x2c).
 *   Callees: func_021D5F14 returns u8, func_021D7930 takes u8 (both matched);
 *   sub_0201BD28 and sub_0201C284 return u32 (matched arm9 units).
 * symbols:
 *   sub_0201BD28  0x0201BD28  thumb
 *   sub_0201C284  0x0201C284  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   func_021D7930  0x021D7930  thumb  ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021D75A8(int key, u32 val);
extern u8 func_021D5F14(u8 *p);
extern int func_021D7930(u8 v);
extern int func_021B911C(int a, int b);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 sub_0201C284(u16 id);

#pragma opt_lifetimes off
int func_021C6BF8(u8 *p, u8 *a, u8 *b, u16 q)
{
    int r, n;
    u16 h;
    h = sub_0201BD28(q, 7);
    h = h + func_021D5F14(a);
    func_021D74F8(11952);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x2c, h);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x36);
    if (func_021D775C(0x41) == 0) {
        if (sub_0201C284(q)) {
            r = 1;
        } else {
            n = func_021D775C(0x2c);
            if (n > 4) n = 4;
            r = func_021D7930((u16)n);
        }
        if (func_021B911C(*(int *)(p + 4), 3)) r = 1;
    }
    func_021D7540(11975);
    return r;
}

#pragma opt_lifetimes reset

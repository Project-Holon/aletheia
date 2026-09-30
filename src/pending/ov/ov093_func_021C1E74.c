/*
 * function: func_021C1E74
 * address: 0x021C1E74
 * packet: pkt_ov093_021C1E74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: 0x0201C1E8, unlabelled ARM9 tail-call wrapper owned by Ilias.
 *   Call +0x10 has no witness outside 021C1E74..021C2048; all concrete
 *   bytes match, and the other 39 relocation sites resolve.
 *   Verified one --thumb, no --region, dsi/1.1p1 -O4,p: EXACT, 12 bytes.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 *   symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 func_0201C1E8(u16 id) { return sub_0201BD28(id, 2); }
 * lever: a separately narrowed u8 level local avoids the extra r0-to-r2
 *   copy from narrowing an inline call argument. value * scale selects
 *   the original multiplication destination; scale * value adds a copy.
 * symbols:
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021C728C 0x021C728C thumb ov093
 *   func_021C7374 0x021C7374 thumb ov093
 *   func_021C7474 0x021C7474 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D7A44 0x021D7A44 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021D7C38 0x021D7C38 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021C75EC 0x021C75EC thumb ov093
 *   func_021D7A6C 0x021D7A6C thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201C1E8(u16);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *);
extern void func_021D75EC(int, u32);
extern void func_021D75A8(int, u32);
extern void func_021D7674(int, u32, u32, u32);
extern void func_021D70F0(u8 *, int);
extern u32 func_021D775C(int);
extern void func_021D7540(int);
extern u16 func_021C728C(u8 *, u8 *, u8 *, u8 *);
extern u32 func_021C7374(u8 *, u8 *, u8 *, u8 *, u32);
extern u32 func_021C7474(u8 *, u8 *, u8 *, u8 *, u32);
extern int func_021D59B4(u8 *, int);
extern int func_021D7A44(int, int, u8, int);
extern u32 func_021D7B10(u32, u32);
extern int func_021C2AB0(u8 *);
extern u32 func_021D7C38(int, u32);
extern int func_021B911C(void *, int);
extern u32 func_021D78AC(u32);
extern int func_021C75EC(u8 *, u8 *, int);
extern u32 func_021D7A6C(u32, u32);
extern int func_021D62A8(u8 *);
int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out)
{
    int category = func_0201C1E8(*(u16 *)c);
    int flag = 0;
    u32 result;
    u32 x;
    u32 y;
    u32 value;
    u32 factor;
    u16 scale;
    u8 level;
    func_021D74F8(0x1c21);
    func_021D75EC(0x38, d);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x45, f);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x1a, category);
    func_021D75A8(0x37, 0);
    func_021D70F0(p, 0x46);
    result = func_021D775C(0x37);
    if (result) {
        flag = 1;
    } else {
        x = func_021C728C(p, a, b, c);
        y = func_021C7374(p, a, b, c, f);
        value = func_021C7474(p, a, b, c, f);
        level = func_021D59B4(a, 15);
        value = func_021D7A44(x, y, level, value);
        if (e != 0x1000) value = func_021D7B10(value, e);
        factor = func_021D7C38(func_021C2AB0(p), c[6]);
        if (factor != 0x1000) value = func_021D7B10(value, factor);
        if (f) value *= 2;
        if (!func_021B911C(*(void **)(p + 4), 7)) {
            if (g) scale = 85;
            else scale = 100 - func_021D78AC(16);
            value = (u32)(value * scale) / 100u;
        }
        if (c[6] != 17) value = func_021D7B10(value, func_021C75EC(p, a, c[6]));
        value = func_021D7A6C(value, d);
        if (category == 1 && func_021D62A8(a) == 4 && func_021D59B4(a, 17) != 62) {
            value = (u32)(50u * value) / 100u;
        }
        if (!value) value = 1;
        func_021D7674(0x35, 0x1000, 0x29, 0x20000);
        func_021D75A8(0x32, value);
        func_021D70F0(p, 0x47);
        factor = func_021D775C(0x35);
        result = func_021D7B10(func_021D775C(0x32), factor);
    }
    func_021D70F0(p, 0x48);
    func_021D7540(0x1c8d);
    *out = result;
    return flag;
}

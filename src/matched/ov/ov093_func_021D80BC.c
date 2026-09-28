/*
 * function: func_021D80BC
 * address:  0x021D80BC
 * packet:   pkt_ov093_021D80BC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   sub_0201BD28   0x0201BD28  thumb
 *   sub_0201BEB8   0x0201BEB8  thumb
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_021B8C50  0x021B8C50  thumb  ov093
 *   func_021B8D38  0x021B8D38  thumb  ov093
 *   func_021B8778  0x021B8778  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021B8588(void *p);
extern int func_021D5440(int m);
extern int func_021B8D8C(void *p, int a, u32 b);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 sub_0201BEB8(u16 id, u32 bit);
extern int func_021D80A8(int m);
extern u8 func_021B8C50(void *p, u32 v, int k);
extern u8 func_021B8D38(void *p, int a, int k, u8 *out);
extern u8 func_021B8778(void *p, int k, u8 *out);
extern u32 func_021D78AC(u32 range);

int func_021D80BC(void *p, int a, int m, u16 move)
{
    u32 mode;
    int t;
    u32 kind;
    u8 b;
    u8 buf[8];
    u8 n;

    mode = func_021B8588(p);
    t = func_021B8D8C(p, a, func_021D5440(m));
    kind = sub_0201BD28(move, 0x1B);
    if (move == 0xAE) kind = func_021D80A8(m);

    if (mode == 0) {
        switch (kind) {
        case 0:
        case 3:
        case 4:
        case 5:
        case 9:
            return func_021B8C50(p, t, 0);
        case 1:
        case 7:
            return t;
        case 13:
        default:
            return 6;
        }
    }

    b = 0;
    if (mode == 2) b = sub_0201BEB8(move, 0xB);

    switch (kind) {
    case 0:
    case 3:
    case 9:
        if (b) t = (u16)(t | (6 << 8));
        else t = (u16)(t | (1 << 8));
        break;
    case 1:
        t = (u16)(t | (3 << 8));
        break;
    case 2:
        if (b) t = (u16)(t | (7 << 8));
        else t = (u16)(t | (4 << 8));
        break;
    case 7:
        return t;
    default:
        return 6;
    }

    n = func_021B8D38(p, a, t, buf);
    if (n) {
        n = func_021D78AC(n);
        return func_021B8D8C(p, a, buf[n]);
    }
    n = func_021B8778(p, t, buf);
    if (n) return buf[(u8)func_021D78AC(n)];
    return 6;
}

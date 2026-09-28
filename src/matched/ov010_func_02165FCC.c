/*
 * function: func_02165FCC
 * address:  0x02165FCC
 * packet:   pkt_ov010_02165FCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Print a record into a text window: its name into slot 0, then the
 * type-specific value (number, string or item) into slots 1 and 2.
 *
 * symbols:
 *   func_0201F31C  0x0201F31C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F104  0x0201F104  thumb
 *   func_0201F134  0x0201F134  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0201F1E0  0x0201F1E0  thumb
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165D8C  0x02165D8C  thumb  ov010
 *   func_02165E24  0x02165E24  thumb  ov010
 *   func_02165E34  0x02165E34  thumb  ov010
 *   func_02165E78  0x02165E78  thumb  ov010
 *   func_02165E8C  0x02165E8C  thumb  ov010
 *   func_02165E9C  0x02165E9C  thumb  ov010
 *   func_02165EAC  0x02165EAC  thumb  ov010
 *   func_02165ECC  0x02165ECC  thumb  ov010
 *   func_02165F30  0x02165F30  thumb  ov010
 *   func_02165F64  0x02165F64  thumb  ov010
 *   func_02165F74  0x02165F74  thumb  ov010
 *   func_02165F84  0x02165F84  thumb  ov010
 *   func_02165F94  0x02165F94  thumb  ov010
 *   func_02165FA4  0x02165FA4  thumb  ov010
 *   func_02165FB4  0x02165FB4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Rec Rec;

extern void func_0201F31C(void *win);
extern void *func_020457B0(u32 len, u32 heap);
extern void func_02045808(void *str);
extern void func_0201EE0C(void *win, u32 slot, void *str, u32 a, u32 b, u32 c);
extern void func_0201EE60(void *win, u32 slot, u32 v);
extern void func_0201EF34(void *win, u32 slot, u32 v);
extern void func_0201EF40(void *win, u32 slot, u32 v);
extern void func_0201EF4C(void *win, u32 slot, u32 v);
extern void func_0201EFA4(void *win, u32 slot, u32 v, u32 digits, u32 a, u32 b);
extern void func_0201F104(void *win, u32 slot, u32 v);
extern void func_0201F134(void *win, u32 slot, u32 v);
extern void func_0201F184(void *win, u32 slot, u32 v);
extern void func_0201F1E0(void *win, u32 slot, u32 v);
extern void func_02165C34(Rec *r, void *str);
extern u8 func_02165D08(Rec *r);
extern void func_02165D8C(Rec *r, void *str);
extern u16 func_02165E24(Rec *r);
extern u16 func_02165E34(Rec *r);
extern u16 func_02165E78(Rec *r);
extern u16 func_02165E8C(Rec *r);
extern u16 func_02165E9C(Rec *r);
extern u16 func_02165EAC(Rec *r);
extern void func_02165ECC(Rec *r, void *str);
extern u16 func_02165F30(Rec *r);
extern u32 func_02165F64(Rec *r);
extern u16 func_02165F74(Rec *r);
extern u32 func_02165F84(Rec *r);
extern u8 func_02165F94(Rec *r);
extern u16 func_02165FA4(Rec *r);
extern u8 func_02165FB4(u16 type);

void func_02165FCC(Rec *r, void *win, u32 heap)
{
    void *str;
    u8 kind;
    u32 v;

    func_0201F31C(win);
    str = func_020457B0(0x21, heap);
    if (str == 0)
        return;
    func_02165C34(r, str);
    func_0201EE0C(win, 0, str, 0, 1, 2);
    kind = func_02165FB4(func_02165E24(r));
    switch (kind) {
    case 1:
        v = func_02165F30(r);
        func_0201F104(win, 1, v);
        func_0201F134(win, 2, v);
        break;
    case 2:
    case 4:
        func_0201EE60(win, 1, func_02165E34(r));
        if (kind == 2)
            break;
    case 3:
        func_02165ECC(r, str);
        func_0201EE0C(win, 2, str, 0, 1, 2);
        break;
    case 5:
        func_0201EF4C(win, 1, func_02165E78(r));
        break;
    case 6:
        func_0201EFA4(win, 1, func_02165F74(r), 3, 0, 1);
        break;
    case 7:
        func_0201EFA4(win, 1, func_02165F64(r), 3, 0, 1);
        break;
    case 8:
        func_0201EE60(win, 1, func_02165E9C(r));
        break;
    case 9:
        func_0201EF40(win, 1, func_02165EAC(r));
        break;
    case 10:
        func_0201EF34(win, 1, func_02165E8C(r));
        break;
    case 11:
        func_0201EFA4(win, 1, func_02165F84(r), 1, 0, 1);
        break;
    case 12:
        func_0201F1E0(win, 1, func_02165F94(r));
        break;
    case 13:
        func_0201F184(win, 1, func_02165FA4(r));
        break;
    case 14:
        func_02165D8C(r, str);
        func_0201EE0C(win, 1, str, func_02165D08(r), 1, 2);
        break;
    case 15:
        break;
    }
    func_02045808(str);
}

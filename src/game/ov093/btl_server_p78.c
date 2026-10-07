/*
 * file:     btl_server_p78.c
 * unit:     yes
 * function: func_021C6720, func_021C676C
 * address:  0x021C6720
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C6828  0x021C6828  thumb  ov093
 *   func_021C6838  0x021C6838  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u32 func_021C6828(u8 *d);
extern u8 *func_021C6838(u8 *d, u32 i);
int func_021C6720(u8 *p, u8 *a, u32 c);
int func_021C676C(u8 *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32);


int func_021C6720(u8 *p, u8 *a, u32 c)
{
    int r;
    func_021D74F8(11622);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x94);
    r = func_021D775C(0x51);
    func_021D7540(11628);
    return r;
}


int func_021C676C(u8 *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32)
{
    u32 n;
    u32 i;
    int t;
    n = func_021C6828(d);
    func_021D74F8(11648);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            func_021D75EC(i + 6, func_021D5440(func_021C6838(d, i)));
        }
    } else {
        func_021D75EC(6, 0x1F);
    }
    func_021D7630(0x41, 0);
    func_021D7630(0x51, 0);
    func_021D7630(0x4F, 0);
    func_021D70F0(p, 0x95);
    if (func_021D775C(0x51) != 0) {
        *out8 = func_021D775C(6);
    } else {
        *out8 = 0x1F;
    }
    *out32 = func_021D775C(0x4F);
    t = func_021D775C(0x41);
    func_021D7540(11677);
    return t == 0;
}

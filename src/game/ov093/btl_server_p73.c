/*
 * file:     btl_server_p73.c
 * unit:     yes
 * function: func_021C6668, func_021C66AC
 * address:  0x021C6668
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
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C6710  0x021C6710  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u8 *func_021C6710(u32 a, int b);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
int func_021C6668(u8 *p, u8 *a, u8 *a2, u16 a3);
int func_021C66AC(u8 *p, u8 *a, u32 c);


int func_021C6668(u8 *p, u8 *a, u8 *a2, u16 a3)
{
    int r;
    func_021D74F8(11574);
    func_021D75A8(3, func_021D5440(a));
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x2E);
    r = func_021D775C(0x51);
    func_021D7540(11579);
    return r;
}


int func_021C66AC(u8 *p, u8 *a, u32 c)
{
    u8 *q;
    int r;
    q = func_021C6710(c, 0);
    func_021D74F8(11599);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, q ? func_021D5440(q) : 0x1F);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x93);
    r = func_021D775C(0x41);
    func_021D7540(11605);
    return r;
}

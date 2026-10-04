/*
 * function: func_021C7374
 * address: 0x021C7374
 * packet: pkt_ov093_021C7374
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: 0x0201C1E8, unlabelled ARM9 tail-call wrapper owned by Ilias;
 *   no witness outside this caller (7374-r2.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 *   symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 func_0201C1E8(u16 id) { return sub_0201BD28(id, 2); }
 * lever: bind the category call result before initialising k to prevent
 *   its constant assignment moving before the call.
 * symbols:
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021D5AD8 0x021D5AD8 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201C1E8(int a);
extern void func_021D74F8(int);
extern void func_021D7540(int);
extern u8 func_021D5440(u8 *);
extern void func_021D75EC(int, u32);
extern void func_021D75A8(int, u32);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D58A8(u8 *, int);
extern int func_021D5AD8(u8 *, int);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D7674(int, u32, u32, u32);
extern u32 func_021D7B10(u32 a, u32 b);

u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag)
{
    int k;
    u16 value;
    u8 index;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 10;
    if (mode != 2) k = 8;
    func_021D74F8(12542);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75A8(0x3b, 0x1f);
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x39);
    index = func_021D775C(0x3b);
    if (index != 0x1f) a = (u8 *)func_021B9934(*(char **)(p + 8), index);
    if (func_021D775C(0x51)) value = func_021D58A8(a, k);
    else if (flag) value = func_021D5AD8(a, k);
    else value = func_021D59B4(a, k);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, *(u32 *)(c + 8));
    func_021D75A8(0x33, value);
    func_021D7674(0x35, 1 << 12, 410, 1 << 17);
    func_021D70F0(p, 0x3b);
    value = func_021D775C(0x33);
    value = func_021D7B10(value, func_021D775C(0x35));
    func_021D7540(12579);
    return value;
}

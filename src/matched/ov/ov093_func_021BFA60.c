/*
 * function: func_021BFA60
 * address: 0x021BFA60
 * packet: pkt_ov093_021BFA60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Declare flag before base to place their spills at the original stack offsets.
 * symbols:
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021C69B8 0x021C69B8 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C6A04 0x021C6A04 thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D7630 0x021D7630 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D7908 0x021D7908 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 */
#include "../include/Obj07752.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q { u16 h0; u8 pad[6]; u32 w8; };
extern int func_021BF324(u8 *, u8 *, u8 *);
extern int func_021C69B8(u8 *, u8 *, u32, u16);
struct Unk021D62A8;
struct UtilWork;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021C6A04(u8 *, u8 *, u8 *, struct Q *);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D7630(int, u32);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D75A8(int, u32);
extern void func_021D7674(int, u32, u32, u32);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int);
extern void func_021D7704(int, int);
extern void func_021D7540(int);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern unsigned char func_021D7908(int a, int i);
extern u32 func_021D7B10(u32, u32);
extern int func_021B911C(void *, int);
extern u32 func_021D78AC(u32);
int func_021BFA60(u8 *p, u8 *a, u8 *b, struct Q *q)
{
    u8 flag;
    s8 x, y;
    int base;
    u32 scale;
    int v;
    u32 chance;
    if (func_021BF324(p, a, b)) return 1;
    if (func_021C69B8(p, a, (u32)b, q->h0)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)b, 32)) return 1;
    base = func_021C6A04(p, a, b, q);
    func_021D74F8(5014);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D7630(75, 0);
    func_021D75A8(39, func_021D59B4(a, 6));
    func_021D75A8(40, func_021D59B4(b, 7));
    func_021D7674(53, 4 << 10, 41, 4 << 15);
    func_021D70F0(p, 51);
    x = func_021D775C(39);
    y = func_021D775C(40);
    flag = func_021D775C(75);
    if ((func_021D62C4((struct Unk021D62A8 *)b, 17) && y > 6) || flag) y = 6;
    if (func_021D5BB0((struct UtilWork *)a, 14)) func_021D7704(53, 4915);
    scale = func_021D775C(53);
    func_021D7540(5039);
    v = x + 6 - y;
    if (v < 0) v = 0;
    if (v > 12) v = 12;
    chance = func_021D7B10(func_021D7908((u8)base, (u8)(s8)v), scale);
    if (chance > 100) chance = 100;
    if (func_021B911C(((struct Obj07752 *)p)->f4, 6)) chance = 100;
    if (func_021D78AC(100) < (u8)chance) return 1;
    return 0;
}

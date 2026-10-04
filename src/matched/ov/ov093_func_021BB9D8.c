/*
 * function: func_021BB9D8
 * address: 0x021BB9D8
 * packet: pkt_ov093_021BB9D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: the four flag clears are typed bitfield assignments, emitting bics.
 * func_021C5474 leaves its input in r0 for the following func_021BBB38.
 * symbols:
 *   func_021D6EAC 0x021D6EAC thumb ov093
 *   func_021EF874 0x021EF874 thumb ov093
 *   func_021BBB08 0x021BBB08 thumb ov093
 *   func_021BBB18 0x021BBB18 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BBB28 0x021BBB28 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021C7C18 0x021C7C18 thumb ov093
 *   func_021C8588 0x021C8588 thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021CC8C8 0x021CC8C8 thumb ov093
 *   func_021C5474 0x021C5474 thumb ov093
 *   func_021BBB38 0x021BBB38 thumb ov093
 */
#include "../include/Obj02133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 a:1; u8 b:1; u8 c:1; u8 pad:3; u8 d:1; u8 rest:1; } Flags;
extern void func_021D6EAC(void);
extern int func_021EF874(int a);
extern void func_021BBB08(void *);
extern void func_021BBB18(void *);
extern u32 func_021B8588(void **p);
extern void func_021BBB28(void *, void *, void *, u32);
extern void func_02082BCC(void *, int, u32);
extern void func_021C7C18(void *);
extern void func_021C8588(unsigned char *p);
extern void func_021D8230(u8 *p);
extern void func_021CC8C8(void *);
extern void *func_021C5474(void *);
extern void func_021BBB38(void *);
void func_021BB9D8(u8 *p)
{
    func_021D6EAC();
    func_021EF874(0);
    func_021BBB08(p + 0x1c);
    func_021BBB18(p + 0x3e0);
    func_021BBB28(p + 0x1ab8, ((struct Obj02133 *)p)->f4, ((struct Obj02133 *)p)->f8, func_021B8588(((struct Obj02133 *)p)->f4));
    func_02082BCC(p + 0x7a9, 0, 0x18);
    func_02082BCC(p + 0x7c1, 0, 0x18);
    func_02082BCC(p + 0x7d9, 0, 4);
    func_02082BCC(p + 0x4d4, 0, 0x2a0);
    func_021C7C18(p + 0x1f7c);
    func_021C8588(p);
    func_021D8230(p + 0x4b8);
    func_021CC8C8(p + 0x1d74);
    func_021BBB38(func_021C5474(p + 0x1b50));
    p[0x786] = 0;
    p[0x787] = 0;
    ((Flags *)(p + 0x78a))->a = 0;
    ((Flags *)(p + 0x78a))->b = 0;
    ((Flags *)(p + 0x78a))->c = 0;
    p[0x77c] = 0;
    p[0x789] = 31;
    ((struct Obj02133 *)p)->f1F74 = 0;
    p[0x784] = 6;
    ((struct Obj02133 *)p)->f774 = 0;
    p[0x77e] = 0;
    ((struct Obj02133 *)p)->f778 = 0;
    ((Flags *)(p + 0x78a))->d = 0;
}

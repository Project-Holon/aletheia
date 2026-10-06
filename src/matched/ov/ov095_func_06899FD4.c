/*
 * unit:     yes
 * function: func_06899FD4, func_06899FDC, func_06899FE8, func_0689A008, func_0689A020, func_0689A028
 * address:  0x06899FD4
 * packet:   pkt_ov095_06899FD4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed extent 0x06899FC4 (108 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D8434 (ARM linker stub, not compilable); the six unlabelled
 * tail-call stubs after it (0x06899FD4..0x0689A030) are this unit.
 *
 * symbols:
 *   func_06899E68  0x06899E68  thumb  ov095
 *   func_06899E48  0x06899E48  thumb  ov095
 *   func_06899E2C  0x06899E2C  thumb  ov095
 *   func_0689A878  0x0689A878  thumb  ov095
 *   func_0689A84C  0x0689A84C  thumb  ov095
 *   func_0689B0D4  0x0689B0D4  thumb  ov095
 *   func_0689B1E4  0x0689B1E4  thumb  ov095
 */
#include "../include/Obj10164.h"
#include "../include/Obj13634.h"
#include "../include/Obj21890.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_06899E68(void);
struct Q;
extern void func_06899E48(struct Q *p, void *a, void *b);
extern void func_06899E2C(void);
extern int func_0689A878(int unused, u8 *s);
extern int func_0689A84C(u32 unused, u32 p);
extern int func_0689B0D4(int unused, u8 *s);
extern int func_0689B1E4(int *state, u8 *s);

void func_06899FD4(void)
{
    func_06899E68();
}

void func_06899FDC(u8 *p)
{
    func_06899E48((struct Q *)p, 0, (void *)((struct Obj21890 *)p)->f68);
}

void func_06899FE8(u8 *p, u32 a, u32 b)
{
    ((struct Obj10164 *)p)->f6C = a;
    ((struct Obj10164 *)p)->f70 = b;
    ((struct Obj10164 *)p)->f98 = 0;
    func_06899E48((struct Q *)p, (void *)func_0689A878, (void *)func_0689A84C);
}

void func_0689A008(u8 *p, u32 a, u32 b)
{
    ((struct Obj13634 *)p)->f6C = a;
    ((struct Obj13634 *)p)->f70 = b;
    func_06899E48((struct Q *)p, (void *)func_0689B0D4, (void *)func_0689B1E4);
}

void func_0689A020(void)
{
    func_06899E68();
}

void func_0689A028(void)
{
    func_06899E2C();
}

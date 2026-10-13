/*
 * file:     unit_068989C0.c
 * unit:     yes
 * function: func_068989C0, func_068989CC
 * address:  0x068989C0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb
 *   func_021C8020  0x021C8020  thumb
 *   func_021C8138  0x021C8138  thumb
 *   func_021C83D4  0x021C83D4  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D6A0 0x0689D6A0 data a4
 */
#include "../../matched/include/Obj10161.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int w0; u32 w1; u8 pad[0x10]; u32 w6; } D;

extern int BTL_EVENT_GetVar(int k);
extern int func_021C83D4(int b);
extern int func_021C8138(int b);
extern int func_021C8020(int b, int c);
extern int func_021C7CF4(int b, int s);
extern int BTL_POKEPARAM_IsFainted(int x);
extern u8 *func_021C88A4(int b, int n, int k);
extern void func_021C8838(void *p, int n, int v);
extern void func_021C8860();
extern void func_021C88C8(int b, void *p);
extern void BTL_EVENT_RemoveFactor(int a);
void *func_068989C0(u32 *p);
void func_068989CC(int a, int b, int c, D *d);
extern char d_0689D6A0[];

/*
 * Follower of the non-C veneer at 0x068989B0; code and pool end at 0x068989CC.
 */
void *func_068989C0(u32 *p)
{
    *p = 1;
    return d_0689D6A0;
}

/*
 * Message pointer y is passed live in r1 to 06898B40, whose fixed veneer
 * targets two-argument func_021C88C8. Omitting y lost its r0-to-r1 copy.
 */
void func_068989CC(int a, int b, int c, D *d)
{
    if (BTL_EVENT_GetVar(2) == 0x1f && func_021C83D4(b) == 0) {
        u8 t = func_021C8138(b);
        if (t >= d->w0) {
            int s = func_021C8020(b, c);
            u8 k = d->w6;
            if (s != 0x1f && s != k) {
                if (BTL_POKEPARAM_IsFainted(func_021C7CF4(b, s)) == 0) {
                    u8 *x = func_021C88A4(b, 4, k);
                    u8 *y;
                    func_021C8838(x + 4, 2, 0x438);
                    func_021C8860(x + 4, s);
                    func_021C8860(x + 4, d->w1);
                    func_021C88C8(b, x);
                    y = func_021C88A4(b, 0x27, k);
                    y[4] = k;
                    y[5] = s;
                    ((struct Obj10161 *)y)->f6 = d->w1;
                    func_021C88C8(b, y);
                }
            }
            BTL_EVENT_RemoveFactor(a);
        }
    }
}

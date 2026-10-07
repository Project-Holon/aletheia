/*
 * file:     field_fog_p06.c
 * unit:     yes
 * function: func_0219FE64, func_0219FE9C, func_0219FEB0, func_0219FFBC
 * address:  0x0219FE64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0205085C  0x0205085C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_02050880  0x02050880  arm
 *   data_021D8548  0x021D8548  data  ov021  a1
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02189A78  0x02189A78  thumb  ov021
 */
#include "../../matched/include/Obj17985.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed int     s32;

typedef struct { u8 b[4]; } U8x4;

extern u16 func_0216D598(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern void func_0205085C(void *p, int idx, u32 v);
extern u32 func_02082BCC(u32, u32, u32, u32);
extern u16 func_0216D678(void *p);
extern u32 func_0219FFD4(u32);
extern void func_0205082C(void *p, int idx, u32 h);
extern u16 func_02050880(u8 *p, int i);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern u32 func_02189A78(u8 *p);
void func_0219FE64(u32 a);
int func_0219FE9C(u32 a, u32 b, u32 c, u32 d);
void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id);
void func_0219FFBC(u32 a, u32 *p);
extern const U8x4 data_021D8548;


/*
 * Addresses are Black-image addresses.
 */
void func_0219FE64(u32 a)
{
    u16 v;
    u16 z;
    if (func_0216D598((void *)a) == 0x7B) {
        z = 0;
        v = func_0216D7A8((void *)a, 0);
        if (v != 0xFFFF) {
            func_0205085C((void *)func_0219C9DC((u8 *)func_0216D910(a)), v, z);
        }
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219FE9C(u32 a, u32 b, u32 c, u32 d)
{
func_02082BCC(a, 0, 4, d);
((struct Obj17985 *)((u8 *)(a)))->f0 = 8;
return 8;
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id)
{
    U8x4 tbl;
    u32 flag;
    u16 k;
    u32 y;
    u32 x;

    flag = 0;
    y = func_0219FFD4(a);
    x = func_0216D678((void *)a);
    k = y + x * 4;
    if (s[3] != 0 && x == s[1])
        s[3] = flag;
    if (y != s[0]) {
        flag = 1;
        s[1] = x;
        s[0] = y;
        s[2] = 0;
        func_0205082C((void *)r, id, k);
    } else if (x != s[1]) {
        flag = 1;
        if (x == 0) {
            if (s[1] == 0) {
                func_0205082C((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            } else {
                if (s[3] == 0) {
                    s[3]++;
                    flag = 0;
                    goto tail;
                }
                tbl = data_021D8548;
                s[2] = func_02050880((u8 *)r, id);
                if (s[2] >= 4)
                    s[2] = 0;
                s[2] = tbl.b[s[2]];
                func_0205082C((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            }
        } else {
            if (s[1] != 0) {
                s[2] = func_02050880((u8 *)r, id);
                s[2] = (s[2] >= 2) ? 0 : 2;
            }
            func_0205082C((void *)r, id, k);
            func_0205085C((void *)r, id, s[2]);
            s[1] = x;
            s[3] = 0;
        }
    }
tail:
    func_021A000C(a, r, id, flag, 0);
}


void func_0219FFBC(u32 a, u32 *p)
{
    p[1] += func_02189A78((u8 *)func_0216D534(func_0216D67C((void *)a)));
}

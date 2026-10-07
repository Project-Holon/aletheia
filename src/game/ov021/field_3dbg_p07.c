/*
 * file:     field_3dbg_p07.c
 * unit:     yes
 * function: func_021A15F4, func_021A1670, func_021A1680, func_021A1698, func_021A16D4, func_021A16D8, func_021A16DC, func_021A16E0, func_021A16E4
 * address:  0x021A15F4
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
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1784  0x021A1784  thumb  ov021
 *   func_021A1934  0x021A1934  thumb  ov021
 *   func_021A195C  0x021A195C  thumb  ov021
 *   func_021A1848  0x021A1848  thumb  ov021
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207D8C4  0x0207D8C4  arm
 *   d_02148B54     0x02148B54  data  a4
 *   func_021A1768  0x021A1768  thumb  ov021
 *   func_021A1750  0x021A1750  thumb  ov021
 *   func_021A16EC  0x021A16EC  thumb  ov021
 */
#include "../../matched/include/Obj07216.h"
#include "../../matched/include/Obj17994.h"
#include "../../matched/include/Obj17995.h"
#include "../../matched/include/Obj17996.h"
#include "../../matched/include/Obj19720.h"
#include "../../matched/include/Obj19721.h"
#include "../../matched/include/Obj19722.h"

typedef unsigned int u32;

typedef struct { u32 w[16]; } S64;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A1780(u8 *p);
extern void func_021A1784(u32 *, u32 *, u32 *, S64 *);
extern void func_021A1934(u8 *p);
extern void func_021A195C(u32 *);
extern void func_021A1848(const s32 *a);
extern void func_0206DB80(void);
extern void func_0207D8C4(S64 *);
void func_021A1768(u8 *p);
int func_021A1750(u32 a);
extern void func_021A16EC(u8 *d, void *a, const u8 *s, u32 n);
void ov021_func_021A15F4(u32 *p);
void func_021A1670(u8 *p);
void func_021A1680(u8 *p);
int func_021A1698(u32 a, int b, void *c, int d);
void func_021A16D4(u8 *p, u32 v);
void func_021A16D8(u8 *p, u8 v);
void func_021A16DC(unsigned char *p, unsigned int v);
void func_021A16E0(unsigned char *p, unsigned int v);
void func_021A16E4(unsigned char *p, unsigned int v);
extern S64 d_02148B54;


void ov021_func_021A15F4(u32 *p)
{
    S64 buf;
    volatile u32 *r;
    if (p != 0 && p[2] != 0 && func_021A1780((u8 *)(p + 8)) != 0) {
        func_0206DB80();
        *(volatile u32 *)0x04000440 = 0;
        buf = d_02148B54;
        func_0207D8C4(&buf);
        r = (volatile u32 *)0x04000440;
        r[0] = 2;
        r[5] = 0;
        r[1] = 0;
        func_021A1784(p + 11, p, p + 8, &buf);
        func_021A1934((u8 *)p);
        func_021A195C(p);
        func_021A1848((const s32 *)(p + 11));
        r[2] = 1;
    }
}


void func_021A1670(u8 *p)
{
    if (p != 0)
        func_021A1768(p + 0x20);
}


void func_021A1680(u8 *p)
{
    if (func_021A1780(p + 0x20) != 0)
        func_021A1750((u32)(p + 0x20));
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A1698(u32 a, int b, void *c, int d)
{
if (func_021A1780((u8 *)(a + 32)) != 0) {
    func_021A1750((a + 32));
}
func_021A16EC((u8 *)(a + 32), (void *)b, (const u8 *)c, d);
((struct Obj07216 *)((u8 *)(a)))->f1F = ((struct Obj17994 *)((u8 *)(c)))->f8;
((struct Obj07216 *)((u8 *)(a)))->f14 = (1 << 12);
((struct Obj07216 *)((u8 *)(a)))->f18 = (1 << 12);
((struct Obj07216 *)((u8 *)(a)))->f1C = 0;
return 0;
}


/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_021A16D4(u8 *p, u32 v)
{
    ((struct Obj17995 *)p)->f8 = v;
}


/*
 * Field setter at +0x1e.
 *
 * Addresses are Black-image addresses.
 */
void func_021A16D8(u8 *p, u8 v)
{
    ((struct Obj17996 *)p)->f1E = v;
}


/*
 * Unlabelled leaf (str r1,[r0,#0xc]; bx lr), filed for the ov026 lane.
 */
void func_021A16DC(unsigned char *p, unsigned int v)
{
    ((struct Obj19720 *)p)->fC = v;
}


/*
 * Unlabelled leaf (str r1,[r0,#0x10]; bx lr), filed for the ov026 lane.
 */
void func_021A16E0(unsigned char *p, unsigned int v)
{
    ((struct Obj19721 *)p)->f10 = v;
}


/*
 * Unlabelled leaf (str r1,[r0,#0x14]; bx lr), filed for the ov026 lane.
 */
void func_021A16E4(unsigned char *p, unsigned int v)
{
    ((struct Obj19722 *)p)->f14 = v;
}

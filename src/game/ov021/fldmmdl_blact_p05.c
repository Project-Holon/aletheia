/*
 * file:     fldmmdl_blact_p05.c
 * unit:     yes
 * function: func_0219D49C, func_0219D4AC, func_0219D4EC, func_0219D524, func_0219D558
 * address:  0x0219D49C
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D528  0x0216D528  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DDD80     0x021DDD80  data ov021 a4
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj17972.h"
#include "../../matched/include/Obj04226.h"
#include "../../matched/include/Obj06002.h"
#include "../../matched/include/Obj09515.h"
#include "../../matched/include/Obj09517.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 a; u16 b; } E4;

extern u32 func_0216D528(u32);
extern void *func_0216D67C(void *a0);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_021C6580(u8 *p, int i);
extern u32 func_020307B0(void *p);
u32 func_0219D49C(u32 a);
void func_0219D4AC(int *obj, int a);
void func_0219D4EC(u8 *s);
u16 func_0219D524(u32 *s, u32 b, u32 a);
u16 func_0219D558(u8 *s, u16 k);
extern unsigned char d_021DDD80[];


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D528 (0x0216D528) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219D49C(u32 a)
{
return ((struct Obj17972 *)((u8 *)(func_0216D528((u32)func_0216D67C((void *)a)))))->f4;
}



/*
 * Allocates n*4 bytes (n = *(u16 *)(obj+8)), stores the pointer at obj+0xc,
 * then writes 0xFFFF into the high halfword of each 4-byte entry.
 */
void func_0219D4AC(int *obj, int a)
{
    int i;
    *(int *)&((struct Obj04226 *)obj)->fC =
        (int)(unsigned short *)func_02030734(a, ((struct Obj04226 *)obj)->f8 * 4,
                                             1, (const char *)d_021DDD80, 0x7f);
    for (i = 0; i < (int)((struct Obj04226 *)obj)->f8; i++) {
        unsigned short *p = *(unsigned short * *)&((struct Obj04226 *)obj)->fC;
        p[i * 2 + 1] = 0xFFFF;
    }
}



void func_0219D4EC(u8 *s)
{
    int i = 0;
    E4 *e = *(E4 * *)&((struct Obj06002 *)s)->fC;
    if (i < ((struct Obj06002 *)s)->f8) {
        for (; i < ((struct Obj06002 *)s)->f8; i++, e++) {
            if (e->b != 0xFFFF) {
                func_021C6580((u8 *)(((struct Obj06002 *)s)->f4), e->a);
            }
        }
    }
    func_020307B0(((struct Obj06002 *)s)->fC);
}



u16 func_0219D524(u32 *s, u32 b, u32 a)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09515 *)s)->fC;
    int n = ((struct Obj09515 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == 0xFFFF) {
            e->b = b;
            e->a = a;
            return i;
        }
    }
    return 0;
}



u16 func_0219D558(u8 *s, u16 k)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09517 *)s)->fC;
    int n = ((struct Obj09517 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            return e->a;
        }
    }
    return 0xFFFF;
}

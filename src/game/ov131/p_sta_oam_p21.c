/*
 * file:     p_sta_oam_p21.c
 * unit:     yes
 * function: func_021D8884, func_021D8904
 * address:  0x021D8884
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049E74 0x02049E74 arm
 *   func_021DBA90 0x021DBA90 thumb ov131
 *   func_021D909C 0x021D909C thumb ov131
 *   func_021DBAC0 0x021DBAC0 thumb ov131
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj00776.h"
#include "../../matched/include/Obj05392.h"

struct S;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct S { u32 a; u32 p1[10]; void *f2c; u32 p2; void *f34; u32 p3; void *f3c; u32 p4; void *f44; u32 p5; void *f4c; u32 p6[7]; void *f6c; };

extern void *func_02049EF4(void *, unsigned int, unsigned int, void **, unsigned short);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct S *func_021DBA90(u32 a, u32 b);
extern void func_021D909C(unsigned char *a, unsigned char *p);
extern void func_021DBAC0(u8 *p);
extern u32 func_020307B0(void *p);
void func_021D8884(unsigned char *a, unsigned char *p, void *arc);
void func_021D8904(void *a, struct S *s);

void func_021D8884(unsigned char *a, unsigned char *p, void *arc)
{
    ((struct Obj05392 *)p)->f2C = func_02049EF4(arc, 66, 0, (void **)(p+0x28), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f34 = func_02049EF4(arc, 67, 0, (void **)(p+0x30), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f3C = func_02049EF4(arc, 68, 0, (void **)(p+0x38), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f44 = func_02049EF4(arc, 69, 0, (void **)(p+0x40), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f4C = func_02049E74(arc, 12, 0, (u32)(p+0x48), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f6C = func_021DBA90(((struct Obj00776 *)a)->f0, (u32)(((struct Obj00776 *)a)->f174));
}

void func_021D8904(void *a, struct S *s) {
 if (s->a == 1) func_021D909C(a, (unsigned char *)s);
 func_021DBAC0(s->f6c);
 func_020307B0(s->f4c);
 func_020307B0(s->f2c);
 func_020307B0(s->f34);
 func_020307B0(s->f3c);
 func_020307B0(s->f44);
}

/*
 * function: func_021D5C98
 * address: 0x021D5C98
 * packet: pkt_ov131_021D5C98
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfwords reread at 021D5D96, 021D5DA0, 021D5DA6
 *   and written at 021D5D9C, 021D5DA4, 021D5DAA.
 * arithmetic: full-word selectors have cases 0..3 and an empty default;
 *   no selector bound is assumed. Halfword OR with 64 fits promoted int.
 * interfaces: own matched 60D4,697C,7C38,9C3C,8F50,9D44,A84C;
 *   matched callers 4418,4240,7BF0 supply remaining two-argument calls.
 *   Full original 6CDC and 909C confirm both incoming payloads are passed.
 * symbols:
 *   func_021D60D4 0x021D60D4 thumb ov131
 *   func_021D6CDC 0x021D6CDC thumb ov131
 *   func_021D91EC 0x021D91EC thumb ov131
 *   func_021D697C 0x021D697C thumb ov131
 *   func_021D911C 0x021D911C thumb ov131
 *   func_021D7E84 0x021D7E84 thumb ov131
 *   func_021D9D44 0x021D9D44 thumb ov131
 *   func_021D909C 0x021D909C thumb ov131
 *   func_021DA84C 0x021DA84C thumb ov131
 *   func_021D7C38 0x021D7C38 thumb ov131
 *   func_021D9C3C 0x021D9C3C thumb ov131
 *   func_021D8F50 0x021D8F50 thumb ov131
 *   func_021DA6A4 0x021DA6A4 thumb ov131
 */
#include "../include/Obj00039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D60D4(u8 *,int);
extern void func_021D6CDC(unsigned char *a, unsigned char *b);
extern void func_021D91EC(void *,void *);
extern void func_021D697C(u8 *,int *);
extern void func_021D911C(u8 *a, u8 *p);
extern void func_021D7E84(void *,u8 *);
extern void func_021D9D44(void *,u8 *);
extern void func_021D909C(u8 *a, u8 *p);
extern void func_021DA84C(u8 *,u8 *);
extern void func_021D7C38(void *,u8 *);
extern void func_021D9C3C(void *,u8 *);
extern void func_021D8F50(void *,u8 *);
extern void func_021DA6A4(u8 *a, u8 *p);
void func_021D5C98(u8 *p)
{
    func_021D60D4(p,1);
    if (p[0x1a]!=((struct Obj00039 *)p)->f18) {
        if (p[0x1a]!=255) {
            func_021D6CDC(p,((struct Obj00039 *)p)->f88);
            func_021D91EC(p,((struct Obj00039 *)p)->f94);
        }
        func_021D697C(p,*(int * *)&((struct Obj00039 *)p)->f88);
        func_021D911C(p,((struct Obj00039 *)p)->f94);
    }
    switch (((struct Obj00039 *)p)->f5C) {
    case 0: func_021D7E84(p,*(u8 * *)&((struct Obj00039 *)p)->f8C); break;
    case 1: func_021D9D44(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: func_021D909C(p,((struct Obj00039 *)p)->f94); break;
    case 3: func_021DA84C(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    }
    switch (*(u32 *)&((struct Obj00039 *)p)->f58) {
    case 0: func_021D7C38(p,*(u8 * *)&((struct Obj00039 *)p)->f8C); break;
    case 1: func_021D9C3C(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: func_021D8F50(p,*(u8 * *)&((struct Obj00039 *)p)->f94); break;
    case 3: func_021DA6A4(p,((struct Obj00039 *)p)->f90); break;
    }
    if (((struct Obj00039 *)p)->f5C!=*(u32 *)&((struct Obj00039 *)p)->f58) {
        ((struct Obj00039 *)p)->f25C=1;
        p[0x260]=0;
        *(volatile u16 *)0x0400000c |= 64;
        *(volatile u16 *)0x0400100a |= 64;
        *(volatile u16 *)0x0400100c |= 64;
    }
    func_021D60D4(p,0);
    ((struct Obj00039 *)p)->fC=1;
}

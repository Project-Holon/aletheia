/*
 * file:     union_oneself_p13.c
 * unit:     yes
 * function: func_0217F9BC, func_0217F9DC
 * address:  0x0217F9BC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   d_02180814 0x02180814 data ov019 a4
 *   func_02034714 0x02034714 arm
 *   func_0217FB30 0x0217FB30 thumb ov019
 *   func_0217FA10 0x0217FA10 thumb ov019
 */
#include "../../matched/include/Obj05958.h"
#include "../../matched/include/Obj09420.h"

struct Tagged;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct E { u32 a,b,c,d; u16 h; };

extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct E *func_0217FB30(struct E *p);
extern void func_0217FA10(char *p, u32 *out, u32 a, u16 b);
void func_0217F9BC(char *p);
void func_0217F9DC(char *p, u32 a);
extern const char d_02180814[];

void func_0217F9BC(char *p) { func_020470D0(((struct Obj05958 *)p)->f14); func_02046EFC(((struct Obj05958 *)p)->f18); ((struct Obj05958 *)p)->f18=0; func_02046EFC(((struct Obj05958 *)p)->f14); ((struct Obj05958 *)p)->f14=0; }

void func_0217F9DC(char *p, u32 a)
{
    struct E *e;
    if (((struct Obj09420 *)p)->f14 == 0) func_02034714(d_02180814,0,d_02180814);
    e=func_0217FB30((struct E *)p);
    func_0217FA10(p,(u32 *)e,a,((struct Obj09420 *)p)->f1C);
    (((struct Obj09420 *)p)->f1C)++;
}

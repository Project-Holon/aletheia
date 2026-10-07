/*
 * file:     unit_021E2FA8_p01.c
 * unit:     yes
 * function: func_021E2FE8, func_021E300C
 * address:  0x021E2FE8
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   d_021E3910 0x021E3910 data a4
 */
#include "../../matched/include/Obj06616.h"
#include "../../matched/include/Obj24695.h"

struct Pair;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a,b; } Pair;

typedef struct { u32 f0,f4; Pair callbacks; } Table;

extern void func_021FD860(char *,u32,const struct Pair *);
extern void func_021FD15C(void *,int);
void func_021E2FE8(char *p);
void func_021E300C(Pair *out);
extern const Table d_021E3910;

void func_021E2FE8(char *p) { int zero=0;func_021FD860(*(char * *)&((struct Obj06616 *)p)->f30,0,0);if(((struct Obj06616 *)p)->f8){func_021FD15C(((struct Obj06616 *)p)->f8,((struct Obj24695 *)(*(char * *)&((struct Obj06616 *)p)->f3C))->f8);*(int *)&((struct Obj06616 *)p)->f8=zero;} }

void func_021E300C(Pair *out) {
    *out=d_021E3910.callbacks;
}

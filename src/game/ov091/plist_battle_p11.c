/*
 * file:     plist_battle_p11.c
 * unit:     yes
 * function: func_021BC1B4, func_021BC1D0, func_021BC228, func_021BC24C, func_021BC288
 * address:  0x021BC1B4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BDD78  0x021BDD78  thumb  ov091
 *   func_021BBE74 0x021BBE74 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02017988 0x02017988 thumb
 *   func_02019D00  0x02019D00  thumb
 */
#include "../../matched/include/Obj20908.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 id;
    char pad[0x27e];
    int *f;
} P;

extern unsigned int func_02020FE4(void *,unsigned int,unsigned int);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BDD78(void *a, u32 id, int slot, u32 heap);
extern int func_021BBE74(int);
extern u32 func_02017E1C(void *,u32,u32);
extern unsigned int func_02019CF8(unsigned int item);
extern u32 func_02017988(void *,u32);
extern u32 func_02019D00(u32 id);
int func_021BC1B4(unsigned short *p,void *id);
int func_021BC1D0(P *p);
int func_021BC228(int unused,int id);
void func_021BC24C(void *unused,void *a,int b);
void func_021BC288(int unused, int a, int b);

int func_021BC1B4(unsigned short *p,void *id) { if(func_02020FE4(id,27,*p)) return 1; return 0; }


int func_021BC1D0(P *p)
{
    u8 n;
    u8 i;
    n = func_0201AA18((void *)*p->f);
    for (i = 0; i < n; i++) {
        int **q = &p->f;
        int e = (int)func_0201AB28((void *)*p->f, i);
        if (func_021BDD78((void *)e, ((struct Obj20908 *)((char *)*q))->f44, 0, p->id) == 1)
            return i;
    }
    return -1;
}

int func_021BC228(int unused,int id) { switch(func_021BBE74(id)) { case 26: case 27: return 22; case 28: return 21; default: return 21; } }

/*
 * 2026-10-05 (D8 lane 15): the leaf func_02019CF8 is now filed EXACT in src/matched/arm9, so every
 * relocation resolves and this file is EXACT.
 */
void func_021BC24C(void *unused,void *a,int b) { u32 t=0; int r; if(func_02017E1C(a,5,0)==0x1ED) { t=func_02017E1C(a,0x6F,t); r=func_02019CF8(b); if(t!=r)func_02017988(a,r); } }


void func_021BC288(int unused, int a, int b)
{
    int t = 0;
    int r;
    if (func_02017E1C((void *)a, 5, 0) == 0x289) {
        t = func_02017E1C((void *)a, 0x6f, t);
        r = func_02019D00(b);
        if (t != r) {
            func_02017988((void *)a, (u16)r);
        }
    }
}

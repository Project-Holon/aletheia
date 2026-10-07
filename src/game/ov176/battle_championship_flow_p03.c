/*
 * file:     battle_championship_flow_p03.c
 * unit:     yes
 * function: func_0217B35C, func_0217B368, func_0217B380, func_0217B3B8, func_0217B3C0, func_0217B468, func_0217B4A0
 * address:  0x0217B35C
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90  0x021E8A90  thumb  ov177
 *   func_021E8AA0  0x021E8AA0  thumb  ov177
 *   func_0217B6AC  0x0217B6AC  thumb  ov176
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_0217B93C 0x0217B93C thumb ov176
 *   func_0217B964 0x0217B964 thumb ov176
 *   func_0217B7D8 0x0217B7D8 thumb ov176
 *   func_0217B930 0x0217B930 thumb ov176
 *   func_0217B924 0x0217B924 thumb ov176
 *   func_0217B970 0x0217B970 thumb ov176
 *   func_0217B7A0 0x0217B7A0 thumb ov176
 *   func_0217B55C 0x0217B55C thumb ov176
 *   func_0217B594 0x0217B594 thumb ov176
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0200B480 0x0200B480 thumb
 */
#include "../../matched/include/Obj14357.h"
#include "../../matched/include/Obj24404.h"

typedef struct {void (*fn)(void *,int *,int);int a;int b;} CB;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021E8A80(CB *);
extern int func_021E8A90(int **p);
extern void func_021E8AA0(int *p, int v);
extern void func_0217B6AC(int p, unsigned *state, int *q);
extern void func_021E8AA8(int);
extern void func_0217B93C(int *,int);
extern int func_0217B964(int *);
extern void func_0217B7D8(int *,int);
extern unsigned func_0217B930(int *);
extern void func_0217B924(int *);
extern void func_0217B970(int *,int);
extern void func_0217B7A0(int *p, int *state, u8 *q);
extern void func_0217B55C(int p, int *state, int *q);
extern void func_0217B594(int p, int *state, char *q);
extern int func_0202EB44(void);
extern void func_0200B480(void);
void func_0217B35C(CB **p);
int func_0217B368(int *p);
void func_0217B380(int a, int b, int *p);
void func_0217B3B8(int p);
void func_0217B3C0(int p, unsigned *state, int *q);
void func_0217B468(int *p,int *state,u8 *q);
void func_0217B4A0(int p,unsigned *state,int *q);

/*
 * leaf: sole blocker of owned 0217B0C8 MATCH; no prior source/unit/shard, parent claim accepted.
 */
void func_0217B35C(CB **p)
{
    func_021E8A80(*p);
}


/*
 *   func_021E8A90 (0x021E8A90) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int func_0217B368(int *p)
{
    if (func_021E8A90((int **)(((struct Obj14357 *)p)->f0)))
        return ((struct Obj14357 *)p)->f10;
    return 0;
}


void func_0217B380(int a, int b, int *p)
{
    switch (((struct Obj24404 *)p)->f14) {
    case 0:
        func_021E8AA0((int *)a, (int)func_0217B3C0);
        break;
    case 1:
        func_021E8AA0((int *)a, (int)func_0217B4A0);
        break;
    case 2:
        func_021E8AA0((int *)a, (int)func_0217B6AC);
        break;
    }
}

void func_0217B3B8(int p) {func_021E8AA8(p);}

void func_0217B3C0(int p, unsigned *state, int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,0); *state = 1; break;
    case 1: if (func_0217B964(q) == 1) *state = 2; break;
    case 2: func_0217B7D8(q,0); *state = 3; break;
    case 3:
        result = func_0217B930(q);
        if (result != -1) {
            switch (result) {
            case 0: func_021E8AA0((int *)p,(int)func_0217B4A0); break;
            case 1: func_021E8AA0((int *)p,(int)func_0217B6AC); break;
            case 2: func_021E8AA0((int *)p,(int)func_0217B468); break;
            case 3: func_0217B970(q,1); break;
            }
            func_0217B924(q);
        }
        break;
    }
}

void func_0217B468(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B93C((int *)q,1);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B3C0);break;}}

/*
 * extent: stale 0217B550 data label splits its final twelve pool bytes; real next function is separately filed 0217B55C.
 */
void func_0217B4A0(int p,unsigned *state,int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,9); *state=1; break;
    case 1: if(func_0217B964(q)==1) *state=2; break;
    case 2: func_0217B7D8(q,1); *state=3; break;
    case 3:
        result=func_0217B930(q);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(func_0202EB44()==0) func_021E8AA0((int *)p,(int)func_0217B7A0);
                else {func_0200B480(); func_0217B970(q,2);}
                break;
            case 1: func_021E8AA0((int *)p,(int)func_0217B55C); break;
            case 2: func_021E8AA0((int *)p,(int)func_0217B594); break;
            case 3: func_021E8AA0((int *)p,(int)func_0217B3C0); break;
            }
            func_0217B924(q);
        }
        break;
    }
}

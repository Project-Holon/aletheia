/*
 * file:     br_net_p03.c
 * unit:     yes
 * function: func_021FF648, func_021FF660, func_021FF67C, func_021FF698, func_021FF6B4, func_021FF6DC, func_021FF704, func_021FF72C, func_021FF88C, func_021FF8D4, func_021FF8E0, func_021FF8E4, func_021FF900, func_021FF938
 * address:  0x021FF648
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FFB70 0x021FFB70 thumb ov186
 *   func_021D7374  0x021D7374  thumb  ov125
 *   func_021D73E0 0x021D73E0 thumb ov125
 *   func_021D74D8  0x021D74D8  thumb  ov125
 *   func_021D7414 0x021D7414 thumb ov125
 *   func_021D72EC 0x021D72EC thumb ov125
 *   func_021D72F8 0x021D72F8 thumb ov125
 *   func_02006210 0x02006210 thumb
 *   func_0200FB4C 0x0200FB4C thumb
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200F7DC 0x0200F7DC thumb
 *   func_021D730C  0x021D730C  thumb  ov125
 *   func_021FFB68  0x021FFB68  thumb  ov186
 *   func_021D67C8 0x021D67C8 thumb ov125
 *   func_02034714 0x02034714 arm
 *   d_02200D98 0x02200D98 data a1
 *   func_021D6814 0x021D6814 thumb ov125
 */
#include "../../matched/include/Obj24855.h"
#include "../../matched/include/Obj24856.h"
#include "../../matched/include/Obj24858.h"
#include "../../matched/include/Obj24860.h"
#include "../../matched/include/Obj24861.h"
#include "../../matched/include/Obj24862.h"
#include "../../matched/include/Obj24863.h"
#include "../../matched/include/Obj24864.h"
#include "../../matched/include/Obj14481.h"
#include "../../matched/include/Obj24865.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed int s32;

typedef struct{int words[32];} Block128;

typedef struct{int words[108];} Block432;

extern int func_021FFB70(int *,int);
extern int func_021D7374(char *a, void **out, int max);
extern unsigned long long func_021D73E0(char *a0);
extern int func_021D74D8(void *unused, char **out);
extern int func_021D7414(char *unused, char *dst, int n);
extern int func_021D72EC(char *,int **);
extern void func_021D72F8(char *);
extern void func_02006210(void);
extern void func_0200FB4C(unsigned int x);
extern int func_02157170(int, int);
extern void func_0200F7DC(void);
extern int func_021D730C(char *p);
extern void func_021FFB68(char *p, int v);
extern int func_021D67C8(char*,const Block128*,const Block432*);
extern void func_02034714(const char*,u32,const char*);
extern int func_021D6814(char *,int);
int func_021FF648(char *p);
int func_021FF660(char *p, int a1, int a2, int *out);
u32 func_021FF67C(u8*p,unsigned long long*out);
int func_021FF698(char *p, int a1, int *out);
int func_021FF6B4(char*p,void*buffer,int count,int*out);
int func_021FF6DC(char*p,void*buffer,int count,int*out);
int func_021FF704(char*p,void*buffer,int count,int*out);
int func_021FF72C(char *p,int *out);
int func_021FF88C(char *p);
int func_021FF8D4(char *p);
void func_021FF8E0(void);
void func_021FF8E4(void *p, int a1, int a2);
void func_021FF900(char*p,int unused,char*q);
void func_021FF938(char *p,int unused,char *q);
extern const char d_02200D98[];

int func_021FF648(char *p)
{
    return func_021FFB70(*(int * *)&((struct Obj24855 *)p)->f5AC,(int)func_021FF8E0);
}


int func_021FF660(char *p, int a1, int a2, int *out)
{
    int v = ((struct Obj24856 *)p)->f5BC;

    if (v != 0)
        *out = func_021D7374((char *)p, (void **)a1, a2);
    return v;
}

u32 func_021FF67C(u8*p,unsigned long long*out){u32 present;present=((struct Obj24858 *)p)->f5C0;if(present)*out=func_021D73E0((char *)p);return present;}


/*
 * Earlier blocker (closed): 5 bytes, a pure r4/r5 swap.  The original keeps the out pointer
 * in r4 and the field value in r5; every spelling tried (named pointer copy,
 * reversed declarations, int index, inline re-read) makes this compiler put
 * the field value in r4 and the pointer in r5, because the loaded value is
 *   the first live temporary while the pointer (arg r2) is spilled to the
 *   highest callee-saved register.  `cmp`-style naming does not move it.
 *   Re-verified (DIFF fixer): declaration order v-then-o, assignment o-then-v,
 *   and dropping the `o` alias to store through `out` directly all still swap
 *   r4/r5 the same way.
 *
 * 2026-10-05: tried a local k=0x5c4 reused as the call argument, pointer-typed value, u32 types, struct field access, early return for v==0, static inline getter, out alias inside the if. All still give out in r5 and value in r4 (original: out r4, value r5). Residue unchanged: 5 bytes, pure r4/r5 swap.
 *
 * 2026-10-05 (D9-14): closed. The swap was a wrong callee arity: func_021D74D8
 *   (matched in ov125) takes two arguments; the 0x5c4 in r2 at the call is only the
 *   leftover offset register. Two-argument call, no alias local: EXACT.
 */
int func_021FF698(char *p, int a1, int *out)
{
    int v = *(int *)(p + 0x5c4);

    if (v != 0)
        *out = func_021D74D8(p, (char **)a1);
    return v;
}

int func_021FF6B4(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24860 *)p)->f5C8;if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}

int func_021FF6DC(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24861 *)p)->f5C8;if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}

int func_021FF704(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24862 *)p)->f5C8;if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}

/*
 * note: pass 4 2026-10-06 P4L01: EXACT (also with --lang c). Case 1 works on a block local copy of the
 *   result (`int r=result; ... r=1; ... result=r;`). The final `result=r` is a register copy that the
 *   allocator coalesces away, so the block after case 1's if is empty only after allocation; it is then
 *   merged into case 1's copy block, which gives that block a new (front of list) edge to the release
 *   join. The cross-jump keeps the first predecessor in the join's list, so case 1's `movs r5,#1` keeps
 *   and case 0's after-store copy and 22002's copy become hops onto it (the image's forward hop at +002E).
 *   Earlier forms (2 B off) kept case 0's copy, the earliest original edge.
 */
int func_021FF72C(char *p,int *out)
{
    const int *event;
    int result;
    if(func_021D72EC(p,(int **)&event)){
        result=1;
        if(event[1]==0){
            if(event[3]){
                if(out)*out=event[3]+283;
                result=1;
            }
        }else if(event[1]==1){
            int r=result;
            if(event[3]==7){
                if(out)*out=event[3]+298;
                r=1;
            }
            result=r;
        }else if(event[1]==2){
            switch(event[2]){
            case 21000:
                if(event[3]){if(out)*out=event[3]+230;result=2;}
                break;
            case 21001:
                if(event[3]){if(out)*out=event[3]+237;result=2;}
                break;
            case 22000:
                if(event[3]){
                    switch(event[3]){
                    case 150:func_02006210();func_0200FB4C(65);result=3;break;
                    case 151:func_02006210();func_0200FB4C(66);result=3;break;
                    case 152:func_02006210();func_0200FB4C(68);result=3;break;
                    case 153:func_02006210();func_0200FB4C(67);result=3;break;
                    default:if(out)*out=event[3]+261;result=2;break;
                    }
                }
                break;
            case 22001:
                if(event[3]){if(out)*out=event[3]+269;result=2;}
                break;
            case 22002:
                if(event[3]){if(out)*out=event[3]+274;result=1;}
                break;
            case 22003:result=0;break;
            }
        }
        func_021D72F8(p);
        if(result==3)*(int *)(p+0x5DC)=1;
        return result;
    }
    return 0;
}

int func_021FF88C(char *p)
{
    if (!p) return 0;
    switch (func_02157170(1, 0)) {
    case 1: func_02006210(); return 1;
    case 2: func_02006210(); ((struct Obj24863 *)p)->f5DC = 1; return 2;
    case 3: func_02006210(); func_0200F7DC(); break;
    }
    return 0;
}


int func_021FF8D4(char *p)
{
    return ((struct Obj24864 *)p)->f5DC;
}

void func_021FF8E0(void)
{
}


/*
 * 0x021FF8E0 is an unlabelled two-byte `bx lr` leaf reached through the pool
 * word 0x021FF8E1 (thumb bit set); now matched as src/matched/func_021FF8E0.c.
 */
void func_021FF8E4(void *p, int a1, int a2)
{
    if (func_021D730C((char *)a2) != 0)
        func_021FFB68(p, (int)((void *)func_021FF8E0));
}

void func_021FF900(char*p,int unused,char*q){if(!func_021D67C8(q,*(const Block128* *)&((struct Obj14481 *)q)->f5A8,*(const Block432* *)&((struct Obj14481 *)q)->f5B0))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

void func_021FF938(char *p,int unused,char *q) {if(!func_021D6814(q,((struct Obj24865 *)q)->f5B0))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

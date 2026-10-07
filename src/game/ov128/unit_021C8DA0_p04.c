/*
 * file:     unit_021C8DA0_p04.c
 * unit:     yes
 * function: func_021C9244, func_021C93C0, func_021C9450, func_021C94DC, func_021C9544, func_021C958C, func_021C95CC, func_021C9628
 * address:  0x021C9244
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C9238 0x021C9238 thumb ov128
 *   func_021C97A0 0x021C97A0 thumb ov128
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_021C9D0C 0x021C9D0C thumb ov128
 *   func_020061E4 0x020061E4 thumb
 *   func_021C98EC 0x021C98EC thumb ov128
 *   func_021C6438 0x021C6438 thumb ov128
 *   func_021C9730 0x021C9730 thumb ov128
 *   func_0204B98C 0x0204B98C arm
 *   func_021C987C 0x021C987C thumb ov128
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_021C9D88 0x021C9D88 thumb ov128
 *   func_021C6E18 0x021C6E18 thumb ov128
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C08 0x02035C08 arm
 *   d_021CA576 0x021CA576 data a1
 *   func_021C6DF8 0x021C6DF8 thumb ov128
 *   func_021C9BEC 0x021C9BEC thumb ov128
 *   func_021C9BF8 0x021C9BF8 thumb ov128
 *   func_02040618 0x02040618 arm
 *   func_021C9E10 0x021C9E10 thumb ov128
 *   func_021C9E6C 0x021C9E6C thumb ov128
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_021C9ED0 0x021C9ED0 thumb ov128
 *   func_021C9EF4 0x021C9EF4 thumb ov128
 *   d_021CA564 0x021CA564 data a2
 *   d_021CA538 0x021CA538 data a4
 *   d_021CA7E0 0x021CA7E0 data a4
 *   d_021CA521 0x021CA521 data a1
 */
#include "../../matched/include/Obj00773.h"
#include "../../matched/include/Obj10491.h"
#include "../../matched/include/Obj08131.h"
#include "../../matched/include/Obj23105.h"
#include "../../matched/include/Obj10493.h"
#include "../../matched/include/Obj02842.h"

struct Actor;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern void func_021C9238(char *p, void *b, void *c, void *d);
extern void func_021C97A0(u8 *,u8 *,u8 *,u16);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern int func_021C9D0C(u8 *,int);
extern void func_020061E4(u32 a);
extern void func_021C98EC(char *p, u8 *q);
extern void func_021C6438(u8 *,u8,u8);
extern void func_021C9730(u8 *,void *,u8 *);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021C987C(u8 *,u8 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern void func_021CA3A0(char *p);
extern void func_021CA3C4(char *p);
extern int func_021C9D88(u8 *p, int direction);
extern void func_021C6E18(u8 *p, int i, u16 a);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_020355D8(u8 v);
extern int func_02035C08(const void *);
extern void func_021C6DF8(u8 *p, u32 a);
extern void func_021C9BEC(u16 *p, void *b, void *c, int flag, int value, int a5);
extern void func_021C9BF8(u8 *p, u8 *q, int idx);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021C9E10(u8 *, u8 *, u16);
extern void func_021C9E6C(u8 *, void *);
extern void func_021C63AC(void *p, u32 *out, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u32 unused, u8 g);
extern void func_021C9ED0(u32, int, const u16 *, u32, u16);
extern void func_021C9EF4(u32, int, u32, u32, u32, u16);
int func_021C9244(u8 *p,u8 *q,u8 *r,u16 heap);
int func_021C93C0(char *p,void *q,void *r,int n);
int func_021C9450(void *p,int *q,void *r);
int func_021C94DC(void *p,void *q,void *r,int *flag);
int func_021C9544(void *p,int *q,char *r);
void func_021C958C(char *p, void *q, void *r, int s);
int func_021C95CC(u8 *p,void *a,void *b,int c);
void func_021C9628(u8 *p, void *unused, u8 *q, u16 heap);
extern const u8 d_021CA576[];
extern const s16 d_021CA564[][3];
extern const u32 d_021CA538[], d_021CA7E0[];
extern const u8 d_021CA521[];

int func_021C9244(u8 *p,u8 *q,u8 *r,u16 heap)
{
    switch(q[8]) {
    case 0:
        ((struct Obj00773 *)p)->fE=0; ((struct Obj00773 *)p)->f0=0;
    case 1:
        func_021C9238((char *)p,q,r,(void *)heap);
        func_021C97A0(p,q,r,heap);
        q[8]=2;
        break;
    case 2: q[8]=func_021C9544(p,(int *)q,(char *)r); break;
    case 3:
        func_021C958C((char *)p,q,r,heap);
        func_021C95CC(p,q,r,heap);
        q[8]=4; break;
    case 4: if(func_021C95CC(p,q,r,heap)==1)q[8]=5; break;
    case 5:
        if(func_0201C6B4(((struct Obj10491 *)r)->f34)==1) {
            func_02041EE4(2,0,0);func_02041EE4(3,0,0);q[8]=2;
        } break;
    case 6:
        if(((struct Obj00773 *)p)->fE) {
            --((struct Obj00773 *)p)->fC;
            if(((struct Obj00773 *)p)->fC)break;
        }
        if(func_021C9D0C(q,((struct Obj00773 *)p)->f8)) {
            func_020061E4(0x548);
            func_021C98EC((char *)p,r);
            func_021C6438(q,4,1);
            ((struct Obj00773 *)p)->fE=1;
            func_021C9730(p,q,r);
            return 1;
        } else q[8]=2;
        break;
    case 7:
        if(func_0204B98C(((struct Obj10491 *)r)->f164)!=1) {
            func_021C987C(p,r);
            func_021C6438(q,1,11);
            func_021C9730(p,q,r);
            return 1;
        } break;
    case 8: if(func_0204B98C(((struct Obj10491 *)r)->f168)!=1)q[8]=9; break;
    case 9: func_0202208C(0,0,0,0,6,1,heap);q[8]=10;break;
    case 10: if(func_020221A4()) {
        func_021C6438(q,6,0);func_021C9730(p,q,r);return 1;
        }break;
    }
    return 0;
}

int func_021C93C0(char *p,void *q,void *r,int n) {
 switch(n) {
 case 0:func_020061E4(0x551);func_021CA3A0(r);return 7;
 case 1:func_020061E4(0x556);func_021CA3C4(r);return 8;
 case 2:if(func_021C9D88(q,0)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=0;func_021C6E18(r,1,11);return 6;}break;
 case 3:if(func_021C9D88(q,1)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=1;func_021C6E18(r,0,10);return 6;}break;
 }
 return 2;
}

int func_021C9450(void *p,int *q,void *r) {
 if(*q==1 && (func_020362DC()&0xcf3)) {func_020355D8(0);*q=0;}
 if(func_020362DC()&2)return func_021C93C0(p,q,r,0);
 if(func_020362DC()&1024)return func_021C93C0(p,q,r,1);
 if(func_0203630C()&64)return func_021C93C0(p,q,r,2);
 if(func_0203630C()&128)return func_021C93C0(p,q,r,3);
 return 2;
}

int func_021C94DC(void *p,void *q,void *r,int *flag) {
 int v=func_02035C08(d_021CA576);
 if(v==-1)return 2;
 *flag=1;
 if(v==0)return func_021C93C0(p,q,r,3);
 if(v==1)return func_021C93C0(p,q,r,2);
 if(v==2)return func_021C93C0(p,q,r,0);
 return func_021C93C0(p,q,r,1);
}

int func_021C9544(void *p,int *q,char *r) {
 int flag=0; int ret;
 if(!func_0201C6B4(((struct Obj23105 *)r)->f34)) return 2;
 ret=func_021C94DC(p,q,r,&flag);
 if(flag) {func_020355D8(1); *q=1; return ret;}
 return func_021C9450(p,q,r);
}

void func_021C958C(char *p, void *q, void *r, int s) {
 int mode;
 ((struct Obj10493 *)p)->f4=0;
 func_021C6DF8(r,0);
 mode=(((struct Obj10493 *)p)->f8==2)?2:1;
 func_021C9BEC((u16 *)p,q,r,mode,((struct Obj10493 *)p)->f0,s);
 func_020061E4(0x548);
}

/*
 * extent: two-byte zero padding at 021C9626 before next label 021C9628.
 */
int func_021C95CC(u8 *p,void *a,void *b,int c)
{
    int value=((struct Obj02842 *)p)->f4;
    int offset;
    if(value>8) {
        func_021C9BEC((u16 *)p,a,b,0,((struct Obj02842 *)p)->f0,c);
        func_021C6DF8(b,1);
        func_021C9BF8(p,b,255);
        return 1;
    }
    offset=(value*256)/8;
    if(((struct Obj02842 *)p)->f8==2) offset=-offset;
    func_02040618(3,0,offset);
    ((struct Obj02842 *)p)->f4=((struct Obj02842 *)p)->f4+1;
    return 0;
}

static inline int absolute(s16 value) { if (value < 0) return -value; return value; }

/*
 * note 2026-10-05: the matched callees func_021C9ED0 and func_021C9EF4 declare 4 parameters,
 *   but this caller passes the heap id as a stack argument (5th for 9ED0, 6th for 9EF4); the
 *   prototypes below carry the real arity. The heap id is u16 here and in all callee prototypes
 *   (narrow param puts its home store first); the inner counter is long.
 */
void func_021C9628(u8 *p, void *unused, u8 *q, u16 heap)
{
    int i, k, x, y; long j;
    const s16 *row;
    func_021C9E10(p + 0xf8, q, heap);
    func_021C9E6C(p, q);
    for (k = 0; k < 2; k++) {
        row = d_021CA564[k];
        y = absolute(row[1]);
        x = absolute(row[0]);
        func_021C63AC(q, (u32 *)(p + 0x118 + k * 8), 3, (u8)(x + 2), y + 1, 26, 18, 10, 0, 0);
    }
    for (i = 0; i < 3; i++) {
        func_021C9ED0((u32)(p + 20 + i * 0x4c), (int)q, (const u16 *)d_021CA564[i], d_021CA538[i], heap);
        for (j = 0; j < 8; j++) {
            func_021C9EF4((u32)(p + 20 + i * 0x4c), (int)q, j, d_021CA521[j], d_021CA7E0[j], heap);
            *(void **)(p + 0x20 + j * 4) = p + 0x118;
            *(void **)(p + 0x6c + j * 4) = p + 0x120;
            *(void **)(p + 0xb8 + j * 4) = p + 0x120;
        }
    }
}

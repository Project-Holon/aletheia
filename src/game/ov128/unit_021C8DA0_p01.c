/*
 * file:     unit_021C8DA0_p01.c
 * unit:     yes
 * function: func_021C8DA0, func_021C8E2C
 * address:  0x021C8DA0
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
 *   func_0216BFD4 0x0216BFD4 thumb ov010
 *   func_02045924 0x02045924 arm
 *   func_021C8F88 0x021C8F88 thumb ov128
 *   func_021C9180 0x021C9180 thumb ov128
 *   func_021C8F2C 0x021C8F2C thumb ov128
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_0204B98C 0x0204B98C arm
 *   func_021C6438 0x021C6438 thumb ov128
 *   func_021C91CC 0x021C91CC thumb ov128
 *   func_021C9154 0x021C9154 thumb ov128
 */
#include "../../matched/include/Obj00227.h"
#include "../../matched/include/Obj03544.h"
#include "../../matched/include/Obj03813.h"

struct Big;
struct Sub020097BCObj;
struct BigObj;
struct Strbuf;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern char *func_0216BFD4(int,int,u32,u32,int,int,void *);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_021C8F88(void *,void *,void *,int);
extern void func_021C9180(char *p, char *q, char *r);
extern int func_021C8F2C(void *, int *);
extern void func_020061E4(u32 a);
extern void func_021CA3A0(char *p);
extern void func_021CA3C4(char *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021C6438(u8 *p, u8 a, u8 b);
extern void func_021C91CC(char *p, void *q);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern u32 func_020221A4(void);
extern void func_021C9154(char *p, int unused, char *q);
char *func_021C8DA0(void *unused,char *q,int mode,int heap);
void func_021C8E24(void *p,void *q,void *r,int s);
int func_021C8E2C(void *p, u8 *q, u8 *r, int heap);
void func_021C8F24(void *p, void *q, void *r);

char *func_021C8DA0(void *unused,char *q,int mode,int heap) {
 void *v;void *base;int idx;char *ret;unsigned kind;
 v=func_0200C0F0(func_02012EBC(((struct Obj00227 *)q)->f4));
 base=(void *)func_0201283C(((struct Obj00227 *)q)->f4);idx=*(u8 *)(q+24+*(signed char *)&((struct Obj00227 *)q)->fB);
 kind=func_02009864(base,idx,9);
 if(mode==1 || kind==2) ret=func_0216BFD4(heap,4,65535,0,7,0,v);
 else ret=func_0216BFD4(heap,4,func_02009864(base,idx,8),0,7,0,v);
 if(((struct Obj00227 *)q)->f64==1) {func_02045924(((struct Obj03544 *)ret)->f20,(const u16 *)(((struct Obj00227 *)q)->f60));((struct Obj00227 *)q)->f64=0;}
 return ret;
}

/*
 * extent: includes the eight-byte forwarding follower at 0x021C8E24.
 */
void func_021C8E24(void *p,void *q,void *r,int s) {
 func_021C8F88(p,q,r,s);
}

/*
 * extent: Includes the eight-byte forwarding follower at 0x021C8F24.
 */
int func_021C8E2C(void *p, u8 *q, u8 *r, int heap)
{
    int v;
    switch (q[8]) {
    case 0:
        func_021C8E24(p, q, r, 52);
        func_021C9180(p, (char *)q, (char *)r);
        q[8] = 1;
        break;
    case 1:
        v = func_021C8F2C(p, (int *)q);
        if (v == 0) {
            func_020061E4(0x551);
            func_021CA3A0((char *)r);
            q[8] = 2;
        } else if (v == 1) {
            func_020061E4(0x556);
            func_021CA3C4((char *)r);
            q[8] = 3;
        }
        break;
    case 2:
        if (func_0204B98C(((struct Obj03813 *)r)->f164) != 1) {
            func_021C6438(q, 0, 2);
            func_021C91CC(p, r);
            func_021C8F24(p, q, r);
            return 1;
        }
        break;
    case 3:
        if (func_0204B98C(((struct Obj03813 *)r)->f168) != 1) q[8] = 4;
        break;
    case 4:
        func_0202208C(0, 0, 0, 0, 6, 1, heap);
        q[8] = 5;
        break;
    case 5:
        if (func_020221A4() == 1) {
            func_021C6438(q, 6, 0);
            func_021C8F24(p, q, r);
            return 1;
        }
        break;
    }
    return 0;
}

void func_021C8F24(void *p, void *q, void *r)
{
    func_021C9154(p, (int)q, r);
}

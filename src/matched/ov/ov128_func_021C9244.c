/*
 * function: func_021C9244
 * address: 0x021C9244
 * packet: pkt_ov128_021C9244
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed halfword switch offsets map cases 0 and 1 to a shared
 * setup tail; case 0 clears the two halfwords before falling through.
 * symbols:
 *   func_021C9238 0x021C9238 thumb ov128
 *   func_021C97A0 0x021C97A0 thumb ov128
 *   func_021C9544 0x021C9544 thumb ov128
 *   func_021C958C 0x021C958C thumb ov128
 *   func_021C95CC 0x021C95CC thumb ov128
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
 */
#include "../include/Obj00773.h"
#include "../include/Obj10491.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C9238(char *p, void *b, void *c, void *d);
extern void func_021C97A0(u8 *,u8 *,u8 *,u16);
extern int func_021C9544(void *,int *,char *);
extern void func_021C958C(char *,void *,void *,int);
extern int func_021C95CC(u8 *,void *,void *,int);
struct Actor;
struct PrintSys;
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

/*
 * unit: yes
 * function: func_021D0D50, func_021D0E74
 * address: 0x021D0D50
 * packet: pkt_ov093_021D0D50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to func_021CE1B0;
 * included in this complete 300-byte unit after parent ownership audit.
 * symbols:
 *   func_021CE1B0 0x021CE1B0 thumb ov093
 *   func_021D0C78 0x021D0C78 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021CFD50 0x021CFD50 thumb ov093
 *   func_021D09E0 0x021D09E0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021D1058 0x021D1058 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021D102C 0x021D102C thumb ov093
 *   func_021D83C4 0x021D83C4 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 */
#include "../include/Obj01236.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D0C78(void *,u8 *);
extern u8 func_021D0980(u8 *,u8 *);
extern u8 *func_021CFD50(void *,int);
extern void func_021D09E0(void *,u8 *,u8,void *);
extern u32 func_021B8588(void **);
extern int func_021D1058(u8 *,void *);
extern void func_021B8E28(u8 *,u8,u8 *,u8 *);
extern void func_021D8394(void *,u8,u8);
extern int func_021D102C(u8 *);
extern void func_021D83C4(void *);
extern void func_021D8434(void *);
int func_021D0D50(u8 *p)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    p[0x1b3] = func_021D0C78(p,p+0x1b5);
    if (p[0x1b3]) {
        n = func_021D0980(p,order);
        if (n) {
            count = p[0x1b3];
            target = func_021CFD50(p,p[0x1b5]);
            if (target) func_021D09E0(p,order,n,target);
            if (count > n) {
                if (func_021B8588(*(void ** *)&((struct Obj01236 *)p)->f0) == 3) {
                    result = func_021D1058(p,p+0x124);
                    if (result) {
                        *(int *)&((struct Obj01236 *)p)->fDC = result;
                        ((struct Obj01236 *)p)->fD8 = p+0x124;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                func_021B8E28(*(u8 * *)&((struct Obj01236 *)p)->f0,p[0x1b5+i],pair,pair+1);
                func_021D8394(p+0x124+i*4,pair[1],order[i]);
            }
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = count*4;
        } else {
            if (func_021D102C(p)) {
                result = func_021D1058(p,p+0x124);
                if (result) {
                    *(int *)&((struct Obj01236 *)p)->fDC = result;
                    ((struct Obj01236 *)p)->fD8 = p+0x124;
                    return 1;
                }
            }
            func_021D83C4(p+0x124);
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = 4;
        }
    } else {
        func_021D8434(p+0x124);
        ((struct Obj01236 *)p)->fD8 = p+0x124;
        ((struct Obj01236 *)p)->fDC = 4;
    }
    return 1;
}

extern int func_021CE1B0(u8 *,int *);
int func_021D0E74(u8 *p,int *state)
{
    return func_021CE1B0(p,state);
}

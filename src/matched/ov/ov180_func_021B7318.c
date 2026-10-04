/*
 * function: func_021B7318
 * address: 0x021B7318
 * packet: pkt_ov180_021B7318
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B827C 0x021B827C data a4
 *   d_021B8298 0x021B8298 data a4
 *   func_021B61FC 0x021B61FC thumb ov180
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_02025538 0x02025538 thumb
 *   func_021B74C8 0x021B74C8 thumb ov180
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
#include "../include/Obj00547.h"
typedef struct { unsigned words[7]; } Config;
extern const Config d_021B827C,d_021B8298;
extern int func_021B61FC(int);
extern void func_0204A48C(Config *,int,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_021B74C8(int *);
extern void func_020434DC(unsigned,unsigned);
extern void func_02043598(unsigned,unsigned);
void func_021B7318(char *p,int mode) {
    if(mode==0) {
        Config cfg=d_021B827C;
        func_0204A48C(&cfg,func_021B61FC(mode),141);
    } else {
        Config cfg=d_021B8298;
        func_0204A48C(&cfg,func_021B61FC(mode),141);
    }
    *(int *)&((struct Obj00547 *)p)->f9044=(int)func_0204B100(249,0,141);
    ((struct Obj00547 *)p)->f911C=func_02025538(141,((struct Obj00547 *)p)->f9044);
    func_021B74C8((int *)p);
    func_020434DC(16,1); func_02043598(16,1);
}

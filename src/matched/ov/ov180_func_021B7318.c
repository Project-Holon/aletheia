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
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_021B74C8 0x021B74C8 thumb ov180
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj00547.h"
typedef struct { unsigned words[7]; } Config;
extern const Config d_021B827C,d_021B8298;
extern int func_021B61FC(int);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void func_021B74C8(int *);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
void func_021B7318(char *p,int mode) {
    if(mode==0) {
        Config cfg=d_021B827C;
        CLACT_InitSystem((const struct Cfg *)(&cfg),func_021B61FC(mode),141);
    } else {
        Config cfg=d_021B8298;
        CLACT_InitSystem((const struct Cfg *)(&cfg),func_021B61FC(mode),141);
    }
    *(int *)&((struct Obj00547 *)p)->f9044=(int)CLACT_CreateUnit(249,0,141);
    ((struct Obj00547 *)p)->f911C=BMP_OAM_CreateSys(141,((struct Obj00547 *)p)->f9044);
    func_021B74C8((int *)p);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
}

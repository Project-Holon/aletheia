/*
 * function: func_021E0CC0
 * address: 0x021E0CC0
 * packet: pkt_ov119_021E0CC0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_021E106C 0x021E106C thumb ov119
 *   func_021E57A4 0x021E57A4 thumb ov119
 *   func_021E53CC 0x021E53CC thumb ov119
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021E467C 0x021E467C thumb ov119
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021E3F74 0x021E3F74 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DACE4 0x021DACE4 thumb ov119
 */
#include "../include/Obj02828.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
struct Bank;
extern u32 WIPE_SYS_EndCheck(void);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void func_021E106C(char *p);
extern void func_021E57A4(int);
extern void func_021E53CC(int p);
extern void func_021E57E8(int);
extern void func_021E5680(char *p);
extern void func_021E58A0(int);
extern void func_021E467C(char *p);
extern void func_021E4420(char *p);
extern void func_021E3E80(char *);
extern void func_021E3FE4(char *p);
extern void func_021E3F74(char *p);
extern void func_021E3208(void *,int);
extern void func_021E3C20(char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_021D8E84(void *,int);
extern void func_021DACE4(char *p);
void func_021E0CC0(char *p)
{
    if(((struct Obj02828 *)p)->fF2C>=6 && WIPE_SYS_EndCheck()) {
        if(((struct Obj02828 *)p)->f644) func_0203FB44((int)6,(u16)(((struct Obj02828 *)p)->f644),(u16)(((struct Obj02828 *)p)->f644>>16));
        *(int *)&((struct Obj02828 *)p)->f644=0;
        BG_SYS_SetMainVisiblePlanes((int)0);BG_SYS_SetSubVisiblePlanes((int)0);
        CLACT_DeleteUnit(((struct Obj02828 *)p)->f9C4);
        ((struct Obj02828 *)p)->f9C4=CLACT_CreateUnit(0x154,0,((struct Obj02828 *)p)->f5F4);
        func_021E106C(p);func_021E57A4((int)p);func_021E53CC((int)p);
        func_021E57E8(0);func_021E5680(p);func_021E58A0((int)p);
        func_021E467C(p);func_021E4420(p);func_021E3E80(p);
        func_021E3FE4(p);func_021E3F74(p);func_021E3208(p,0);
        BG_SYS_SetMainVisiblePlanes((int)31);BG_SYS_SetSubVisiblePlanes((int)30);func_021E3C20(p);
        GFL_NET_RestartWithDefaultTimeout(1,((struct Obj02828 *)p)->f5F4);
        ((struct Obj02828 *)p)->f11FA=0;
        func_021D8E84(p,(int)func_021DACE4);
    }
}

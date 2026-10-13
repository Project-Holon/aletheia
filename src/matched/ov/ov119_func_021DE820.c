/*
 * unit: yes
 * function: func_021DE820, func_021DE8C0
 * address: 0x021DE820
 * packet: pkt_ov119_021DE820
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021DE89A reads 0x04001000 before the store at 0x021DE89E.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021DC720 0x021DC720 thumb ov119
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021E467C 0x021E467C thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021E3F74 0x021E3F74 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02043534 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DACE4 0x021DACE4 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021DE820 0x021DE820 thumb ov119
 */
#include "../include/Obj00001.h"
#include "../include/Obj00252.h"

typedef unsigned short u16;
extern unsigned int WIPE_SYS_EndCheck(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern void func_021DC720(char *p);
extern void func_021E57E8(int);
extern void func_021E5680(char *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void func_021E10D8(char *p);
extern void func_021E58A0(int p);
extern void func_021E467C(char *p);
extern void func_021E3E80(char *p);
extern void func_021E3FE4(char *p);
extern void func_021E3F74(char *p);
extern void func_021E3208(void *,int);
extern void func_02043534(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_021E3C20(char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_021D8E84(void *,int);
extern void func_021DACE4(char *p);
void func_021DE820(char *p)
{
    if(WIPE_SYS_EndCheck()) {
        func_021DC720(p); func_021E57E8(0); func_021E5680(p);
        ((struct Obj00252 *)p)->f9C4=CLACT_CreateUnit(0x154,0,((struct Obj00252 *)p)->f5F4);
        func_021E10D8(p); func_021E58A0((int)p); func_021E467C(p);
        func_021E3E80(p); func_021E3FE4(p); func_021E3F74(p);
        func_021E3208(p,0); func_02043534(31); BG_SYS_SetSubVisiblePlanes(30);
        func_021E3C20(p); GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00252 *)p)->f5F4);
        *(volatile unsigned *)0x04001000 &= 0xffff1fff;
        func_021D8E84(p,(int)func_021DACE4);
    }
}

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int func_021E12AC(char *p);
extern int func_021DD140(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void func_021DE8C0(char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(func_021E12AC(p) && func_021DD140(p) && ((struct Obj00001 *)p)->fF2C>=120) {
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
        func_021D8E84(p,(int)func_021DE820);
    }
}

/*
 * function: func_021D9958
 * address: 0x021D9958
 * packet: pkt_ov123_021D9958
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: ov123 021D9D34 callback stub filed and verified before caller rerun.
 * volatile: hardware register 04001000 is read then written at 021D9990/021D9994.
 * symbols:
 *   ov067_id 0x00000043 data
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D9AE8 0x021D9AE8 thumb ov123
 *   func_021D9D3C 0x021D9D3C thumb ov123
 *   func_021D9D34 0x021D9D34 thumb ov123
 *   d_021DABFC 0x021DABFC data a1
 *   d_021DABCC 0x021DABCC data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DABBC 0x021DABBC data a4
 */
#include "../include/Obj05370.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern const char d_021DABFC[];
extern char ov067_id[];
extern const u32 d_021DABCC[];
extern const u32 d_020A1464[];
extern const u32 d_021DABBC[];
typedef unsigned char  u8;
struct Bank;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02034AC4(int);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void GX_DispOn(void);
extern void func_0203F8F4(u16 heapId);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021D9AE8(void *);
extern void func_021D9D3C(char *p);
extern void func_021D9D34(void);
extern void *func_020056A0(void *,void *,int);
char *func_021D9958(int heap)
{
    char *p;
    p=func_02030734(heap,0xb70,1,d_021DABFC,201);
    ((struct Obj05370 *)p)->f9E4=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    func_0203F8F4(((struct Obj05370 *)p)->f9E4);
    CLACT_InitSystem((const struct Cfg *)d_020A1464,(u32)d_021DABCC,((struct Obj05370 *)p)->f9E4);
    ((struct Obj05370 *)p)->f97C=CLACT_CreateUnit(40,0,((struct Obj05370 *)p)->f9E4);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DABCC);
    func_0203FC28((struct DispConfig *)d_021DABBC);
    func_021D9AE8(p);
    func_021D9D3C(p);
    ((struct Obj05370 *)p)->f980=func_020056A0(func_021D9D34,p,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(27);
    return p;
}

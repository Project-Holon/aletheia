/*
 * function: func_021D9158
 * address: 0x021D9158
 * packet: pkt_ov123_021D9158
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_021D5D58 0x021D5D58 thumb ov123
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021D8F58 0x021D8F58 thumb ov123
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_021D5D7C 0x021D5D7C thumb ov123
 *   func_021D5E60 0x021D5E60 thumb ov123
 *   func_021D562C 0x021D562C thumb ov123
 *   func_0200FB24 0x0200FB24 thumb
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 */
#include "../include/Obj01406.h"
#include "../include/Obj22983.h"
typedef unsigned char u8;
extern unsigned int func_020221A4(void);
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern int func_021D5D58(char *p);
extern void func_021B9774(u8 *p);
extern void GAME_DATA_SaveCancel(char *p);
extern void func_021D8F58(char *);
extern void func_0200F7C0(u32 value);
extern void func_0202223C(u32 a, u32 color);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void func_02027974(void *);
extern void func_021D5D7C(char *p);
extern void func_021D5E60(u8 *p);
extern void func_021D562C(char *p);
int func_021D9158(void *a, int b, int c, char *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))(p+0x50);
    result=1;
    if (func_020221A4() && !((struct Obj01406 *)p)->fAE && func_0200FB24()) {
        if (((struct Obj01406 *)p)->f8) func_021D5D58(((struct Obj01406 *)p)->f8);
        func_021B9774(((struct Obj01406 *)p)->f10);
        if (((struct Obj01406 *)p)->fAD) {
            GAME_DATA_SaveCancel(((struct Obj01406 *)p)->f2C);
            ((struct Obj01406 *)p)->fAD=0;
        }
        func_021D8F58(p);
        if (((struct Obj01406 *)p)->fAB) func_0200F7C0(41);
        func_0202223C(0,0);
        func_0202223C(1,0);
        DWC_RAPCOMMON_HandleNetError(1,0);
        ((struct Obj22983 *)(*(char * *)&((struct Obj01406 *)p)->f20))->f1C8=7;
        return 1;
    }
    if (callback) { callback(p); result=0; }
    if (((struct Obj01406 *)p)->f1C) func_02027974(((struct Obj01406 *)p)->f1C);
    if (((struct Obj01406 *)p)->f8) func_021D5D7C(((struct Obj01406 *)p)->f8);
    func_021D5E60(((struct Obj01406 *)p)->f14);
    func_021D562C(((struct Obj01406 *)p)->f18);
    return result;
}

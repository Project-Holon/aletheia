/*
 * function: func_0221268C
 * address: 0x0221268C
 * packet: pkt_ov199_0221268C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0221372C 0x0221372C thumb ov199
 *   func_022133D0 0x022133D0 thumb ov199
 *   BATTLE_REC_FreeWork 0x0200B424 thumb
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_Delete 0x02012704 thumb
 *   OS_ResetSystem 0x02087BCC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 */
#include "../include/Obj03352.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct S020315D4;
extern void func_0221372C(char *p);
extern void func_022133D0(u8 *p);
extern void BATTLE_REC_FreeWork(void);
extern u32 func_020307B0(void *p);
extern void GAME_DATA_Delete(u8 *p);
extern void OS_ResetSystem(u32 parameter);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
extern void GFL_USE_CancelChangeAndStopBgm(void);
int func_0221268C(void *sys, int unused, void *data, char *p)
{
    func_0221372C(((struct Obj03352 *)p)->f18);
    func_022133D0((u8 *)p);
    BATTLE_REC_FreeWork();
    func_020307B0(((struct Obj03352 *)p)->f3C);
    func_020307B0(((struct Obj03352 *)p)->f38);
    func_020307B0(((struct Obj03352 *)p)->f34);
    func_020307B0(((struct Obj03352 *)p)->f30);
    if (((struct Obj03352 *)p)->f0) GAME_DATA_Delete(((struct Obj03352 *)p)->f4);
    if (((struct Obj03352 *)p)->fC != 1) OS_ResetSystem(0);
    if (((struct Obj03352 *)p)->f14) func_020307B0(data);
    func_020315D4(sys);
    func_020306F0(0x56);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}

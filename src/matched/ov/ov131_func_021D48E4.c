/*
 * function: P_STATUS_ExitGraphics
 * address: 0x021D48E4
 * packet: pkt_ov131_021D48E4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * 2026-10-02 R3: closed by the arm9 witness src/matched/arm9/NNS_GfdResetVramTransferTaskQueue.c
 *   (the tail-call stub matches under ../2.0/sp2; see its header).
 * extent: Two zero padding bytes at 0x021D493E.
 * symbols:
 *   NNS_GfdResetVramTransferTaskQueue 0x02061C30 arm
 *   MCSS_Exit 0x02014BA8 thumb
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
#include "../include/Obj10503.h"
extern void NNS_GfdResetVramTransferTaskQueue(void);
typedef unsigned char  u8;
struct Bank;
extern void MCSS_Exit(u8 *a0);
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_020403F4(unsigned int);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
void P_STATUS_ExitGraphics(char *p)
{
    NNS_GfdResetVramTransferTaskQueue();
    MCSS_Exit(((struct Obj10503 *)p)->f78);
    G3D_CAMERA_Delete(((struct Obj10503 *)p)->f70);
    G3D_SYSTEM_Exit();
    CLACT_DeleteUnit(((struct Obj10503 *)p)->f174);
    CLACT_ExitSystem();
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    BMP_WIN_Exit();
    func_0203F9B4();
}

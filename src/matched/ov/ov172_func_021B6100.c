/*
 * function: CTVT_CAMERA_Create
 * address: 0x021B6100
 * packet: pkt_ov172_021B6100
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   UI_SetKeepAwakeFlagsGlobal 0x02034F84 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   OS_Terminate 0x02088234 arm
 *   OS_EnableIrqMask 0x02084968 arm
 *   func_020351F8 0x020351F8 arm
 *   func_021B62A8 0x021B62A8 arm ov172
 *   func_021B62B0 0x021B62B0 arm ov172
 *   func_021B62B8 0x021B62B8 arm ov172
 *   func_021B62C0 0x021B62C0 arm ov172
 *   func_021B62C8 0x021B62C8 arm ov172
 *   func_021B62D0 0x021B62D0 arm ov172
 *   func_021B62D8 0x021B62D8 arm ov172
 *   func_021B62E0 0x021B62E0 arm ov172
 *   func_021B62E8 0x021B62E8 arm ov172
 *   func_021B62F0 0x021B62F0 arm ov172
 *   func_021B62F8 0x021B62F8 arm ov172
 *   func_021B6300 0x021B6300 arm ov172
 *   func_021B6308 0x021B6308 arm ov172
 *   func_021B6310 0x021B6310 arm ov172
 *   func_021B6318 0x021B6318 arm ov172
 *   func_021B6320 0x021B6320 arm ov172
 *   func_021B6328 0x021B6328 arm ov172
 *   func_021B6330 0x021B6330 arm ov172
 *   CTVT_CAMERA_ResetTrimming 0x021B68A0 thumb ov172
 *   CTVT_CAMERA_OnPowerOff 0x021B6338 thumb ov172
 *   CTVT_CAMERA_OnBufferError 0x021B65D8 thumb ov172
 *   CTVT_CAMERA_OnReboot 0x021B6620 thumb ov172
 *   CTVT_CAMERA_OnVsync 0x021B662C thumb ov172
 *   d_021C71C0 0x021C71C0 data a4
 *   g_021C88E0 0x021C88E0 data a4
 */
#include "../include/Obj00917.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void UI_SetKeepAwakeFlagsGlobal(int);
extern int OS_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void OS_EnableIrqMask(int);
extern void func_020351F8(u32 a, u32 b);
extern int func_021B62A8(void);
extern int func_021B62B0(int);
extern void func_021B62B8(int, int, int);
extern void func_021B62C0(int, int);
extern void func_021B62C8(int, int);
extern int func_021B62D0(int);
extern void func_021B62D8(void *);
extern void func_021B62E0(void *);
extern void func_021B62E8(void *);
extern void func_021B62F0(int);
extern void func_021B62F8(int, int);
extern void func_021B6300(int, int);
extern void func_021B6308(int, int);
extern void func_021B6310(int, int);
extern void func_021B6318(int, int);
extern void func_021B6320(int, int);
extern void func_021B6328(void *);
extern int func_021B6330(void *, int, int);
extern void CTVT_CAMERA_ResetTrimming(char *);
extern void CTVT_CAMERA_OnPowerOff(char *p);
extern void CTVT_CAMERA_OnBufferError(void);
extern void CTVT_CAMERA_OnReboot(int x);
extern void CTVT_CAMERA_OnVsync(void);
extern const char d_021C71C0[];
extern char *g_021C88E0;

char *CTVT_CAMERA_Create(int id)
{
    char *p;
    int r;
    int z;
    char buf[0x48];

    z = 0;
    p = func_02030734(id, 0x50, 0, d_021C71C0, 0x6F);
    g_021C88E0 = p;
    ((struct Obj00917 *)p)->f0 = id;
    ((struct Obj00917 *)p)->f4 = z;
    ((struct Obj00917 *)p)->f18 = z;
    ((struct Obj00917 *)p)->f8 = z;
    ((struct Obj00917 *)p)->fC = z;
    ((struct Obj00917 *)p)->f10 = z;
    ((struct Obj00917 *)p)->f14 = z;
    ((struct Obj00917 *)p)->f2C = 1;
    ((struct Obj00917 *)p)->f30 = 5;
    ((struct Obj00917 *)p)->f1C = z;
    ((struct Obj00917 *)p)->f20 = z;
    ((struct Obj00917 *)p)->f24 = z;
    ((struct Obj00917 *)p)->f3C = z;
    ((struct Obj00917 *)p)->f40 = z;
    UI_SetKeepAwakeFlagsGlobal(0x40);
    if (OS_IsRunOnTwl() == 1) {
        r = func_021B62A8();
        if (r == 0) r = func_021B62B0(3);
    } else {
        r = 7;
    }
    if (r == 7) OS_Terminate();
    if (r == 6) return 0;
    r = ((struct Obj00917 *)p)->f2C;
    if (OS_IsRunOnTwl() == 1) func_021B62B8(r, 3, 0);
    r = ((struct Obj00917 *)p)->f2C;
    if (OS_IsRunOnTwl() == 1) func_021B62C0(r, 1);
    r = ((struct Obj00917 *)p)->f2C;
    if (OS_IsRunOnTwl() == 1) func_021B62C8(r, 1);
    r = ((struct Obj00917 *)p)->f2C;
    if (OS_IsRunOnTwl() == 1) r = func_021B62D0(r);
    else r = 7;
    if (r == 7) OS_Terminate();
    if (r == 6) return 0;
    ((struct Obj00917 *)p)->f28 = 0;
    OS_EnableIrqMask(0x20000000);
    if (OS_IsRunOnTwl() == 1) func_021B62D8((void *)CTVT_CAMERA_OnVsync);
    if (OS_IsRunOnTwl() == 1) func_021B62E0((void *)CTVT_CAMERA_OnBufferError);
    if (OS_IsRunOnTwl() == 1) func_021B62E8((void *)CTVT_CAMERA_OnReboot);
    CTVT_CAMERA_ResetTrimming(p);
    if (OS_IsRunOnTwl() == 1) func_021B62F0(1);
    ((struct Obj00917 *)p)->f48 = 0;
    ((struct Obj00917 *)p)->f44 = 0;
    func_021B62F8(1, 0);
    func_021B6300(1, 0);
    func_021B6308(1, 1);
    func_021B6310(2, 0);
    func_021B6318(2, 0);
    func_021B6320(2, 1);
    if (OS_IsRunOnTwl() != 0) func_021B6328(buf);
    if (OS_IsRunOnTwl() != 0) r = func_021B6330(buf, 0xFF, 0xFF);
    else r = 0;
    if (r == 0) OS_Terminate();
    func_020351F8((u32)((void *)CTVT_CAMERA_OnPowerOff), (u32)p);
    return p;
}

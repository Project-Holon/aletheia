/*
 * function: CTVT_CAMERA_StartFrameDma
 * address: 0x021B644C
 * packet: pkt_ov172_021B644C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CTVT_CAMERA_GetWidth 0x021B6938 thumb ov172
 *   CTVT_CAMERA_GetHeight 0x021B6944 thumb ov172
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B649C 0x021B649C arm ov172
 *   func_021B64A4 0x021B64A4 arm ov172
 *   CTVT_CAMERA_OnFrameDmaDone 0x021B66B0 thumb ov172
 */
#include "../include/Obj01264.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 CTVT_CAMERA_GetWidth(void *);
extern u16 CTVT_CAMERA_GetHeight(void *);
extern int OS_IsRunOnTwl(void);
extern u32 func_021B649C(u32);
extern void func_021B64A4(int, u32, u32, u32, int, void (*)(void), int);
extern void CTVT_CAMERA_OnFrameDmaDone(void);
void CTVT_CAMERA_StartFrameDma(char *p)
{
    u32 width = CTVT_CAMERA_GetWidth(p);
    u32 height = CTVT_CAMERA_GetHeight(p);
    u32 offset = OS_IsRunOnTwl() == 1 ? func_021B649C(width) : 0;
    width *= 2;
    func_021B64A4(1, (*(u32 **)(p + 4))[((struct Obj01264 *)p)->f18], offset >> 2,
                 width * height, 0, CTVT_CAMERA_OnFrameDmaDone, 0);
}

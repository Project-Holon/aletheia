/*
 * function: CTVT_CAMERA_ResetTrimming
 * address: 0x021B68A0
 * packet: pkt_ov172_021B68A0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: initialize the result after the guards, before the descriptor stores.
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B6918 0x021B6918 arm ov172
 *   func_021B6920 0x021B6920 arm ov172
 *   func_021B6928 0x021B6928 arm ov172
 *   func_021B6930 0x021B6930 arm ov172
 *   CTVT_CAMERA_GetSizeWidth 0x021B697C thumb ov172
 *   CTVT_CAMERA_GetSizeHeight 0x021B699C thumb ov172
 *   CTVT_CAMERA_GetWidth 0x021B6938 thumb ov172
 *   CTVT_CAMERA_GetHeight 0x021B6944 thumb ov172
 */
#include "../include/Obj01264.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern int OS_IsRunOnTwl(void);
extern int func_021B6918(void);
extern void func_021B6920(int);
extern int func_021B6928(u32, u32);
extern void func_021B6930(int);
extern int CTVT_CAMERA_GetSizeWidth(void *);
extern int CTVT_CAMERA_GetSizeHeight(void *);
extern u16 CTVT_CAMERA_GetWidth(void *);
extern u16 CTVT_CAMERA_GetHeight(void *);
void CTVT_CAMERA_ResetTrimming(char *p)
{
    int result;
    u32 width;
    u32 height;
    if (((struct Obj01264 *)p)->f10 != 0) return;
    if ((OS_IsRunOnTwl() == 1 ? func_021B6918() : 0) != 0) return;
    if (OS_IsRunOnTwl() == 1) func_021B6920(0);
    result = 0;
    ((struct Obj01264 *)p)->f34 = 0;
    ((struct Obj01264 *)p)->f36 = CTVT_CAMERA_GetSizeWidth(p);
    ((struct Obj01264 *)p)->f38 = 0;
    ((struct Obj01264 *)p)->f3A = CTVT_CAMERA_GetSizeHeight(p);
    width = CTVT_CAMERA_GetWidth(p);
    height = CTVT_CAMERA_GetHeight(p);
    if (OS_IsRunOnTwl() == 1) result = func_021B6928(width, height);
    if (OS_IsRunOnTwl() == 1) func_021B6930(result);
    ((struct Obj01264 *)p)->f14 = 0;
}

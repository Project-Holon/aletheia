/*
 * function: CTVT_CAMERA_UpdateShutterSound
 * address: 0x021B64AC
 * packet: pkt_ov172_021B64AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status:   EXACT*
 * note: 2026-10-02 byte-correct; the four arm veneers 021B655C..021B6574 are filed as matched asm files (no shards yet), so the blx sites are unresolved until the integrator manifests them.
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   CTVT_CAMERA_LoadShutterSound 0x021B657C thumb ov172
 *   CTVT_CAMERA_FreeShutterSound 0x021B65C4 thumb ov172
 *   func_021B655C 0x021B655C arm ov172
 *   func_021B6564 0x021B6564 arm ov172
 *   func_021B656C 0x021B656C arm ov172
 *   func_021B6574 0x021B6574 arm ov172
 */
#include "../include/Obj01559.h"
extern int OS_IsRunOnTwl(void);
extern void CTVT_CAMERA_LoadShutterSound(char *, int);
extern void CTVT_CAMERA_FreeShutterSound(void *p);
extern void func_021B655C(int, int);
extern int func_021B6564(void);
extern void func_021B656C(int, int);
extern int func_021B6574(void);

void CTVT_CAMERA_UpdateShutterSound(char *p)
{
    int b;
    int a;
    int d;
    int c;
    int r;
    switch (((struct Obj01559 *)p)->f44) {
    case 1:
        CTVT_CAMERA_LoadShutterSound(p, 1);
        a = *(int *)&((struct Obj01559 *)p)->f4C;
        b = *(int *)&((struct Obj01559 *)p)->f48;
        if (OS_IsRunOnTwl() != 0) func_021B655C(b, a);
        ((struct Obj01559 *)p)->f44 = 2;
        break;
    case 2:
        r = 0;
        if (OS_IsRunOnTwl() != 0) r = func_021B6564();
        if (r == 0) {
            CTVT_CAMERA_FreeShutterSound(p);
            ((struct Obj01559 *)p)->f44 = 3;
        }
        break;
    case 4:
        CTVT_CAMERA_LoadShutterSound(p, 0);
        c = *(int *)&((struct Obj01559 *)p)->f4C;
        d = *(int *)&((struct Obj01559 *)p)->f48;
        if (OS_IsRunOnTwl() != 0) func_021B656C(d, c);
        ((struct Obj01559 *)p)->f44 = 5;
        break;
    case 5:
        r = 0;
        if (OS_IsRunOnTwl() != 0) r = func_021B6574();
        if (r == 0) {
            CTVT_CAMERA_FreeShutterSound(p);
            ((struct Obj01559 *)p)->f44 = 6;
        }
        break;
    case 0:
    case 3:
    case 6:
    default:
        break;
    }
}

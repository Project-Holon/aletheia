/*
 * function: CTVT_CAMVIEW_Delete
 * address: 0x021B70A8
 * packet: pkt_ov172_021B70A8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FX_Inv 0x0207C778 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_020307B0 0x020307B0 arm
 *   COMM_TVT_SYS_IsNetIdle 0x021BE100 thumb ov172
 *   CTVT_CAMERA_Delete 0x021B63B8 thumb ov172
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj04550.h"
extern int FX_Inv(int);
extern void func_0207D59C(void *, int *, int, int, int, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern int COMM_TVT_SYS_IsNetIdle(void);
extern void CTVT_CAMERA_Delete(char *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
void CTVT_CAMVIEW_Delete(int unused, char *q)
{
    int matrix[4];
    matrix[0] = FX_Inv(4096);
    matrix[3] = FX_Inv(4096);
    matrix[1] = 0;
    matrix[2] = 0;
    func_0207D59C((void *)0x04000030, matrix, 0, 0, 0, 0);
    func_020307B0(((struct Obj04550 *)q)->f4);
    func_020307B0(((struct Obj04550 *)q)->fC);
    func_020307B0(((struct Obj04550 *)q)->f8);
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        func_020307B0(((struct Obj04550 *)q)->fB0);
        func_020307B0(((struct Obj04550 *)q)->fA8);
        func_020307B0(((struct Obj04550 *)q)->fAC);
        CTVT_CAMERA_Delete(((struct Obj04550 *)q)->fA4);
        GFL_HEAP_DeleteChecked(110);
    }
    func_020307B0(q);
}

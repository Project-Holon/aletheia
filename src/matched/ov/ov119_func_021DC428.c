/*
 * function: func_021DC428
 * address: 0x021DC428
 * packet: pkt_ov119_021DC428
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   MCSS_Exit 0x02014BA8 thumb
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */
#include "../include/Obj00001.h"
extern void func_021E36D8(void *, int);
typedef unsigned char  u8;
extern void MCSS_Exit(u8 *a0);
typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
void func_021DC428(char *p)
{
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    MCSS_Exit(((struct Obj00001 *)p)->f840);
    ((struct Obj00001 *)p)->f840 = 0;
    G3D_CAMERA_Delete(((struct Obj00001 *)p)->f810);
    G3D_SYSTEM_Exit();
}

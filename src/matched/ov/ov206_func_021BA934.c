/*
 * unit: yes
 * function: ZUKAN_INFO_DeleteWindows
 * address: 0x021BA934
 * packet: pkt_ov206_021BA934
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00173.h"
struct Descriptor;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void ZUKAN_INFO_DeleteWindows(char *p)
{
    int i;
    PRINTSYS_QUE_Clear(((struct Obj00173 *)p)->f2C);
    for(i=0;i<4;i++){
        *(int *)(p+i*4+124)=1;
        BMP_WIN_Delete(*(void **)(p+i*4+108));
    }
    func_020307B0(((struct Obj00173 *)p)->f2B0);
}

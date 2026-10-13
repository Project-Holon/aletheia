/*
 * function: func_021E2054
 * address: 0x021E2054
 * packet: pkt_ov119_021E2054
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00001.h"
extern void func_021E36D8(void *, int);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021E2054(char *p, void *a, int b, int a3)
{
    func_021E36D8(p, b);
    if (((struct Obj00001 *)p)->f6B4) {
        BMP_WIN_Delete(((struct Obj00001 *)p)->f6B4);
    }
}

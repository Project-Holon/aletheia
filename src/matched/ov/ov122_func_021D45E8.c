/*
 * function: INTRUDE_COMM_VIEW_DeleteRows
 * address: 0x021D45E8
 * packet: pkt_ov122_021D45E8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes after the return, next function 021D4630.
 * symbols:
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj02472.h"
#include "../include/Obj06456.h"
extern void BUTTON_MAN_Delete(void *);
typedef unsigned int   u32;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_0201F7A8(void *, unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void INTRUDE_COMM_VIEW_DeleteRows(char *p)
{
    int i;
    char *q;
    if (((struct Obj02472 *)p)->f40) BUTTON_MAN_Delete(((struct Obj02472 *)p)->f40);
    *(int *)&((struct Obj02472 *)p)->f40 = 0;
    for (i = 0; i < 11; i++) {
        q = p + i * 4;
        if (((struct Obj06456 *)q)->f10) {
            BMP_WIN_ClearScreen(((struct Obj06456 *)q)->f10);
            func_02041B6C(5);
            func_0201F7A8(((struct Obj06456 *)q)->f10, 2);
            BMP_WIN_Delete(((struct Obj06456 *)q)->f10);
        }
        *(int *)&((struct Obj06456 *)q)->f10 = 0;
    }
    ((struct Obj02472 *)p)->f348 = 0;
}

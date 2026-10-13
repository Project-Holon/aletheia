/*
 * function: IRCBATTLEMENU_DeleteButtonWindows
 * address:  0x02196454
 * packet:   pkt_ov021_02196454
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj03578.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Descriptor;
extern void BUTTON_MAN_Delete(void *p);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 a);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void IRCBATTLEMENU_DeleteButtonWindows(u8 *p)
{
    int i;

    if (((struct Obj03578 *)p)->f24 != 0)
        BUTTON_MAN_Delete((void *)(((struct Obj03578 *)p)->f24));
    ((struct Obj03578 *)p)->f24 = 0;
    for (i = 0; i < 4; i++) {
        u32 *q = (u32 *)p + i;
        if (q[5] != 0) {
            BMP_WIN_ClearScreen((struct Descriptor *)q[5]);
            func_02041B6C(5);
            func_0201F7A8((void *)q[5], 2);
            BMP_WIN_Delete((struct Descriptor *)q[5]);
        }
        q[5] = 0;
    }
    ((struct Obj03578 *)p)->f2F4 = 0;
}

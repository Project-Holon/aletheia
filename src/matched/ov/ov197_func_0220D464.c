/*
 * function: B_BAG_MAIN_StateOtherFlow
 * address: 0x0220D464
 * packet: pkt_ov197_0220D464
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_FINGER_CURSOR_IsActive 0x02209C2C thumb
 *   B_BAG_MAIN_PlaySe 0x0220D89C thumb ov197
 *   B_BAG_MAIN_StartFrameAnim 0x0220BF20 thumb ov197
 *   B_BAG_MAIN_StateShowPocket1 0x0220D234 thumb ov197
 *   B_BAG_MAIN_StateShowPocket2 0x0220D254 thumb ov197
 *   B_BAG_MAIN_GetSlotItem 0x0220BB98 thumb ov197
 *   B_BAG_MAIN_StateShowMessage 0x0220D11C thumb ov197
 */
#include "../include/Obj00688.h"
#include "../include/Obj25098.h"
#include "../include/Obj25099.h"
#include "../include/Obj25100.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTLV_FINGER_CURSOR_IsActive(void *);
extern void B_BAG_MAIN_PlaySe(char **, int);
extern void B_BAG_MAIN_StartFrameAnim(char *, int);
extern int B_BAG_MAIN_StateShowPocket1(char *);
extern int B_BAG_MAIN_StateShowPocket2(char *);
extern unsigned B_BAG_MAIN_GetSlotItem(const char *p, unsigned n);
extern int B_BAG_MAIN_StateShowMessage(char *);
int B_BAG_MAIN_StateOtherFlow(char *p)
{
    switch (((struct Obj00688 *)p)->f53D) {
    case 0:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct Obj00688 *)p)->f533 = 2;
            ((struct Obj00688 *)p)->f531 = 0x11;
            B_BAG_MAIN_StartFrameAnim(p, 2);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 1:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 0) {
            B_BAG_MAIN_StateShowPocket1(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00688 *)p)->f531 = 0x11;
            B_BAG_MAIN_StartFrameAnim(p, 4);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 3:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 0) {
            B_BAG_MAIN_StateShowPocket2(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct Obj25098 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f16 = B_BAG_MAIN_GetSlotItem(p, *(short *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30));
            ((struct Obj25099 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f2A = ((struct Obj00688 *)p)->f533;
            ((struct Obj25100 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f18 = 0;
            B_BAG_MAIN_StartFrameAnim(p, 0xd);
            ++((struct Obj00688 *)p)->f53D;
        }
        break;
    case 5:
        if (BTLV_FINGER_CURSOR_IsActive(((struct Obj00688 *)p)->f14C) == 0) return B_BAG_MAIN_StateShowMessage(p);
        break;
    }
    return 0x11;
}

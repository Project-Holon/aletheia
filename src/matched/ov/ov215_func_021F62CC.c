/*
 * function: func_021F62CC
 * address: 0x021F62CC
 * packet: pkt_ov215_021F62CC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 */
#include "../include/Obj08425.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned BMP_MENU_ProcessYesNo(u8 *);
void func_021F62CC(void *unused, char *p)
{
    unsigned result;
    int flag;
    switch (((struct Obj08425 *)p)->f20) {
    case 0:
        break;
    case 1:
        result = BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj08425 *)p)->f78);
        if (result != 0xffffffff) {
            if (result == 0) flag = 1;
            else flag = 0;
            ((struct Obj08425 *)p)->f7C = flag;
            ((struct Obj08425 *)p)->f20 = 2;
        }
        break;
    }
}

/*
 * function: func_021F7120
 * address: 0x021F7120
 * packet: pkt_ov112_021F7120
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F77A0 0x021F77A0 thumb ov112
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj13839.h"
typedef unsigned char  u8;
extern void func_021F77A0(char *p, char *q);
extern void BILLBOARD_DeleteImage(u8 *a0, int i);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
typedef struct { int pad[5]; int flag; } Record;
void func_021F7120(char *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1)
            func_021F77A0((char *)((int)p), (char *)((int)(p + 0x14 + i * 0x108)));
    }
    BILLBOARD_DeleteImage((u8 *)(((struct Obj13839 *)p)->f8), ((struct Obj13839 *)p)->f438);
    func_020307B0((void *)((int)p));
}

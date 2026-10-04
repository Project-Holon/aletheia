/*
 * function: func_02167DEC
 * address: 0x02167DEC
 * packet: pkt_ov010_02167DEC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj09320.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u8 pad[0xc];
    u16 low : 3;
    u16 flag : 1;
    u16 high : 12;
} Flags;
extern u16 func_02039338(void);
void func_02167DEC(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338()) {
        ((struct Obj09320 *)p)->f728 = 0;
        if (((Flags *)p)->flag != 0 || *c != 0)
            ((struct Obj09320 *)p)->f728 = 1;
    }
}

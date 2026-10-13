/*
 * function: func_021C14A8
 * address: 0x021C14A8
 * packet: pkt_ov099_021C14A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02039C68 0x02039C68 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../include/Obj22056.h"
extern int func_021C1154(char *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned func_02039CB4(struct Link *, unsigned, unsigned);
extern void func_02039C68(struct Link *, unsigned, unsigned);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void func_0203D7BC(u8 a0);
int func_021C14A8(char *p, int ret)
{
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 15, 10) != 0) {
            GFL_NET_SetAutoExit(1);
            func_0203D7BC(1);
            func_02039C68((struct Link *)func_020399A8(), 18, 10);
            ((struct Obj22056 *)p)->f1CC = 45;
        }
    }
    return ret;
}

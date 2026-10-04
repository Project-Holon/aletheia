/*
 * function: func_021D9974
 * address: 0x021D9974
 * packet: pkt_ov121_021D9974
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02050BE8 0x02050BE8 arm
 */
#include "../include/Obj10413.h"
typedef unsigned char u8;
extern void func_02047964(void *),func_02048AD0(void *),func_020479D8(void),func_02050BE8(void);
void func_021D9974(u8 *p) {
    if(((struct Obj10413 *)p)->f4) {
        func_02047964(((struct Obj10413 *)p)->f4);
        func_02048AD0(((struct Obj10413 *)p)->f0);
        func_020479D8();
        func_02050BE8();
    }
}

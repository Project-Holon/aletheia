/*
 * function: func_021B9F08
 * address: 0x021B9F08
 * packet: pkt_ov069_021B9F08
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 */
#include "../include/Obj20658.h"
extern unsigned func_020221A4(void);
int func_021B9F08(char *p)
{
    if (func_020221A4()) {
        ((struct Obj20658 *)p)->f158 = 0;
        return 0;
    }
    return 1;
}

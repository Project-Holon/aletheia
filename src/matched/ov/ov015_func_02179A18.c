/*
 * function: func_02179A18
 * address: 0x02179A18
 * packet: pkt_ov015_02179A18
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov015/unit_02179824_p03.c and filed here.
 *
 * symbols:
 *   d_0217AB40 0x0217AB40 data ov015 a4
 *   d_0217ABA0 0x0217ABA0 data ov015 a4
 *   d_0217AB80 0x0217AB80 data ov015 a1
 */

#include "../include/G_s_ab40.h"
#include "../include/G_s_aba0.h"
#include "../include/G_State.h"

typedef unsigned char u8;
typedef unsigned int   u32;

struct flags_ab80 {
    u8 pad[0xE];
    u8 fE;
    u8 b0 : 1;
    u8 b1 : 1;
};

int func_02179A18(void);
extern struct s_ab40 d_0217AB40;
extern struct s_aba0 d_0217ABA0;
extern struct State d_0217AB80;

int func_02179A18(void)
{
    if (d_0217AB80.f14 == 1 && ((struct flags_ab80 *)&d_0217AB80)->b0 == 0 && ((u32 *)&d_0217AB40)[0x40 / 4] == 0 && d_0217ABA0.b1 == 0)
        return 1;
    return 0;
}

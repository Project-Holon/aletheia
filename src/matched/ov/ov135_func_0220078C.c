/*
 * function: func_0220078C
 * address: 0x0220078C
 * packet: pkt_ov135_0220078C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov135/worldtrade_adapter_p04.c and filed here.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef struct { u8 pad0[0x28]; int state; u8 pad2C[0xE18 - 0x2C]; u16 active; } Work_0220078C;
int func_0220078C(Work_0220078C *p);

int func_0220078C(Work_0220078C *p)
{
    if (p->active != 0) {
        p->state = 9;
    }
    return 2;
}

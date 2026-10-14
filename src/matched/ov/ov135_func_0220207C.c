/*
 * function: WORLDTRADE_SERVER_StateCountdown
 * address: 0x0220207C
 * packet: pkt_ov135_0220207C
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

/*
 * When the mode query answers 1, publish the u16 at +0xe0c.
 */
typedef struct { u8 pad0[0x28]; int state; u8 pad2C[0xDFC - 0x2C]; int cnt; } Work_0220207C;
int WORLDTRADE_SERVER_StateCountdown(Work_0220207C *p);

int WORLDTRADE_SERVER_StateCountdown(Work_0220207C *p)
{
    p->cnt--;
    if (p->cnt == 0) {
        p->state = 0x24;
    }
    return 2;
}

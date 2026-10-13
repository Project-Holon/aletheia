/*
 * function: POKE_REGULATION_GetBattleModeLine
 * address: 0x0201A4B4
 * packet: pkt_arm9_0201A4B4
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/pokeparty_p01.c and filed here.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 */

struct MsgBank;
typedef unsigned int   u32;
typedef unsigned char  u8;

struct Ctx {
    struct MsgBank *bank;
    u8 pad04[0x30];
    u8 f34;
};

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void *POKE_REGULATION_GetBattleModeLine(u8 *a0, int a1, struct Ctx *c);

void *POKE_REGULATION_GetBattleModeLine(u8 *a0, int a1, struct Ctx *c)
{
    u32 k;
    u8 v = c->f34;

    if (v == 1) {
        k = 0x16;
    } else {
        k = 0x17;
        if (v != 0)
            k = 0x16;
    }
    return func_02045EC0(c->bank, k);
}

/*
 * function: POKE_REGULATION_GetBannedSpeciesLine
 * address: 0x0201A468
 * packet: pkt_arm9_0201A468
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
void *POKE_REGULATION_GetBannedSpeciesLine(u8 *a0, int a1, struct Ctx *c);

void *POKE_REGULATION_GetBannedSpeciesLine(u8 *a0, int a1, struct Ctx *c)
{
    int i;
    u32 k;

    for (i = 0; i < 0x52; i++) {
        if (a0[i + 0xA] != 0)
            break;
    }
    k = 0x10;
    if (i != 0x52)
        k = 0x11;
    return func_02045EC0(c->bank, k);
}

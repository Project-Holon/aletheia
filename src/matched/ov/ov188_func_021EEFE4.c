/*
 * function: BATTLE_REC_TOOL_UnpackParties
 * address:  0x021EEFE4
 * packet:   pkt_021EEFE4
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BATTLE_REC_TOOL_UnpackParty  0x021EEF2C  thumb  ov188
 */
typedef unsigned int u32;

typedef unsigned char  u8;
extern void BATTLE_REC_TOOL_UnpackParty(u8 *a, void *b, u32 c);

void BATTLE_REC_TOOL_UnpackParties(void *p, char *b, u32 c)
{
    char *base;
    u32 i = 0;

    base = b + 0xc38;
    for (; i < 4; i++) {
        u32 v = *(u32 *)((char *)p + i * 4 + 0x24);

        if (v != 0)
            BATTLE_REC_TOOL_UnpackParty((u8 *)(base + i * 0x2a4), (void *)v, c);
    }
}

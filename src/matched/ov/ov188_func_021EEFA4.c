/*
 * function: BATTLE_REC_TOOL_PackParties
 * address:  0x021EEFA4
 * packet:   pkt_021EEFA4
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two shape levers close it.  The table slot is the indexed form `a[9 + i]`
 * (with `a` typed `int *`), not `*(int *)(a + 0x24 + i*4)`: the byte-offset
 * spelling folds a+0x24 into a base register.  And `base` must be declared
 * before `i` — the original keeps the 0xC38 base in r4 and i in r5.
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   BATTLE_REC_TOOL_PackParty   0x021EEED8  thumb
 *
 * Clear 0xA90 bytes at p+0xC38, then release each non-null entry of the
 *   four-record table at a+0x24.
 */


extern void MI_CpuFill8(int, int, int);
extern void BATTLE_REC_TOOL_PackParty(int, char *);

void BATTLE_REC_TOOL_PackParties(int *a, char *p)
{
    char *base;
    unsigned int i;
    MI_CpuFill8((int)(p + 0xC38), 0, 0xA90);
    base = p + 0xC38;
    for (i = 0; i < 4; i++) {
        int v = a[9 + i];
        if (v != 0)
            BATTLE_REC_TOOL_PackParty(v, base + i * 0x2A4);
    }
}

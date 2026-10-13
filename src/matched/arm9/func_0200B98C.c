/*
 * function: BATTLE_REC_GetHeaderParam
 * address:  0x0200B98C
 * packet:   pkt_0200B98C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BattleRecModeTable 0x0209DDCC data
 *
 * A record field getter: selector picks the field, the result is 64-bit.
 * Callers: ov183 0x021DD228, 0x021DD25C, 0x021DEE7C, 0x021DF838 and others.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

extern const u16 BattleRecModeTable[];

u64 BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index)
{
    int i;
    u16 v;
    switch (selector) {
    case 0:
        v = ((u16 *)p)[index];
        if (v > 0x289)
            return 0;
        return v;
    case 1:
        return (p + index)[0x18] & 0x7f;
    case 2:
        v = *(u16 *)(p + 0x24);
        if (v > 9999)
            return 9999;
        return v;
    case 3:
        for (i = 0; i < 41; i++) {
            if (*(u16 *)(p + 0x26) == BattleRecModeTable[i])
                return i;
        }
        return 0;
    case 4:
        return *(u64 *)(p + 0x38);
    case 5:
        return p[0x2a];
    case 6:
        return ((p + index)[0x18] & 0x80) >> 7;
    case 7:
        return p[0x2b];
    }
    return 0;
}

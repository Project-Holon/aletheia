/*
 * function: BATTLE_REC_TOOL_PackBattleRules
 * address:  0x021EF1F4
 * packet:   pkt_ov188_021EF1F4
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   CONFIG_Copy  0x02008314  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[4]; } Block16;
typedef struct { u32 w[6]; } Block24;
typedef struct { unsigned char low:5, high:3; } Bits50;
typedef struct { unsigned char low:4, mid:3, high:1; } Bits51;
extern void CONFIG_Copy(void *a, void *b);

int BATTLE_REC_TOOL_PackBattleRules(const u8 *a, u8 *b)
{
    int f;
    *(Block16 *)(b + 24) = *(const Block16 *)(a + 8);
    *(Block24 *)b = *(const Block24 *)(a + 156);
    *(u16 *)(b + 44) = *(const u16 *)(a + 24);
    *(u16 *)(b + 46) = *(const u16 *)(a + 26);
    ((Bits50 *)(b + 50))->low = *(const u32 *)a;
    ((Bits51 *)(b + 51))->low = *(const u32 *)(a + 4);
    ((Bits51 *)(b + 51))->mid = a[34];
    *(u16 *)(b + 48) = *(const u16 *)(a + 134);
    ((Bits50 *)(b + 50))->high = a[33];
    f = (a[127] != 0);
    ((Bits51 *)(b + 51))->high = f;
    CONFIG_Copy(*(void **)(a + 92), b + 40);
    return 1;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: BG_SYS_GetBuf, BG_SYS_GetChannelScrollX, BG_SYS_GetChannelScrollY, BG_SYS_GetType,
 *           BG_SYS_GetColorMode, BG_SYS_GetTileBytes
 * address:  0x0204162C
 * packet:   pkt_0204152C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ptr_02146A44  0x02146A44  data
 *
 * Channel state struct member accessors.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204162C.c \
 *       --addr 0x0204162C --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Channel {
    u8  pad00[8];
    u32 field_08;
    u8  pad0c[8];
    u32 field_14;
    u32 field_18;
    u8  field_1c;
    u8  pad1d[1];
    u8  field_1e;
    u8  field_1f;
    u8  pad20[0xc];
};

extern struct Channel *ptr_02146A44;

u32 BG_SYS_GetBuf(int channel)
{
    return ptr_02146A44[channel].field_08;
}

u32 BG_SYS_GetChannelScrollX(u8 channel)
{
    return ptr_02146A44[channel].field_14;
}

u32 BG_SYS_GetChannelScrollY(u8 channel)
{
    return ptr_02146A44[channel].field_18;
}

u8 BG_SYS_GetType(int channel)
{
    return ptr_02146A44[channel].field_1c;
}

u8 BG_SYS_GetColorMode(int channel)
{
    return ptr_02146A44[channel].field_1e;
}

u8 BG_SYS_GetTileBytes(int channel)
{
    return ptr_02146A44[channel].field_1f;
}

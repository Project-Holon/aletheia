/*
 * unit:     yes
 * function: APP_ICON_GetBallCellFileId, APP_ICON_GetBallPaletteFileId, APP_ICON_GetBallAnimFileId, APP_ICON_GetBallFrameFileId,
 *           APP_ICON_GetBallThrowCellFileId, APP_ICON_GetBallThrowAnimFileId, APP_ICON_GetBallOpenCellFileId, APP_ICON_GetBallOpenPaletteFileId,
 *           APP_ICON_GetBallOpenAnimFileId, APP_ICON_GetEffectCellFileId, APP_ICON_GetEffectPaletteFileId, APP_ICON_GetEffectAnimFileId,
 *           APP_ICON_GetNoneFileId, APP_ICON_GetGearCellFileId, APP_ICON_GetGearPaletteFileId, APP_ICON_GetGearAnimFileId,
 *           APP_ICON_GetGearDataFileId, APP_ICON_GetGearExtraFileId, APP_ICON_GetGearFrameFileId, APP_ICON_GetGearAnim2FileId
 * address:  0x02027710
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Offset accessors and constants in beacon_status.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02027710.c \
 *       --addr 0x02027710 --thumb --cc 1.1p1
 */

int APP_ICON_GetBallCellFileId(int a)
{
    return a + 0x51;
}

int APP_ICON_GetBallPaletteFileId(int a)
{
    return a + 0x54;
}

int APP_ICON_GetBallAnimFileId(int a)
{
    return a + 0xa6;
}

int APP_ICON_GetBallFrameFileId(int a)
{
    return a + 0xa9;
}

int APP_ICON_GetBallThrowCellFileId(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x56;
}

int APP_ICON_GetBallThrowAnimFileId(int a)
{
    if (a == 0) {
        a = 4;
    }
    return a + 0x6f;
}

int APP_ICON_GetBallOpenCellFileId(int dummy, int b)
{
    return b + 0x89;
}

int APP_ICON_GetBallOpenPaletteFileId(int dummy, int b)
{
    return b + 0x8c;
}

int APP_ICON_GetBallOpenAnimFileId(void)
{
    return 0x8f;
}

int APP_ICON_GetEffectCellFileId(int a)
{
    return a + 0x90;
}

int APP_ICON_GetEffectPaletteFileId(int a)
{
    return a + 0x93;
}

int APP_ICON_GetEffectAnimFileId(int a)
{
    return a + 0x96;
}

int APP_ICON_GetNoneFileId(void)
{
    return 0;
}

int APP_ICON_GetGearCellFileId(int a)
{
    return a + 2;
}

int APP_ICON_GetGearPaletteFileId(int a)
{
    return a + 5;
}

int APP_ICON_GetGearAnimFileId(int a)
{
    return a + 8;
}

int APP_ICON_GetGearDataFileId(void)
{
    return 0x99;
}

int APP_ICON_GetGearExtraFileId(int a)
{
    return a + 0x9a;
}

int APP_ICON_GetGearFrameFileId(int a)
{
    return a + 0x9d;
}

int APP_ICON_GetGearAnim2FileId(int a)
{
    return a + 0xa0;
}

/*
 * file:     wm_icon_arc.c
 * unit:     yes
 * function: WM_ICON_GetArcId, WM_ICON_InitArcData
 * address:  0x0200F168
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from net_device_table.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "../types.h"

/* Three-word header WM_ICON_InitArcData stamps. */
typedef struct NetDeviceHeader {
    u32 tag;
    u32 size;
    u32 count;
} NetDeviceHeader;

u32 WM_ICON_GetArcId(void);

void WM_ICON_InitArcData(NetDeviceHeader *hdr);

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: WM_ICON_GetArcId is a stub returning 0; WM_ICON_InitArcData stamps a
 * three-word header (a type tag, a size, a count) into the caller's struct.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200F168.c \
 *       --addr 0x0200F168 --thumb
 */
u32 WM_ICON_GetArcId(void)
{
    return 0;
}

void WM_ICON_InitArcData(NetDeviceHeader *hdr)
{
    hdr->tag = 2;
    hdr->size = 4;
    hdr->count = 1;
}

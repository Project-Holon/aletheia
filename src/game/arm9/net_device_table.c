/*
 * file:     net_device_table.c
 * unit:     yes
 * function: NET_DEVICE_TABLE_Select, NET_DEVICE_TABLE_Reset
 * address:  0x0200F17C
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
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GFL_NET_DEVWIFI_GetDeviceTable  0x0215536C  thumb  ov009
 *   GFL_NET_DEVWIRELESS_GetDeviceTable  0x02177020  thumb  ov014
 *   IRCNET_GetHandlerTable  0x021798D4  thumb  ov015
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_09       0x00000009  data
 *   ov_id_0D       0x0000000D  data
 *   ov_id_72       0x00000072  data
 *   ov_id_0E       0x0000000E  data
 *   ov_id_0F       0x0000000F  data
 */
#include "fldmmdl_save_shared_types.h"

typedef signed int     s32;

extern void GF_OVERLAY_Unload(s32 handle);

extern int GF_OVERLAY_Load(s32 handle);

extern void *GFL_NET_DEVWIFI_GetDeviceTable(void);

extern void *GFL_NET_DEVWIRELESS_GetDeviceTable(void);

extern void *IRCNET_GetHandlerTable(void);

int NET_DEVICE_TABLE_Select(u32 sel);

void NET_DEVICE_TABLE_Reset(u32 sel);

extern u8 ov_id_0A[];

extern u8 ov_id_0B[];

extern u8 ov_id_09[];

extern u8 ov_id_0D[];

extern u8 ov_id_72[];

extern u8 ov_id_0E[];

extern u8 ov_id_0F[];

/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_72 (114) and ov_id_0E (14) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * The jump table at 0x0200F18E (base 0x0200F190, selector order 0..6) is
 * 0x006c, 0x0030, 0x004e, 0x0078, 0x0078, 0x006c, 0x000c, i.e. selectors 0
 * and 5 share the arm at 0x0200F1FC, selectors 3 and 4 the one at
 * 0x0200F208, and 6, 1, 2 have their own (0x0200F19C, 0x0200F1C0,
 * 0x0200F1DE).  The cases below are written in that memory order, which is
 * what decides the arm layout (the sibling function NET_DEVICE_TABLE_Reset, same
 * packet, closes the same way).
 *
 * The arguments are absolute symbols, not numbers: every one of them arrives
 * in a literal pool (`ldr r0, [pc]`), and mwccarm writes any literal in
 * 0..255 with `movs`
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).  The
 * seven words of the pool are, in order, 0x0A, 0x0B, 9, 0x0D, 0x72, 0x0E,
 * 0x0F -- all seven are loaded.
 *
 * seed round 9: the five overlay call sites now resolve (0x0215536C,
 *           0x02177020 and 0x021798D4 seeded in layout/function_starts.txt);
 *           25 of 27 sites resolved.  The two left are the pooled overlay-id
 *           constants ov_id_72 and ov_id_0E, which have no witness outside
 *           this range, so the file stayed MATCH until the wave 17
 *           `overlay_id` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_Select.c \
 *       --func NET_DEVICE_TABLE_Select --addr 0x0200F17C --cc 1.1p1 --thumb
 */
int NET_DEVICE_TABLE_Select(u32 sel)
{
    switch (sel) {
    case 6:
        GF_OVERLAY_Unload((u32)ov_id_0A);
        GF_OVERLAY_Unload((u32)ov_id_0B);
        GF_OVERLAY_Load((u32)ov_id_09);
        GF_OVERLAY_Load((u32)ov_id_0D);
        GF_OVERLAY_Load((u32)ov_id_72);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 1:
        GF_OVERLAY_Unload((u32)ov_id_0A);
        GF_OVERLAY_Unload((u32)ov_id_0B);
        GF_OVERLAY_Load((u32)ov_id_09);
        GF_OVERLAY_Load((u32)ov_id_0D);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 2:
        GF_OVERLAY_Unload((u32)ov_id_0A);
        GF_OVERLAY_Unload((u32)ov_id_0B);
        GF_OVERLAY_Load((u32)ov_id_09);
        GF_OVERLAY_Load((u32)ov_id_0D);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 0:
    case 5:
        GF_OVERLAY_Load((u32)ov_id_0E);
        return (int)GFL_NET_DEVWIRELESS_GetDeviceTable();
    case 3:
    case 4:
        GF_OVERLAY_Load((u32)ov_id_0F);
        return (int)IRCNET_GetHandlerTable();
    }
    return 0;
}

void NET_DEVICE_TABLE_Reset(u32 sel)
{
    switch (sel) {
    case 6:
        GF_OVERLAY_Unload((u32)ov_id_72);
        GF_OVERLAY_Unload((u32)ov_id_09);
        GF_OVERLAY_Unload((u32)ov_id_0D);
        GF_OVERLAY_Load((u32)ov_id_0A);
        GF_OVERLAY_Load((u32)ov_id_0B);
        break;
    case 1:
        GF_OVERLAY_Unload((u32)ov_id_09);
        GF_OVERLAY_Unload((u32)ov_id_0D);
        GF_OVERLAY_Load((u32)ov_id_0A);
        GF_OVERLAY_Load((u32)ov_id_0B);
        break;
    case 2:
        GF_OVERLAY_Unload((u32)ov_id_09);
        GF_OVERLAY_Unload((u32)ov_id_0D);
        GF_OVERLAY_Load((u32)ov_id_0A);
        GF_OVERLAY_Load((u32)ov_id_0B);
        break;
    case 0:
    case 5:
        GF_OVERLAY_Unload((u32)ov_id_0E);
        break;
    case 3:
    case 4:
        GF_OVERLAY_Unload((u32)ov_id_0F);
        break;
    }
}

/*
 * function: UNION_COMMAND_SendAppSetting
 * address: 0x02173F20
 * packet: pkt_ov012_02173F20
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 *   UNION_APP_GetSettingSize 0x021840A8 thumb ov022
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendDataMask(u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 UNION_APP_GetSettingSize(u32);
u32 UNION_COMMAND_SendAppSetting(void *p, u32 a)
{
    u32 entry;
    u32 size;
    entry = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    size = UNION_APP_GetSettingSize(entry);
    return GFL_NET_SendDataMask(entry, a, 0x1410, size, (u32)p, 1, 0, 0);
}

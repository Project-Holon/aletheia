/*
 * function: BTL_SERVER_FLOW_CanChangeWeather
 * address: 0x021C3B8C
 * packet: pkt_ov093_021C3B8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_FIELD_GetCountdownValue 0x021EF884 thumb ov093
 *   BTL_FIELD_GetCountdownCount 0x021EF894 thumb ov093
 */
typedef unsigned int u32;
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern int BTL_FIELD_GetCountdownValue(void);
extern int BTL_FIELD_GetCountdownCount(void);
BOOL BTL_SERVER_FLOW_CanChangeWeather(void *p, u32 a, u32 b)
{
    if (a >= 5) return FALSE;
    if (a == BTL_FIELD_GetCountdownValue() && (b != 255 || BTL_FIELD_GetCountdownCount() == 255)) {
        return FALSE;
    }
    return TRUE;
}

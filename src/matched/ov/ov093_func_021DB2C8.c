/*
 * function: BTL_TOKUSEI_Forecast_ResetFormOnAbilityChange
 * address: 0x021DB2C8
 * packet: pkt_ov093_021DB2C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_TOKUSEI_Forecast_ResetForm 0x021DB318 thumb ov093
 */
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_TOKUSEI_Forecast_ResetForm(int,void *,int);

void BTL_TOKUSEI_Forecast_ResetFormOnAbilityChange(void *a, void *b, int c)
{
    int v;
    if (c == BTL_EVENT_GetVar(2)) {
        v = BTL_EVENT_GetVar(16);
        if (v != BTL_EVENT_GetFactorKey(a)) BTL_TOKUSEI_Forecast_ResetForm((int)a, b, c);
    }
}

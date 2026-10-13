/*
 * function: SCRCMD_POKEMON_FLD_StartTradeEvent
 * address:  0x021B654C
 * packet:   pkt_ov021_021B654C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   FLD_TRADE_CreateEvent  0x021CC500  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void *FLD_TRADE_CreateEvent(void *a, u32 b, u32 c);

u32 SCRCMD_POKEMON_FLD_StartTradeEvent(void *a, void *b)
{
    void *r7 = SCRCMD_WORK_GetScriptWork(b);
    void *x = SCRCMD_WORK_GetGameSystem(b);
    u32 t = SCRIPT_WORK_ReadWorkValue(a, b);
    u32 u = SCRIPT_WORK_ReadWorkValue(a, b);
    SCRIPT_SYS_CallEvent(r7, FLD_TRADE_CreateEvent(x, (u8)t, (u8)u));
    return 1;
}

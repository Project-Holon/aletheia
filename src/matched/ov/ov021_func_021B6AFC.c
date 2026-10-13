/*
 * function: SCRCMD_POKEMON_FLD_AddWarpMenuItems
 * address:  0x021B6AFC
 * packet:   pkt_ov021_021B6AFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetFadeState  0x0215A6C4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   SCRCMD_WORK_GetScriptId  0x0215A5D0  thumb  ov010
 *   SCRCMD_POKEMON_FLD_CountWarpEntries  0x021B6AB0  thumb
 *   SCRCMD_POKEMON_FLD_GetWarpEntry  0x021B6AA4  thumb
 *   SCRCMD_WORK_AddMenuItem  0x0215A7F0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 SCRCMD_WORK_GetFadeState(void *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern u16 SCRCMD_WORK_GetScriptId(void *);
extern int SCRCMD_POKEMON_FLD_CountWarpEntries(void *a);
extern u16 *SCRCMD_POKEMON_FLD_GetWarpEntry(void *, u32);
struct U16Vec;
extern void SCRCMD_WORK_AddMenuItem(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);

u32 SCRCMD_POKEMON_FLD_AddWarpMenuItems(void *a, void *b)
{
    void *tab = (void *)SCRCMD_WORK_GetFadeState(b);
    void *r4 = SCRCMD_WORK_GetScriptWork(b);
    int s0c = SCRIPT_WORK_GetMsgBuffer(r4);
    int s8 = SCRIPT_WORK_GetTempBuffer(r4);
    u16 id = SCRCMD_WORK_GetScriptId(b);
    u32 n = SCRCMD_POKEMON_FLD_CountWarpEntries(tab);
    u32 i = 0;

    for (; i < n; i++) {
        u16 *e = SCRCMD_POKEMON_FLD_GetWarpEntry(tab, i);

        if (id != e[1])
            SCRCMD_WORK_AddMenuItem(b, e[0], 0xffff, i, (struct U16Vec *)s0c, (void *)s8);
    }
    return 0;
}

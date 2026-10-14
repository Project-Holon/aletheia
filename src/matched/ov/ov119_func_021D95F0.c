/*
 * function: POKETRADE_PROC_IsGuestSide
 * address: 0x021D95F0
 * packet: pkt_ov119_021D95F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_PROC_GetMonSpeciesFlag 0x021D95A0 thumb ov119
 */
typedef unsigned int u32;
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
extern u32 POKETRADE_PROC_GetMonSpeciesFlag(void *);
u32 POKETRADE_PROC_IsGuestSide(void *p)
{
    int r = 1;
    if (POKETRADE_PROC_IsHostSide(p) != 0)
        r = 0;
    return POKETRADE_PROC_GetMonSpeciesFlag(POKETRADE_PROC_GetSideMon(p, r));
}

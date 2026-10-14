/*
 * function: POKETRADE_PROC_StepWaitWipeEnd
 * address: 0x021D941C
 * packet: pkt_ov119_021D941C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 */
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void POKETRADE_PROC_SetStep(void *, int);
void POKETRADE_PROC_StepWaitWipeEnd(void *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        POKETRADE_PROC_SetStep(p, 0);
}

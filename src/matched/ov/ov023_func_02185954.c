/*
 * function: OEKAKI_StepWaitMessage
 * address: 0x02185954
 * packet: pkt_ov023_02185954
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OEKAKI_IsMessageDone 0x021862B0 thumb ov023
 *   OEKAKI_SetNextScene 0x02186444 thumb ov023
 *   OEKAKI_ApplyRemoteStrokes 0x02185354 thumb ov023
 */
extern int OEKAKI_IsMessageDone(char *);
extern void OEKAKI_SetNextScene(char *, unsigned int);
extern void OEKAKI_ApplyRemoteStrokes(char *);
int OEKAKI_StepWaitMessage(char *p, int a)
{
    if (OEKAKI_IsMessageDone(p))
        OEKAKI_SetNextScene(p, 0xe);
    OEKAKI_ApplyRemoteStrokes(p);
    return a;
}

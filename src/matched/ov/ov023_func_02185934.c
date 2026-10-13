/*
 * function: OEKAKI_StepShowWaitMessage
 * address: 0x02185934
 * packet: pkt_ov023_02185934
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OEKAKI_PrintMessage 0x021861C4 thumb ov023
 *   OEKAKI_SetNextScene 0x02186444 thumb ov023
 *   OEKAKI_ApplyRemoteStrokes 0x02185354 thumb ov023
 */
typedef unsigned char u8;
extern void OEKAKI_PrintMessage(u8 *, unsigned int, int);
extern void OEKAKI_SetNextScene(char *, unsigned int);
extern void OEKAKI_ApplyRemoteStrokes(char *);
int OEKAKI_StepShowWaitMessage(char *p, int a)
{
    OEKAKI_PrintMessage((u8 *)p, 5, 1);
    OEKAKI_SetNextScene(p, 0x17);
    OEKAKI_ApplyRemoteStrokes(p);
    return a;
}

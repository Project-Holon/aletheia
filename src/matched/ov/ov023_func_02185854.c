/*
 * function: OEKAKI_StepShowFinishMessage
 * address: 0x02185854
 * packet: pkt_ov023_02185854
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x0218587C.
 * symbols:
 *   OEKAKI_RegisterPlayerName 0x021857F4 thumb ov023
 *   OEKAKI_PrintMessage 0x021861C4 thumb ov023
 *   OEKAKI_SetNextScene 0x02186444 thumb ov023
 *   OEKAKI_ApplyRemoteStrokes 0x02185354 thumb ov023
 */
typedef unsigned char u8;
extern void OEKAKI_RegisterPlayerName(char *, int, int);
extern void OEKAKI_PrintMessage(u8 *, unsigned int, int);
extern void OEKAKI_SetNextScene(char *, unsigned int);
extern void OEKAKI_ApplyRemoteStrokes(char *);
int OEKAKI_StepShowFinishMessage(char *p, int a)
{
    OEKAKI_RegisterPlayerName(p, 0, 0);
    OEKAKI_PrintMessage((u8 *)p, 3, 1);
    OEKAKI_SetNextScene(p, 0x13);
    OEKAKI_ApplyRemoteStrokes(p);
    return a;
}

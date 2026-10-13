/*
 * function: OEKAKI_StepShowQuitMessage
 * address:  0x021856AC
 * packet:   pkt_021856AC
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_PrintMessage  0x021861C4  thumb  ov023
 */

extern void OEKAKI_ApplyRemoteStrokes(char *p);
typedef unsigned int   u32;
extern void OEKAKI_SetNextScene(char *p, u32 v);
typedef unsigned char  u8;
extern void OEKAKI_PrintMessage(u8 *w, u32 msg, int mode);

int OEKAKI_StepShowQuitMessage(char *p, int a1)
{
    OEKAKI_PrintMessage((u8 *)p, 6, 1);
    OEKAKI_SetNextScene(p, 0xd);
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}

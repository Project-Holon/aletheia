/*
 * function: OEKAKI_ApplyRemoteStrokes
 * address: 0x02185354
 * packet: pkt_ov023_02185354
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OEKAKI_UpdateRemoteCursors 0x02185EA0 thumb ov023
 *   OEKAKI_DrawStrokes 0x02185DE8 thumb ov023
 */
#include "../include/Obj00525.h"
struct e6 { unsigned char b[4]; unsigned char c:3, n:3, d:2; unsigned char pad; };
struct o4 { unsigned char x, y; unsigned short n; };
struct P;
extern void OEKAKI_UpdateRemoteCursors(struct P *p);
extern void OEKAKI_DrawStrokes(char *p, struct e6 *e, struct o4 *o, int flag);
void OEKAKI_ApplyRemoteStrokes(char *p)
{
    OEKAKI_UpdateRemoteCursors((struct P *)p);
    OEKAKI_DrawStrokes(*(char * *)&((struct Obj00525 *)p)->f118, (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 0);
}

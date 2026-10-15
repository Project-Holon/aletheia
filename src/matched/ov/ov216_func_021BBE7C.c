/*
 * unit: yes
 * function: BEACON_DETAIL_GRA_Main, BEACON_DETAIL_GRA_StateInteract
 * address: 0x021BBE7C
 * packet: pkt_ov216_021BBE7C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021BBF0C pool-and-bx thunk forwarding to 021BCC10.
 * symbols:
 *   BEACON_DETAIL_GRA_UpdateTouchBar 0x021BC3DC thumb ov216
 *   BEACON_DETAIL_GRA_StateInit 0x021BBF28 thumb ov216
 *   BEACON_DETAIL_GRA_StateFadeIn 0x021BBF60 thumb ov216
 *   BEACON_DETAIL_GRA_StateClose 0x021BBF14 thumb ov216
 *   BEACON_DETAIL_GRA_StateFadeOut 0x021BBF98 thumb ov216
 *   BEACON_DETAIL_GRA_UpdateInteract 0x021BCC10 thumb ov216
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BEACON_DETAIL_GRA_IsPmsActive 0x021BC920 thumb ov216
 *   BEACON_DETAIL_GRA_Draw 0x021BCA24 thumb ov216
 */
#include "../include/Obj03374.h"
struct Tcbl; struct PrintSys;
extern void BEACON_DETAIL_GRA_UpdateTouchBar(void *);
extern int BEACON_DETAIL_GRA_StateInit(unsigned char *p);
extern int BEACON_DETAIL_GRA_StateFadeIn(char *);
extern int BEACON_DETAIL_GRA_StateClose(char *);
extern int BEACON_DETAIL_GRA_StateFadeOut(char *);
extern int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *);
extern void TCBL_Main(struct Tcbl *);
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
extern int BEACON_DETAIL_GRA_IsPmsActive(unsigned *);
extern void BEACON_DETAIL_GRA_Draw(char *);
int BEACON_DETAIL_GRA_StateInteract(char *);
int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p)
{
    if (((struct Obj03374 *)p)->f10) return 1;
    if (*state>=2 && *state<=3) BEACON_DETAIL_GRA_UpdateTouchBar(((struct Obj03374 *)p)->f124);
    switch (*state) {
    case 0: *state=BEACON_DETAIL_GRA_StateInit((unsigned char *)p); break;
    case 1: *state=BEACON_DETAIL_GRA_StateFadeIn(p); break;
    case 2: *state=BEACON_DETAIL_GRA_StateInteract(p); break;
    case 3: *state=BEACON_DETAIL_GRA_StateClose(p); break;
    case 4: *state=BEACON_DETAIL_GRA_StateFadeOut(p); break;
    case 5: return 1;
    }
    TCBL_Main(*(struct Tcbl * *)&((struct Obj03374 *)p)->f18);
    PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C);
    BEACON_DETAIL_GRA_IsPmsActive((unsigned *)p);
    BEACON_DETAIL_GRA_Draw(*(char * *)&((struct Obj03374 *)p)->f50);
    return 0;
}
int BEACON_DETAIL_GRA_StateInteract(char *p)
{
    return BEACON_DETAIL_GRA_UpdateInteract((unsigned char *)p);
}

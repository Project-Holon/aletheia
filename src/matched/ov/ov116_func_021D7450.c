/*
 * function: WIFI_BSUBWAY_GRAPHIC_Step
 * address: 0x021D7450
 * packet: pkt_ov116_021D7450
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 * symbols:
 *   WIFI_BSUBWAY_GRAPHIC_PrintMessage 0x021D8010 thumb ov116
 *   WIFI_BSUBWAY_PollHttpRequest 0x021D6EC4 thumb ov116
 *   WIFI_BSUBWAY_StartHttpRequest 0x021D6E50 thumb ov116
 *   WIFI_BSUBWAY_StartUploadPlayer 0x021D7060 thumb ov116
 *   WIFI_BSUBWAY_IsUploadDone 0x021D70B0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream 0x021D80CC thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_StartSave 0x021D81D0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdateSave 0x021D81EC thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon 0x021D81B4 thumb ov116
 */
#include "../include/Obj01926.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *,u32);
extern int WIFI_BSUBWAY_PollHttpRequest(u8 *,u8 *,int);
extern void WIFI_BSUBWAY_StartHttpRequest(u8 *,u8 *,int,int);
extern void WIFI_BSUBWAY_StartUploadPlayer(u8 *,u8 *);
typedef signed int     s32;
struct Blk1AC;
extern int WIFI_BSUBWAY_IsUploadDone(void *unused, u8 *p);
extern int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void WIFI_BSUBWAY_GRAPHIC_StartSave(u8 *);
extern int WIFI_BSUBWAY_GRAPHIC_UpdateSave(u8 *);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p);
int WIFI_BSUBWAY_GRAPHIC_Step(u8 *p,int b)
{
    int v;
    switch (((struct Obj01926 *)p)->fB6C) {
    case 0: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,7); ++((struct Obj01926 *)p)->fB6C; break;
    case 1: WIFI_BSUBWAY_StartHttpRequest(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 2:
        v=WIFI_BSUBWAY_PollHttpRequest(p+0x1610,p+0x182c,0);
        if(v==1) ((struct Obj01926 *)p)->fB6C=5;
        else if(v==2) ((struct Obj01926 *)p)->fB6C=3;
        break;
    case 3: WIFI_BSUBWAY_StartHttpRequest(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 4:
        if(WIFI_BSUBWAY_PollHttpRequest(p+0x1610,p+0x182c,1)==1) ((struct Obj01926 *)p)->fB6C=5;
        break;
    case 5: WIFI_BSUBWAY_StartUploadPlayer(p+0x1610,p+0x182c); ++((struct Obj01926 *)p)->fB6C; break;
    case 6:
        if(WIFI_BSUBWAY_IsUploadDone(p+0x1610,p+0x182c)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj01926 *)p)->fB6C;
        break;
    case 7: func_0200DBA0(((struct Obj01926 *)p)->f1858,1,2); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++((struct Obj01926 *)p)->fB6C; break;
    case 8:
        if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,8); ++((struct Obj01926 *)p)->fB6C; }
        break;
    case 9: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj01926 *)p)->fB6C; break;
    case 10: return 1;
    }
    return 0;
}

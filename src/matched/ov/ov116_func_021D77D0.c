/*
 * function: WIFI_BSUBWAY_GRAPHIC_StepRetry
 * address: 0x021D77D0
 * packet: pkt_ov116_021D77D0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_BSUBWAY_ClearTrainers 0x021D6998 thumb ov116
 *   WIFI_BSUBWAY_StartRoomRequest 0x021D69A8 thumb ov116
 *   WIFI_BSUBWAY_FinishRoomRequest 0x021D69C0 thumb ov116
 *   WIFI_BSUBWAY_StartPlayerDownload 0x021D69EC thumb ov116
 *   WIFI_BSUBWAY_FinishPlayerDownload 0x021D6A10 thumb ov116
 *   WIFI_BSUBWAY_GetRoomNumber 0x021D6A40 thumb ov116
 *   WIFI_BSUBWAY_GetPlayerIndex 0x021D6A44 thumb ov116
 *   WIFI_BSUBWAY_GetDownloadResult 0x021D6A48 thumb ov116
 *   WIFI_BSUBWAY_GetTransferState 0x021D6A4C thumb ov116
 *   WIFI_BSUBWAY_NormalizeTrainers 0x021D6A5C thumb ov116
 *   WIFI_BSUBWAY_SaveHistory 0x021D6B30 thumb ov116
 *   WIFI_BSUBWAY_OpenCodeIn 0x021D7278 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_SetupTextParam 0x021D72D0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTextParam 0x021D730C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_ParseCodeIn 0x021D7324 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateWindow 0x021D7B70 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteWindow 0x021D7C58 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PrintMessage 0x021D8010 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream 0x021D80CC thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_SetWord 0x021D8118 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateYesNo 0x021D8134 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_ProcessYesNo 0x021D8168 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon 0x021D8190 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon 0x021D81B4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_StartSave 0x021D81D0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdateSave 0x021D81EC thumb ov116
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */
#include "../include/Obj00470.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern void WIFI_BSUBWAY_ClearTrainers(void *a);
extern void WIFI_BSUBWAY_StartRoomRequest(u8 *,u8 *,u16);
extern void WIFI_BSUBWAY_StartPlayerDownload(u8 *,u8 *,u16);
extern int WIFI_BSUBWAY_FinishRoomRequest(u8 *,u8 *),WIFI_BSUBWAY_FinishPlayerDownload(u8 *,u8 *);
extern u16 WIFI_BSUBWAY_GetRoomNumber(u8 *),WIFI_BSUBWAY_GetPlayerIndex(u8 *),WIFI_BSUBWAY_GetDownloadResult(u8 *);
extern int WIFI_BSUBWAY_GetTransferState(unsigned char *p);
extern void WIFI_BSUBWAY_NormalizeTrainers(u8 *);
extern void WIFI_BSUBWAY_SaveHistory(u8 *,void *);
extern void WIFI_BSUBWAY_OpenCodeIn(u8 *,int);
extern void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(u8 *p, u32 heap);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(u8 *p);
extern u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(u8 *);
extern void WIFI_BSUBWAY_GRAPHIC_CreateWindow(u8 *,u32),WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *),WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *,u32);
extern int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *);
extern u32 WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(u8 *p);
extern int WIFI_BSUBWAY_GRAPHIC_UpdateSave(u8 *);
extern int FADE_IsActive(void);
extern void WIFI_BSUBWAY_GRAPHIC_SetWord(u8 *p, u32 i, u32 a, u32 b);
extern void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_StartSave(u8 *);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int WIFI_BSUBWAY_GRAPHIC_StepRetry(u8 *p,int heap)
{
    int v;
    u32 n;
    switch(((struct Obj00470 *)p)->fB6C) {
    case 0: WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,5); ++((struct Obj00470 *)p)->fB6C; break;
    case 1: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 2: FADE_Start(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 3: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 4: WIFI_BSUBWAY_GRAPHIC_SetupTextParam(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 5: ((struct Obj00470 *)p)->fB70=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,heap); FADE_Start(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 6:
        if(FADE_IsActive()==0) {
            n=((struct Obj00470 *)p)->fB70;
            if(n>=1 && n<=10) {
                WIFI_BSUBWAY_StartRoomRequest(p+0xb74,p+0x182c,n); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,26); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++((struct Obj00470 *)p)->fB6C;
            } else ((struct Obj00470 *)p)->fB6C=19;
        } break;
    case 7:
        if(WIFI_BSUBWAY_FinishRoomRequest(p+0xb74,p+0x182c)!=0) {
            WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); v=WIFI_BSUBWAY_GetDownloadResult(p+0xb74); WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,6); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 8: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 9: FADE_Start(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 10: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 11: WIFI_BSUBWAY_OpenCodeIn(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 12: ((struct Obj00470 *)p)->fB70=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,heap); FADE_Start(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 13:
        if(FADE_IsActive()==0) {
            v=WIFI_BSUBWAY_GetDownloadResult(p+0xb74); n=((struct Obj00470 *)p)->fB70;
            if(n<1 || n>(u32)v) { ((struct Obj00470 *)p)->fB6C=19; break; }
            WIFI_BSUBWAY_StartPlayerDownload(p+0xb74,p+0x182c,n);
            v=WIFI_BSUBWAY_GetPlayerIndex(p+0xb74); WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74));
            WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,1,WIFI_BSUBWAY_GetRoomNumber(p+0xb74),(u32)((void *)2)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,1); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 14: if(WIFI_BSUBWAY_FinishPlayerDownload(p+0xb74,p+0x182c)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 15: WIFI_BSUBWAY_NormalizeTrainers(p+0xb74); WIFI_BSUBWAY_SaveHistory(p+0xb74,((struct Obj00470 *)p)->f1854); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++((struct Obj00470 *)p)->fB6C; break;
    case 16: if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,3); ++((struct Obj00470 *)p)->fB6C; } break;
    case 17: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 18: return 1;
    case 19: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,9); ++((struct Obj00470 *)p)->fB6C; break;
    case 20: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 21: WIFI_BSUBWAY_GRAPHIC_CreateYesNo(p+4); ++((struct Obj00470 *)p)->fB6C; break;
    case 22: v=WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(p+4); if(v==0) return 2; if(v==-2) { WIFI_BSUBWAY_ClearTrainers(p+0xb74); ((struct Obj00470 *)p)->fB6C=0; } break;
    }
    return 0;
}

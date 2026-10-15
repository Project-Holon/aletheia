/*
 * function: MYSTERY_TaskMenu
 * address: 0x021D6E3C
 * packet: pkt_ov121_021D6E3C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_ENV_InitParentalControl 0x0202EB44 thumb
 *   MYSTERY_UTIL_SetListValue 0x021DA84C thumb ov121
 *   MYSTERY_NET_GetResult 0x021DE4D8 thumb ov121
 *   MYSTERY_TaskMessage 0x021D80F0 thumb ov121
 *   MYSTERY_TaskAlbumView 0x021D7B4C thumb ov121
 *   MYSTERY_TaskMenuAction 0x021D72F0 thumb ov121
 *   MYSTERY_TaskExitAlbum 0x021D6DF4 thumb ov121
 *   MYSTERY_TaskNetExit 0x021D7EAC thumb ov121
 *   MYSTERY_TaskReceive 0x021D73DC thumb ov121
 *   MYSTERY_TaskNetAlbum 0x021D7CF4 thumb ov121
 *   MYSTERY_NET_SetAction 0x021DE308 thumb ov121
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_NET_GetAction 0x021DE3E0 thumb ov121
 *   MYSTERY_NET_GetReceivedData 0x021DE4DC thumb ov121
 *   MYSTERY_NET_ImportRecords 0x021DEF6C thumb ov121
 *   MYSTERY_IsCardValid 0x021D9554 thumb ov121
 *   MYSTERY_NET_UpdateWifiError 0x021DE500 thumb ov121
 *   MYSTERY_NET_Exit 0x021DE550 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_UTIL_SetTaskArg 0x021DA8C0 thumb ov121
 *   MYSTERY_UTIL_GetTaskArg 0x021DA8C4 thumb ov121
 *   MYSTERY_CreateCardMenu 0x021D81B0 thumb ov121
 *   MYSTERY_CreatePartyMenu 0x021D83DC thumb ov121
 *   MYSTERY_PollCardMenu 0x021D83B0 thumb ov121
 *   MYSTERY_CreateSaveMenu 0x021D8138 thumb ov121
 *   MYSTERY_UTIL_UpdateMenu 0x021DA178 thumb ov121
 *   MYSTERY_DeleteSaveMenu 0x021D8198 thumb ov121
 *   MYSTERY_DeleteCardMenu 0x021D8380 thumb ov121
 *   MYSTERY_DeletePartyMenu 0x021D849C thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_TaskMenu 0x021D6E3C thumb ov121
 *   MYSTERY_TaskAlbum 0x021D7814 thumb ov121
 *   KEY_GetTrg 0x020362DC arm
 *   GF_STANDARD_SetField00_F4E4 0x0203F4E4 arm
 *   MYSTERY_DATA_AddCard  0x0200A034  thumb  arm9
 *   MYSTERY_DATA_HasCardSpace  0x0200A0C8  thumb  arm9
 *   MYSTERY_DATA_IsEventFlag  0x0200A1A8  thumb  arm9
 *   MYSTERY_DATA_SetEventFlag  0x0200A1E4  thumb  arm9
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb  arm9
 *   MYSTERY_DATA_IsMainSave  0x0200A350  thumb  arm9
 *   MYSTERY_DATA_IsCardReceived  0x0200A104  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int y,m,d,week;} Date;
extern void MYSTERY_NET_SetAction(char *,unsigned);
struct RtcDate;
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern int MYSTERY_NET_GetAction(void *);
extern int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
extern int MYSTERY_NET_ImportRecords(char *,void *,u16);
extern int MYSTERY_IsCardValid(char *p, int n);
extern int MYSTERY_NET_UpdateWifiError(void *);
extern void MYSTERY_NET_Exit(char *p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_UTIL_SetTaskArg(u32 *p, u32 a);
extern void MYSTERY_UTIL_GetTaskArg(u32 *p);
extern void MYSTERY_CreateCardMenu(u8 *,u32,int);
extern void MYSTERY_CreatePartyMenu(u8 *,int);
extern int MYSTERY_PollCardMenu(char *p);
extern void MYSTERY_CreateSaveMenu(u8 *,int,int);
extern int MYSTERY_UTIL_UpdateMenu(char *);
extern void MYSTERY_DeleteSaveMenu(char *);
extern void MYSTERY_DeleteCardMenu(char *p);
extern void MYSTERY_DeletePartyMenu(char *p);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void MYSTERY_TaskAlbum(void *task, u32 *state, u8 *p);
extern u32 KEY_GetTrg(void);
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern int MYSTERY_DATA_IsEventFlag(char *p, unsigned int bit);
extern int MYSTERY_DATA_AddCard(void *p, void *arg);
extern void MYSTERY_DATA_SetEventFlag(void *p, unsigned int idx);
#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))

extern u32 MYSTERY_DATA_HasCardSpace(u8 *p);
struct Obj;
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *);
extern int MYSTERY_DATA_IsCardReceived(char *p, unsigned int idx);
extern int MYSTERY_DATA_IsMainSave(struct Obj *a0);
extern int APP_ENV_InitParentalControl(void);
extern void *MYSTERY_NET_GetResult(char *p);
extern void MYSTERY_UTIL_SetListValue(u8 *p, u32 i, u32 value);
extern void MYSTERY_TaskMessage(void *a, int *state, u8 *p);
extern void MYSTERY_TaskAlbumView(void *task, u32 *state, u8 *p);
extern void MYSTERY_TaskMenuAction(void *a, int *state, char *p);
extern void MYSTERY_TaskExitAlbum(void *a, int *state);
extern void MYSTERY_TaskNetExit(void *task, u32 *state, u8 *p);
extern void MYSTERY_TaskReceive(void *task, u32 *state, u8 *p);
extern void MYSTERY_TaskNetAlbum(void *task, u32 *state, u8 *p);
void MYSTERY_TaskMenu(void *task,u32 *state,u8 *p)
{
    int v,flag,all,id;
    u32 i;
    switch(*state) {
    case 0:
        if(W(968)) {W(968)=0;*state=2;break;}
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),79,0);
        if(P(624)==0) MYSTERY_CreateCardMenu(p,0,29);
        *state=1;break;
    case 1:
        v=MYSTERY_PollCardMenu((char *)p);
        if(v!=-1) {
        if(v==0) {
            all=1;
            MYSTERY_DeleteCardMenu((char *)p);
            flag=(MYSTERY_DATA_HasCardSpace(P(956))==0);
            if(flag) {
                for(i=0;i<MYSTERY_DATA_GetCardSlotNum(P(956));i++) {
                    if(MYSTERY_DATA_IsCardReceived(P(956),i)) all=0;
                }
            }
            if(flag) {
                if(all) {
                    if(MYSTERY_DATA_IsMainSave(P(956))==0) id=146;
                    else id=137;
                    MYSTERY_UTIL_SetMenuMessage(P(644),W(932),id,1);
                    MYSTERY_UTIL_SetTaskArg(task,0);*state=19;
                } else *state=16;
            } else {
                if(APP_ENV_InitParentalControl()==0) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMessage);
                else *state=2;
            }
        } else if(v==1) {
            MYSTERY_DeleteCardMenu((char *)p);MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskAlbumView);
        } else if(v==2) {
            MYSTERY_DeleteCardMenu((char *)p);MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenuAction);
        } else if(v==3) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskExitAlbum);
        else break;
        }
        break;
    case 2:
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),83,1);
        MYSTERY_UTIL_SetTaskArg(task,3);*state=19;break;
    case 3:MYSTERY_CreateSaveMenu(p,0,29);*state=4;break;
    case 4:
        v=MYSTERY_UTIL_UpdateMenu(P(608));
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) *state=5;else if(v==1) *state=0;
        }
        break;
    case 5:MYSTERY_NET_SetAction(P(944),1);*state=6;break;
    case 6:if(MYSTERY_NET_GetAction(P(944))==2) *state=7;break;
    case 7:
        MYSTERY_DeleteCardMenu((char *)p);MYSTERY_CreateCardMenu(p,1,29);
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),86,0);*state=8;break;
    case 8:
        if(((u32)MYSTERY_NET_GetResult(P(944)))&32) MYSTERY_UTIL_SetListValue(P(624),0,1);
        else MYSTERY_UTIL_SetListValue(P(624),0,0);
        v=MYSTERY_PollCardMenu((char *)p);
        if(v!=-1) {
        MYSTERY_DeleteCardMenu((char *)p);
        switch(v) {
        case 0:W(940)=0;*state=9;break;
        case 1:W(940)=1;*state=12;break;
        case 2:W(940)=2;*state=9;break;
        case 3:*state=14;break;
        }
        }
        break;
    case 9:
        switch(W(940)) {
        case 0:MYSTERY_UTIL_SetMenuMessage(P(644),W(932),96,1);MYSTERY_UTIL_SetTaskArg(task,10);*state=19;break;
        case 1:break;
        case 2:MYSTERY_UTIL_SetMenuMessage(P(644),W(932),102,1);MYSTERY_UTIL_SetTaskArg(task,10);*state=19;break;
        }
        break;
    case 10:MYSTERY_CreateSaveMenu(p,0,29);*state=11;break;
    case 11:
        v=MYSTERY_UTIL_UpdateMenu(P(608));
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) *state=12;else if(v==1) *state=7;
        }
        break;
    case 12:
        if(MYSTERY_NET_GetAction(P(944))==2) {MYSTERY_NET_SetAction(P(944),3);*state=13;}
        break;
    case 13:
        if(MYSTERY_NET_GetAction(P(944))==0) {
            if(W(940)==1) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskNetExit);
            else MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskReceive);
        }
        break;
    case 14:
        if(MYSTERY_NET_GetAction(P(944))==2) {MYSTERY_NET_SetAction(P(944),3);*state=15;}
        else *state=0;
        break;
    case 15:if(MYSTERY_NET_GetAction(P(944))==0) *state=0;break;
    case 16:
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),141,1);
        MYSTERY_UTIL_SetTaskArg(task,17);*state=19;break;
    case 17:MYSTERY_CreateSaveMenu(p,0,29);*state=18;break;
    case 18:
        v=MYSTERY_UTIL_UpdateMenu(P(608));
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskNetAlbum);
            else if(v==1) *state=0;
        }
        break;
    case 19:if(MYSTERY_UTIL_GetMenuState(P(644))) MYSTERY_UTIL_GetTaskArg(task);break;
    }
}

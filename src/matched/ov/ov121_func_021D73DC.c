/*
 * function: MYSTERY_TaskReceive
 * address: 0x021D73DC
 * packet: pkt_ov121_021D73DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
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
 *   GF_STANDARD_GetCachedDate 0x0203F4E4 arm
 *   MYSTERY_DATA_AddCard  0x0200A034  thumb  arm9
 *   MYSTERY_DATA_IsEventFlag  0x0200A1A8  thumb  arm9
 *   MYSTERY_DATA_SetEventFlag  0x0200A1E4  thumb  arm9
 */
#include "../include/Obj13939.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int y,m,d,week;} Date;
typedef struct {u8 bit:1;} Flag;
extern void MYSTERY_NET_SetAction(char *,unsigned);
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern int MYSTERY_NET_GetAction(void *);
extern int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
extern int MYSTERY_NET_ImportRecords(char *,void *,u16);
struct RtcDate;
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
extern void MYSTERY_TaskMenu(void *task, u32 *state, u8 *p);
extern void MYSTERY_TaskAlbum(void *task, u32 *state, u8 *p);
extern u32 KEY_GetTrg(void);
extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);
extern int MYSTERY_DATA_IsEventFlag(char *p, unsigned int bit);
extern int MYSTERY_DATA_AddCard(void *p, void *arg);
extern void MYSTERY_DATA_SetEventFlag(void *p, unsigned int idx);
#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
void MYSTERY_TaskReceive(void *task,u32 *state,u8 *p)
{
    int v,flag;
    Date date;
    switch(*state) {
    case 0:
        switch(W(940)) {
        case 1:MYSTERY_NET_SetAction(P(944),4);break;
        case 0:MYSTERY_NET_SetAction(P(944),7);break;
        case 2:MYSTERY_NET_SetAction(P(944),10);break;
        }
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),105,0);
        W(964)=0;*state=1;break;
    case 1:
        if(MYSTERY_NET_GetAction(P(944))==0) {
            v=MYSTERY_NET_GetReceivedData(P(944),p+972,720);
            if(v==1) {
                v=MYSTERY_NET_ImportRecords((char *)p+972,P(952),32797);
                if(MYSTERY_IsCardValid((char *)(p+972),v)) *state=5;
                else *state=12;
            } else if(v==2) *state=2;
        }
        v=MYSTERY_NET_UpdateWifiError(P(944));
        switch(v) {case 1:case 2:MYSTERY_NET_Exit(P(944));MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);break;}
        if((KEY_GetTrg()&2) || W(964)++>7200) {
            flag=0;
            switch(W(940)) {
            case 1:
                if(MYSTERY_NET_GetAction(P(944))==4) {MYSTERY_NET_SetAction(P(944),5);flag=1;}break;
            case 0:
                if(MYSTERY_NET_GetAction(P(944))==8) {MYSTERY_NET_SetAction(P(944),9);flag=1;}break;
            case 2:
                if(MYSTERY_NET_GetAction(P(944))==11) {MYSTERY_NET_SetAction(P(944),12);flag=1;}break;
            }
            if(flag) {*state=2;W(964)=0;}
        }
        break;
    case 2:
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),136,2);
        MYSTERY_UTIL_SetTaskArg(task,3);*state=14;break;
    case 3:
        W(964)++;
        if(MYSTERY_NET_GetAction(P(944))==0 && W(964)>30) {
            W(964)=0;
            MYSTERY_UTIL_SetMenuMessage(P(644),W(932),139,1);
            MYSTERY_UTIL_SetTaskArg(task,4);*state=14;
        }
        break;
    case 4:MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);break;
    case 5:
        MYSTERY_CreateCardMenu(p,2,29);MYSTERY_CreatePartyMenu(p,29);
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),106,0);*state=6;break;
    case 6:
        flag=0;v=MYSTERY_PollCardMenu((char *)p);
        if(v!=-1) {
        if(v==0) {
            MYSTERY_UTIL_SetMenuMessage(P(644),W(932),110,1);
            MYSTERY_UTIL_SetTaskArg(task,7);*state=14;
        } else if(v==-2) flag=1;
        } else if(KEY_GetTrg()&2) flag=1;
        if(flag) {
            MYSTERY_UTIL_SetMenuMessage(P(644),W(932),107,1);
            MYSTERY_UTIL_SetTaskArg(task,9);*state=14;
        }
        break;
    case 7:MYSTERY_CreateSaveMenu(p,0,29);*state=8;break;
    case 8:
        v=MYSTERY_UTIL_UpdateMenu(P(608));
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) {
                MYSTERY_DeleteCardMenu((char *)p);
                if(((Flag *)(p+1152))->bit && MYSTERY_DATA_IsEventFlag(P(956),((struct Obj13939 *)p)->f47C)) {*state=11;break;}
                GF_STANDARD_GetCachedDate((struct RtcDate *)(&date));
                W(1144)=(((u32)date.y+2000)<<16)|(((u32)date.m<<24)>>16)|(u8)date.d;
                MYSTERY_DATA_AddCard(P(956),p+972);
                MYSTERY_DATA_SetEventFlag(P(956),((struct Obj13939 *)p)->f47C);
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskAlbum);
            } else if(v==1) *state=5;
        }
        break;
    case 9:MYSTERY_CreateSaveMenu(p,0,29);*state=10;break;
    case 10:
        v=MYSTERY_UTIL_UpdateMenu(P(608));
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) {
                MYSTERY_DeleteCardMenu((char *)p);MYSTERY_DeletePartyMenu((char *)p);
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
            } else if(v==1) *state=5;
        }
        break;
    case 11:
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),138,1);
        MYSTERY_UTIL_SetTaskArg(task,13);*state=14;break;
    case 12:
        MYSTERY_UTIL_SetMenuMessage(P(644),W(932),144,1);
        MYSTERY_UTIL_SetTaskArg(task,13);*state=14;break;
    case 13:
        MYSTERY_DeleteCardMenu((char *)p);MYSTERY_DeletePartyMenu((char *)p);
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);break;
    case 14:
        if(MYSTERY_UTIL_GetMenuState(P(644))) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
}

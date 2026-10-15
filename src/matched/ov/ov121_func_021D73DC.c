/*
 * function: func_021D73DC
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
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   MYSTERY_NET_GetAction 0x021DE3E0 thumb ov121
 *   MYSTERY_NET_GetReceivedData 0x021DE4DC thumb ov121
 *   MYSTERY_NET_ImportRecords 0x021DEF6C thumb ov121
 *   func_021D9554 0x021D9554 thumb ov121
 *   MYSTERY_NET_UpdateWifiError 0x021DE500 thumb ov121
 *   MYSTERY_NET_Exit 0x021DE550 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021D83DC 0x021D83DC thumb ov121
 *   func_021D83B0 0x021D83B0 thumb ov121
 *   func_021D8138 0x021D8138 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021D8198 0x021D8198 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D849C 0x021D849C thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 *   func_021D7814 0x021D7814 thumb ov121
 *   KEY_GetTrg 0x020362DC arm
 *   GF_STANDARD_SetField00_F4E4 0x0203F4E4 arm
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
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern int MYSTERY_NET_GetAction(void *);
extern int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
extern int MYSTERY_NET_ImportRecords(char *,void *,u16);
struct RtcDate;
extern int func_021D9554(char *p, int n);
extern int MYSTERY_NET_UpdateWifiError(void *);
extern void MYSTERY_NET_Exit(char *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8C4(u32 *p);
extern void func_021D81B0(u8 *,u32,int);
extern void func_021D83DC(u8 *,int);
extern int func_021D83B0(char *p);
extern void func_021D8138(u8 *,int,int);
extern int func_021DA178(char *);
extern void func_021D8198(char *);
extern void func_021D8380(char *p);
extern void func_021D849C(char *p);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
extern void func_021D7814(void *task, u32 *state, u8 *p);
extern u32 KEY_GetTrg(void);
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern int MYSTERY_DATA_IsEventFlag(char *p, unsigned int bit);
extern int MYSTERY_DATA_AddCard(void *p, void *arg);
extern void MYSTERY_DATA_SetEventFlag(void *p, unsigned int idx);
#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
void func_021D73DC(void *task,u32 *state,u8 *p)
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
        func_021D9F08(P(644),W(932),105,0);
        W(964)=0;*state=1;break;
    case 1:
        if(MYSTERY_NET_GetAction(P(944))==0) {
            v=MYSTERY_NET_GetReceivedData(P(944),p+972,720);
            if(v==1) {
                v=MYSTERY_NET_ImportRecords((char *)p+972,P(952),32797);
                if(func_021D9554((char *)(p+972),v)) *state=5;
                else *state=12;
            } else if(v==2) *state=2;
        }
        v=MYSTERY_NET_UpdateWifiError(P(944));
        switch(v) {case 1:case 2:MYSTERY_NET_Exit(P(944));func_021DA8B0(task,(u32)func_021D6E3C);break;}
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
        func_021D9F08(P(644),W(932),136,2);
        func_021DA8C0(task,3);*state=14;break;
    case 3:
        W(964)++;
        if(MYSTERY_NET_GetAction(P(944))==0 && W(964)>30) {
            W(964)=0;
            func_021D9F08(P(644),W(932),139,1);
            func_021DA8C0(task,4);*state=14;
        }
        break;
    case 4:func_021DA8B0(task,(u32)func_021D6E3C);break;
    case 5:
        func_021D81B0(p,2,29);func_021D83DC(p,29);
        func_021D9F08(P(644),W(932),106,0);*state=6;break;
    case 6:
        flag=0;v=func_021D83B0((char *)p);
        if(v!=-1) {
        if(v==0) {
            func_021D9F08(P(644),W(932),110,1);
            func_021DA8C0(task,7);*state=14;
        } else if(v==-2) flag=1;
        } else if(KEY_GetTrg()&2) flag=1;
        if(flag) {
            func_021D9F08(P(644),W(932),107,1);
            func_021DA8C0(task,9);*state=14;
        }
        break;
    case 7:func_021D8138(p,0,29);*state=8;break;
    case 8:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) {
                func_021D8380((char *)p);
                if(((Flag *)(p+1152))->bit && MYSTERY_DATA_IsEventFlag(P(956),((struct Obj13939 *)p)->f47C)) {*state=11;break;}
                GF_STANDARD_SetField00_F4E4((struct RtcDate *)(&date));
                W(1144)=(((u32)date.y+2000)<<16)|(((u32)date.m<<24)>>16)|(u8)date.d;
                MYSTERY_DATA_AddCard(P(956),p+972);
                MYSTERY_DATA_SetEventFlag(P(956),((struct Obj13939 *)p)->f47C);
                func_021DA8B0(task,(u32)func_021D7814);
            } else if(v==1) *state=5;
        }
        break;
    case 9:func_021D8138(p,0,29);*state=10;break;
    case 10:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) {
                func_021D8380((char *)p);func_021D849C((char *)p);
                func_021DA8B0(task,(u32)func_021D6E3C);
            } else if(v==1) *state=5;
        }
        break;
    case 11:
        func_021D9F08(P(644),W(932),138,1);
        func_021DA8C0(task,13);*state=14;break;
    case 12:
        func_021D9F08(P(644),W(932),144,1);
        func_021DA8C0(task,13);*state=14;break;
    case 13:
        func_021D8380((char *)p);func_021D849C((char *)p);
        func_021DA8B0(task,(u32)func_021D6E3C);break;
    case 14:
        if(func_021D9FF8(P(644))) func_021DA8C4(task);
        break;
    }
}

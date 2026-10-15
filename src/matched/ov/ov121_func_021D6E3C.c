/*
 * function: func_021D6E3C
 * address: 0x021D6E3C
 * packet: pkt_ov121_021D6E3C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202EB44 0x0202EB44 thumb
 *   func_021DA84C 0x021DA84C thumb ov121
 *   MYSTERY_NET_GetResult 0x021DE4D8 thumb ov121
 *   func_021D80F0 0x021D80F0 thumb ov121
 *   func_021D7B4C 0x021D7B4C thumb ov121
 *   func_021D72F0 0x021D72F0 thumb ov121
 *   func_021D6DF4 0x021D6DF4 thumb ov121
 *   func_021D7EAC 0x021D7EAC thumb ov121
 *   func_021D73DC 0x021D73DC thumb ov121
 *   func_021D7CF4 0x021D7CF4 thumb ov121
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
 *   func_0203F4E4 0x0203F4E4 arm
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
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern int MYSTERY_NET_GetAction(void *);
extern int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
extern int MYSTERY_NET_ImportRecords(char *,void *,u16);
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
extern void func_021D7814(void *task, u32 *state, u8 *p);
extern u32 KEY_GetTrg(void);
extern void func_0203F4E4(struct RtcDate *date);
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
extern int func_0202EB44(void);
extern void *MYSTERY_NET_GetResult(char *p);
extern void func_021DA84C(u8 *p, u32 i, u32 value);
extern void func_021D80F0(void *a, int *state, u8 *p);
extern void func_021D7B4C(void *task, u32 *state, u8 *p);
extern void func_021D72F0(void *a, int *state, char *p);
extern void func_021D6DF4(void *a, int *state);
extern void func_021D7EAC(void *task, u32 *state, u8 *p);
extern void func_021D73DC(void *task, u32 *state, u8 *p);
extern void func_021D7CF4(void *task, u32 *state, u8 *p);
void func_021D6E3C(void *task,u32 *state,u8 *p)
{
    int v,flag,all,id;
    u32 i;
    switch(*state) {
    case 0:
        if(W(968)) {W(968)=0;*state=2;break;}
        func_021D9F08(P(644),W(932),79,0);
        if(P(624)==0) func_021D81B0(p,0,29);
        *state=1;break;
    case 1:
        v=func_021D83B0((char *)p);
        if(v!=-1) {
        if(v==0) {
            all=1;
            func_021D8380((char *)p);
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
                    func_021D9F08(P(644),W(932),id,1);
                    func_021DA8C0(task,0);*state=19;
                } else *state=16;
            } else {
                if(func_0202EB44()==0) func_021DA8B0(task,(u32)func_021D80F0);
                else *state=2;
            }
        } else if(v==1) {
            func_021D8380((char *)p);func_021DA8B0(task,(u32)func_021D7B4C);
        } else if(v==2) {
            func_021D8380((char *)p);func_021DA8B0(task,(u32)func_021D72F0);
        } else if(v==3) func_021DA8B0(task,(u32)func_021D6DF4);
        else break;
        }
        break;
    case 2:
        func_021D9F08(P(644),W(932),83,1);
        func_021DA8C0(task,3);*state=19;break;
    case 3:func_021D8138(p,0,29);*state=4;break;
    case 4:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) *state=5;else if(v==1) *state=0;
        }
        break;
    case 5:MYSTERY_NET_SetAction(P(944),1);*state=6;break;
    case 6:if(MYSTERY_NET_GetAction(P(944))==2) *state=7;break;
    case 7:
        func_021D8380((char *)p);func_021D81B0(p,1,29);
        func_021D9F08(P(644),W(932),86,0);*state=8;break;
    case 8:
        if(((u32)MYSTERY_NET_GetResult(P(944)))&32) func_021DA84C(P(624),0,1);
        else func_021DA84C(P(624),0,0);
        v=func_021D83B0((char *)p);
        if(v!=-1) {
        func_021D8380((char *)p);
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
        case 0:func_021D9F08(P(644),W(932),96,1);func_021DA8C0(task,10);*state=19;break;
        case 1:break;
        case 2:func_021D9F08(P(644),W(932),102,1);func_021DA8C0(task,10);*state=19;break;
        }
        break;
    case 10:func_021D8138(p,0,29);*state=11;break;
    case 11:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) *state=12;else if(v==1) *state=7;
        }
        break;
    case 12:
        if(MYSTERY_NET_GetAction(P(944))==2) {MYSTERY_NET_SetAction(P(944),3);*state=13;}
        break;
    case 13:
        if(MYSTERY_NET_GetAction(P(944))==0) {
            if(W(940)==1) func_021DA8B0(task,(u32)func_021D7EAC);
            else func_021DA8B0(task,(u32)func_021D73DC);
        }
        break;
    case 14:
        if(MYSTERY_NET_GetAction(P(944))==2) {MYSTERY_NET_SetAction(P(944),3);*state=15;}
        else *state=0;
        break;
    case 15:if(MYSTERY_NET_GetAction(P(944))==0) *state=0;break;
    case 16:
        func_021D9F08(P(644),W(932),141,1);
        func_021DA8C0(task,17);*state=19;break;
    case 17:func_021D8138(p,0,29);*state=18;break;
    case 18:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) func_021DA8B0(task,(u32)func_021D7CF4);
            else if(v==1) *state=0;
        }
        break;
    case 19:if(func_021D9FF8(P(644))) func_021DA8C4(task);break;
    }
}

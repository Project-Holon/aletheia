/*
 * function: BR_CODEIN_SoclStep
 * address: 0x021E26B8
 * packet: pkt_ov183_021E26B8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: p is a plain (non-const) pointer, so the case 0 Pair copy and the case 5 loop schedule as in the original; the loop counter is set before the arg local (i=1; arg=...; for(;i<=3;i++)).
 * note: 2026-10-05 recoup P25L4: the older DIFF draft (21 bytes) became 4 bytes when const was dropped from p, and EXACT with i=1 written before arg.
 * symbols:
 *   BR_CODEIN_SOCL_InitDefault 0x021E2F98 thumb ov183
 *   BR_CODEIN_CallStoredFnA 0x021E2E30 thumb ov183
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetVideoReply 0x021FF698 thumb ov186
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_SetData 0x0200B938 thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_CODEIN_CallStoredFnB 0x021E2E48 thumb ov183
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_MenuStep 0x021E2910 thumb ov183
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef enum { STATE_ZERO=0, STATE_TWELVE=12 } State;
typedef struct {u32 a,b;} Pair;
typedef struct {u32 words[2];} Request;
typedef struct {u32 fields[7];Pair request;} Arg;
typedef unsigned char  u8;
struct Big;
struct SOCLResource;
extern void BR_CODEIN_SOCL_InitDefault(struct SOCLResource *resource);
extern void BR_CODEIN_CallStoredFnA(char *,int,int);
extern void BR_FADE_Start(int,int,int,int);extern int BR_FADE_GetResult(int *);
extern void MI_CpuFill8(void *,int,u32);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *p);
extern int BR_NET_PollErrorMessage(char *p, int *out);
extern int BR_NET_GetVideoReply(char *p, int a1, int *out);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *BATTLE_REC_GetHeader(void);
extern void BATTLE_REC_SetData(const void *,const void *,const void *,void *);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_UTIL_StartEffect(int,int,Pair *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BR_CODEIN_CallStoredFnB(char *p, int a, int b);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_MenuStep(int *task, int *state, char *p);
extern int BR_UTIL_ClearTaskStep(int *a);
void BR_CODEIN_SoclStep(int *task,State *state,char *p) {
    u32 req[2];
    u32 msg;
    int extra;char *rec;
    u32 x,y;Pair click,cb;
    int result,found,i;
    u64 value;char *arg;
    switch(*state) {
    case 0:
        BR_CODEIN_SOCL_InitDefault((struct SOCLResource *)(&cb));arg=*(char **)(p+0x3c);*(Pair *)(p+0x4c)=cb;
        BR_CODEIN_CallStoredFnA((char *)p+0x4c,(int)p,(int)arg);*state=1;break;
    case 1:BR_FADE_Start(**(int **)(p+0x3c),2,3,0);*state=2;break;
    case 2:if(BR_FADE_GetResult((int *)**(int **)(p+0x3c)))*state=3;break;
    case 3:
        MI_CpuFill8(req,0,8);*(u64 *)req=*(u64 *)(*(char **)(p+0x3c)+0x1c);
        BR_NET_StartRequest(*(void **)(*(char **)(p+0x3c)+12),3,(const int *)req);
        *(u32 *)(p+0x44)=0;*state=4;break;
    case 4:
        ++*(u32 *)(p+0x44);
        if(BR_NET_IsIdle(*(void **)(*(char **)(p+0x3c)+12)) && *(u32 *)(p+0x44)>96) {
            BR_UTIL_StartEffect(*(int *)(p+0x30),0,0);*state=5;
        }break;
    case 5:
        result=BR_NET_PollErrorMessage(*(void **)(*(char **)(p+0x3c)+12),(int *)(&msg));
        if(result==0) {
            if(BR_NET_GetVideoReply(*(void **)(*(char **)(p+0x3c)+12),(int)(&rec),&extra)) {
                BATTLE_REC_SetData(rec,rec+0x80,rec+0xc4,GAME_DATA_GetSaveControl(*(void **)(*(char **)(p+0x3c)+0x14)));
                found=0;value=BATTLE_REC_GetHeaderParam(BATTLE_REC_GetHeader(),4,0);
                i=1;arg=*(char **)(p+0x3c);
                for(;i<=3;i++) {
                    if(*(u64 *)(*(char **)(arg+0x18)+i*8+0x30)==value) {found=1;break;}
                }
                if(found==1) {BR_UTIL_SetWindowText((char *)(*(int *)(p+8)),(char *)(*(int *)(arg+8)),(void *)316);*state=9;}
                else *state=6;
            } else {BR_UTIL_SetWindowText((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)339);*state=9;}
        } else {BR_UTIL_SetWindowText((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)msg);*state=9;}
        break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);click.a=x;click.b=y;BR_UTIL_StartEffect(*(int *)(p+0x34),1,&click);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=10;
        }break;
    case 6:BR_FADE_Start(**(int **)(p+0x3c),2,3,1);*state=7;break;
    case 7:if(BR_FADE_GetResult((int *)**(int **)(p+0x3c)))*state=8;break;
    case 8:BR_CODEIN_CallStoredFnB((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_MenuStep);break;
    case 10:BR_FADE_Start(**(int **)(p+0x3c),2,3,1);*state=11;break;
    case 11:if(BR_FADE_GetResult((int *)**(int **)(p+0x3c)))*state=12;break;
    case 12:BR_CODEIN_CallStoredFnB((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));BR_UTIL_ClearTaskStep(task);break;
    }
}

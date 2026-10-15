/*
 * function: func_021DBFB0
 * address: 0x021DBFB0
 * packet: pkt_ov183_021DBFB0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: shape copied from matched twin ov183_func_021DC228.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   func_021DCEE4 0x021DCEE4 thumb ov183
 *   func_021DC8EC 0x021DC8EC thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetVideoReply 0x021FF698 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   func_021DBD7C 0x021DBD7C thumb ov183
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct S S;
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern void func_021DCEE4(char *,char *),func_021DC8EC(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void MI_CpuFill8(void *,int,u32);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *p);
extern int BR_NET_PollErrorMessage(char *p, int *out);
extern int BR_NET_GetVideoReply(char *,int,int *);
extern void BR_UTIL_StartEffect(int,int,int *);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int BR_UTIL_ClearTaskStep(int *a);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void func_021DBD7C(int *,int *,char *);
void func_021DBFB0(int *a,int *state,char *p)
{
    u64 t;
    int message;
    char *source;
    int index;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        BR_UTIL_SetWindowText(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);*state=1;break;
    case 1: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=2;break;
    case 2: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=3;break;
    case 3:
        MI_CpuFill8(&t,0,8);
        t=*(u64 *)(*(char **)(p+0xd0)+0x1c);
        BR_NET_StartRequest(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=4;break;
    case 4:
        ++*(int *)(p+0xbc);
        if(BR_NET_IsIdle(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            BR_UTIL_StartEffect(*(int *)(p+12),0,0);*state=5;
        }
        break;
    case 5:
        if(!BR_NET_PollErrorMessage(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(BR_NET_GetVideoReply(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                *(char **)(p+0xc0)=source;
                *(char **)(p+0xc4)=source+0x80;*state=6;
            } else {
                BR_UTIL_SetWindowText(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            BR_UTIL_SetWindowText(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);args[0]=x;args[1]=y;
            BR_UTIL_StartEffect(*(int *)(p+0x10),1,args);GFL_USE_PlaySeDefaultVolume(0x703);
            BR_PROC_SYS_PopEntry((unsigned int *)(*(S **)(*(char **)(p+0xd0)+0x14)));*state=12;
        }
        break;
    case 6: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=7;break;
    case 7:
        if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) {
            func_021DD0F4(p,*(char **)(p+0xd0));
            func_021DCEE4(p,*(char **)(p+0xd0));
            func_021DC8EC(p,*(char **)(p+0xd0));*state=8;
        }
        break;
    case 8: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=9;break;
    case 9: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10: BR_UTIL_SetTaskStep(a,(int)func_021DBD7C);break;
    case 12: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));BR_UTIL_ClearTaskStep((int *)a);break;
    }
}

/*
 * function: func_021DEE7C
 * address: 0x021DEE7C
 * packet: pkt_ov183_021DEE7C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker: ARM9 0200B98C thumb +017A has no outside code-start witness; scratch 0200B98C-blocker2.log EXACT. No overlay leaves filed.
 * tu: --suggest-split leaves this caller out (MATCH, 608 bytes, 24/25 resolved); sole unresolved site remains ARM9 0200B98C +017A.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned short u16;
 *   typedef unsigned char u8;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 three-input u64 ARM9 accessor and caller-read 35C60 return retained; 2 EDB4 twin, eight-byte Pair assignment fixes 4-byte swap; 3 x/y signedness each unchanged; 4 enum offset restores retained 1718 constant and spill; 5 fresh idioms and neighbours, bounded permuter 300 unchanged 608/4 baseline agrees. Aggregate Pair structural check yields MATCH.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetSearchResultsForRanking 0x021FF6DC thumb ov186
 *   BR_NET_GetSearchResultsForNewest 0x021FF704 thumb ov186
 *   BR_NET_GetSearchResults 0x021FF6B4 thumb ov186
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   func_021DF18C 0x021DF18C thumb ov183
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   d_021E3964 0x021E3964 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Pair { u32 x,y; };
struct Data { u8 pad[0x1718]; int count; u32 selected; };
extern const char d_021E3964[];
extern void MI_CpuFill8(void *,int,int),func_02034714(const char *,u32,const char *);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *);
extern int BR_NET_PollErrorMessage(char *p, int *out);
extern int BR_NET_GetSearchResultsForRanking(char *p, void *buffer, int count, int *out);
extern int BR_NET_GetSearchResultsForNewest(char *p, void *buffer, int count, int *out);
extern int BR_NET_GetSearchResults(char *p, void *buffer, int count, int *out);
extern void BR_UTIL_StartEffect(int,int,struct Pair *);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void func_021DF18C(int *p, int *state, char *q);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern void GFL_USE_PlaySeDefaultVolume(u32),BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern int BR_UTIL_ClearTaskStep(int *a);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
void func_021DEE7C(int *task,u32 *state,char *p)
{
    switch(*state) {
    case 0: {
        struct Pair initial;
        int mode;
        MI_CpuFill8(&initial,0,8);
        switch(**(u32 **)(p+0x108)) {
        case 0: mode=5; break;
        case 1: mode=6; break;
        case 2: mode=7; break;
        case 3: initial=*(struct Pair *)(*(char **)(p+0x108)+0x20); mode=4; break;
        default: func_02034714(d_021E3964,0,d_021E3964); break;
        }
        MI_CpuFill8(*(void **)(*(char **)(p+0x108)+0x1c),0,0x1720);
        *(u32 *)(p+0xfc)=0;
        BR_NET_StartRequest(*(void **)(*(char **)(p+0x108)+0x18),mode,(const int *)(&initial));
        *state=1; break;
    }
    case 1:
        ++*(u32 *)(p+0xfc);
        if(BR_NET_IsIdle(*(char **)(*(char **)(p+0x108)+0x18)) && *(u32 *)(p+0xfc)>96) {
            BR_UTIL_StartEffect(*(int *)(p+0x1c),0,0); *state=2;
        } break;
    case 2: {
        int message,success,i;
        struct Data *data;
        enum { COUNT_OFFSET=0x1718 } offset;
        data=*(struct Data **)(*(char **)(p+0x108)+0x1c);
        offset=COUNT_OFFSET;
        if(!BR_NET_PollErrorMessage(*(void **)(*(char **)(p+0x108)+0x18),&message)) {
            switch(**(u32 **)(p+0x108)) {
            case 0: success=BR_NET_GetSearchResultsForRanking(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 1: success=BR_NET_GetSearchResultsForRanking(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 2: success=BR_NET_GetSearchResultsForNewest(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 3: success=BR_NET_GetSearchResults(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            default: func_02034714(d_021E3964,0,d_021E3964); break;
            }
            if(success) {
                for(i=0;i<(*(struct Data **)(*(char **)(p+0x108)+0x1c))->count;i++) {
                    *(u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i+0x16f8)=(u8)BATTLE_REC_GetHeaderParam((u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i*0xc4+0x80),5,0);
                }
                BR_UTIL_SetTaskStep(task,(int)func_021DF18C);
            } else {
                if(**(u32 **)(p+0x108)==3) BR_UTIL_SetWindowText(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)276);
                else BR_UTIL_SetWindowText(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)339);
                *state=3;
            }
        } else {
            BR_UTIL_SetWindowText(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)message);
            *state=3;
        } break;
    }
    case 3: {
        u32 x,y;
        struct Pair clicked;
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);
            clicked.x=x; clicked.y=y;
            BR_UTIL_StartEffect(*(int *)(p+0x20),1,&clicked);
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_FADE_Start(*(int *)(*(char **)(p+0x108)+8),2,3,1);
            *state=4;
        } break;
    }
    case 4:
        if(BR_FADE_GetResult(*(int **)(*(char **)(p+0x108)+8))) *state=5;
        break;
    case 5:
        BR_PROC_SYS_PopEntry(*(void **)(*(char **)(p+0x108)+0x14)); BR_UTIL_ClearTaskStep((int *)task); break;
    }
}

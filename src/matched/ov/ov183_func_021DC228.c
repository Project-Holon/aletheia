/*
 * function: func_021DC228
 * address: 0x021DC228
 * packet: pkt_ov183_021DC228
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker: 0x0200B98C ARM9 thumb +0102 no code-start witness; copied verified C from ov183_func_021DC4FC.c (DF838 blocker-r2.log EXACT).
 * diagnostic: ov186 0x021FF648 +013C resolved through a sibling's new shard in the TU; only ARM9 remains. TU --suggest-split leaves caller out.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: B938 retains caller-loaded r3; DD0AC/DD0F4 retain caller-loaded r1; 35C60 return is consumed.

 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetVideoReply 0x021FF698 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_SetData 0x0200B938 thumb
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBC68 0x021DBC68 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct S S;
typedef unsigned char  u8;
struct Big;
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern void func_021DCE28(char *,char *),func_021DCE48(char *,char *),func_021DD054(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern void func_021FD170(char *p, char *q, void *text);
extern void MI_CpuFill8(void *,int,u32);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *p);
extern int BR_NET_PollErrorMessage(char *p, int *out);
extern int BR_NET_GetVideoReply(char *,int,int *);
extern void func_021FD860(int,int,int *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void BATTLE_REC_SetData(const void *,const void *,const void *,unsigned int);
extern void func_021F9C50(S *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern int func_021FD744(int *a);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBC68(int a, int b, char *p);
void func_021DC228(int *a,int *state,char *p)
{
    u64 t;
    int message;
    int index;
    char *source;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2:
        if(*(int *)(p+0xb0)) func_021DCE28(p,*(char **)(p+0xd0));
        else func_021DCE48(p,*(char **)(p+0xd0));
        func_021DD054(p,*(char **)(p+0xd0));
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);
        *state=3;break;
    case 3: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=4;break;
    case 4: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=5;break;
    case 5:
        MI_CpuFill8(&t,0,8);
        t=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),4,0);
        BR_NET_StartRequest(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=6;break;
    case 6:
        ++*(int *)(p+0xbc);
        if(BR_NET_IsIdle(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860(*(int *)(p+12),0,0);*state=7;
        }
        break;
    case 7:
        if(!BR_NET_PollErrorMessage(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(BR_NET_GetVideoReply(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                BATTLE_REC_SetData(source,source+0x80,source+0xc4,(unsigned int)GAME_DATA_GetSaveControl(*(void **)(*(char **)(p+0xd0)+0x28)));
                **(long long **)(*(char **)(p+0xd0)+0x2c)=index;
                **(int **)(p+0xd0)=1;
                func_021F9C50(*(S **)(*(char **)(p+0xd0)+0x14));*state=8;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);args[0]=x;args[1]=y;
            func_021FD860(*(int *)(p+0x10),1,args);GFL_USE_PlaySeDefaultVolume(0x703);*state=12;
        }
        break;
    case 8: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=9;break;
    case 9: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10:
        if(!GFL_USE_IsSeqPlaying(0x701)) {func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)(*(int *)(p+8)));}
        break;
    case 12: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}

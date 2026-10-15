/*
 * function: BR_CODEIN_RecordStepMenu
 * address: 0x021DBD7C
 * packet: pkt_ov183_021DBD7C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: decode each callback literal from its actual PC-relative pool slot; repeated shared loads obscure distinct callback targets.
 * blocker: ARM9 0200B98C lacks outside code-start witness, call +00B6 wildcard; TU --suggest-split leaves caller out.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
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
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_CODEIN_RecordHitButtonA 0x021DD27C thumb ov183
 *   BR_CODEIN_RecordHitButtonB 0x021DD2BC thumb ov183
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_PROC_SYS_SetupWindow 0x021F9C50 thumb ov186
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_RecordStepProfileText 0x021DBEB0 thumb ov183
 *   BR_CODEIN_RecordStepFadeInB 0x021DBCF4 thumb ov183
 *   BR_CODEIN_RecordStepReceive 0x021DC228 thumb ov183
 *   BR_CODEIN_RecordStepConfirm 0x021DC638 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {char pad[0x4c];char saved[0x18];int count;void *ptr;} S;
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern int BR_CODEIN_RecordHitButtonA(char *,int,int),BR_CODEIN_RecordHitButtonB(char *,int,int);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int,int,int *);
typedef unsigned char  u8;
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern void BR_PROC_SYS_PushEntry(unsigned *,unsigned);
extern void BR_PROC_SYS_SetupWindow(S *);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_RecordStepProfileText(int *task, int *state, char *p);
extern void BR_CODEIN_RecordStepFadeInB(int *task, int *state, char *p);
extern void BR_CODEIN_RecordStepReceive(int *a, int *state, char *p);
extern void BR_CODEIN_RecordStepConfirm(int *a, int *state, char *p);
void BR_CODEIN_RecordStepMenu(int *task,int *state,char *p)
{
    u32 x,y;
    if(TOUCHPANEL_GetPointTrg(&x,&y)) {
        if(BR_CODEIN_RecordHitButtonA(p,x,y)) {
            *(int *)(p+0xb0)^=1;
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepProfileText);
        }
        if(BR_BTN_HitTestWithSound((unsigned int *)(*(int *)(p+0x1c)),x,y)) {
            int args[2];
            args[0]=x;args[1]=y;
            BR_UTIL_StartEffect(*(int *)(p+0x10),1,args);
            **(int **)(p+0xd0)=0;
            BR_PROC_SYS_PopEntry(*(void **)(*(char **)(p+0xd0)+0x14));
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepFadeInB);
        }
        if(*(int *)(p+0x20) && BR_BTN_HitTestWithSound((unsigned int *)(*(int *)(p+0x20)),x,y)) {
            int args[2];
            args[0]=x;args[1]=y;
            BR_UTIL_StartEffect(*(int *)(p+0x10),1,args);
            BR_PROC_SYS_PushEntry(*(unsigned **)(*(char **)(p+0xd0)+0x14),10);
            *(u64 *)(*(char **)(p+0xd0)+0x1c)=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),4,0);
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepFadeInB);
        }
        if(BR_CODEIN_RecordHitButtonB(p,x,y)) {
            if((u32)(*(u32 *)(*(char **)(p+0xd0)+8)-4)<=1)BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepReceive);
            else if(*(int *)(p+0xc8)==0)BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepConfirm);
            else {
                **(int **)(p+0xd0)=1;
                BR_PROC_SYS_SetupWindow(*(S **)(*(char **)(p+0xd0)+0x14));
                BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepFadeInB);
            }
        }
    }
}

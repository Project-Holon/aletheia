/*
 * function: BR_CODEIN_RecordStepSave
 * address: 0x021DC4FC
 * packet: pkt_ov183_021DC4FC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker: ARM9 0200B98C lacks code-start witness; own call +00DC unresolved. TU --suggest-split leaves caller out.
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
 * abi: DD0AC/DD0F4 keep the visibly loaded second descriptor argument despite body using only the first.
 * symbols:
 *   BR_CODEIN_RecordCreateTextWin 0x021DD0AC thumb ov183
 *   BR_CODEIN_RecordDeleteTextWin 0x021DD0F4 thumb ov183
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   GDS_RAP_SaveVideoSecured 0x021D7630 thumb ov125
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_RecordStepCreateProfile 0x021DBC68 thumb ov183
 *   d_021E3960 0x021E3960 data a1
 *   func_02034714 0x02034714 arm
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 */
typedef unsigned short u16;
extern void BR_CODEIN_RecordCreateTextWin(char *,char *),BR_CODEIN_RecordDeleteTextWin(char *,char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int GDS_RAP_SaveVideoSecured(void *a, int x, u16 *state, u16 *b, u16 c);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_RecordStepCreateProfile(int a, int b, char *p);
extern char d_021E3960[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void BATTLE_REC_DecodeWork(void);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
void BR_CODEIN_RecordStepSave(int *a,int *state,char *p)
{
    switch(*state) {
    case 0:
        BR_CODEIN_RecordCreateTextWin(p,*(char **)(p+0xd0));
        BR_UTIL_SetWindowText(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x152);
        BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);
        *state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2: *state=3;break;
    case 3: *(u16 *)(p+0xb6)=0;*(u16 *)(p+0xb8)=0;*state=4;break;
    case 4:
        if(*(int *)(*(char **)(p+0xd0)+8)>3) func_02034714(d_021E3960,0,d_021E3960);
        if(GDS_RAP_SaveVideoSecured((void *)(*(int *)(*(char **)(p+0xd0)+0x28)),*(int *)(*(char **)(p+0xd0)+8),(u16 *)(p+0xb6),(u16 *)(p+0xb8),*(u16 *)(p+0xb4))==2) {
            BATTLE_REC_DecodeWork();
            *(int *)(p+0xc8)=(int)BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),5,0);
            *state=5;
        }
        break;
    case 5: BR_FADE_Start((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=6;break;
    case 6: if(BR_FADE_GetResult(*(int **)(*(char **)(p+0xd0)+12))) *state=7;break;
    case 7: BR_CODEIN_RecordDeleteTextWin(p,*(char **)(p+0xd0));BR_UTIL_SetTaskStep(a,(int)BR_CODEIN_RecordStepCreateProfile);break;
    }
}

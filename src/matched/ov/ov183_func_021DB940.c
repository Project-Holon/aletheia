/*
 * function: BR_CODEIN_RecordCreate
 * address: 0x021DB940
 * packet: pkt_ov183_021DB940
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker: ARM9 0200B98C lacks outside code-start witness, call +014E wildcard; TU --suggest-split leaves caller out.
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
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_RecordStepRequest 0x021DBFB0 thumb ov183
 *   BR_CODEIN_RecordStepSave 0x021DC4FC thumb ov183
 *   BR_CODEIN_RecordStepCreateProfile 0x021DBC68 thumb ov183
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 */
typedef unsigned int u32;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
typedef unsigned char  u8;
struct ObjC4;
extern void * BMP_OAM_CreateSys(unsigned,void *);
extern u32 PRINTSYS_QUE_Create(void *p);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern char *BR_UTIL_CreateHandles(unsigned,char *,int,int);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_RecordStepRequest(int *a, int *state, char *p);
extern void BR_CODEIN_RecordStepSave(int *a, int *state, char *p);
extern void BR_CODEIN_RecordStepCreateProfile(int a, int b, char *p);
extern char * BATTLE_REC_GetHeader(void);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
int BR_CODEIN_RecordCreate(int *task,int *state,char *q)
{
    char *p,*s;
    int i;
    p=PROCSYS_AllocProcWork((struct Obj0203159C *)task,0xe8,BR_PROC_SYS_GetSlotId((struct Obj24810 *)(*(char **)(q+0x14))));
    MI_CpuFill8(p,0,0xe8);
    *(unsigned short *)(p+0xb4)=BR_PROC_SYS_GetSlotId((struct Obj24810 *)(*(char **)(q+0x14)));
    *(int *)(p+0xb0)=0;
    *(char **)(p+0xd0)=q;
    *(void **)p=BMP_OAM_CreateSys(*(unsigned short *)(p+0xb4),*(void **)(q+0x18));
    *(void **)(p+4)=(void *)PRINTSYS_QUE_Create((void *)(*(unsigned short *)(p+0xb4)));
    *(void **)(p+8)=BR_UTIL_CreateTask((int)p,0,*(unsigned short *)(p+0xb4));
    for(i=0;i<2;i++) *(char **)(p+i*4+0xc)=BR_UTIL_CreateHandles(*(unsigned *)(q+0x18),*(char **)(q+0x10),i,*(unsigned short *)(p+0xb4));
    switch(*(int *)(*(char **)(p+0xd0)+8)) {
    case 4:
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc4)=s+*(int *)(s+0x171c)*0xc4+0x80;
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc0)=s+*(int *)(s+0x171c)*0xc4;
        *(int *)(p+0xcc)=1;
        if(**(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(*(char **)(p+0xd0)+0x34)) {
            s=*(char **)(*(char **)(p+0xd0)+0x30);
            *(s+*(int *)(s+0x171c)+0x16f8)=1;
        }
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(int *)(p+0xc8)=*(unsigned char *)(s+*(int *)(s+0x171c)+0x16f8);
        break;
    case 0:
        *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
        *(int *)(p+0xc8)=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
        *(int *)(p+0xc8)=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),5,0);*(int *)(p+0xcc)=0;break;
    case 5:
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0) {
            *(int *)(p+0xc4)=0;*(int *)(p+0xc0)=0;
        }else {
            *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
            *(int *)(p+0xc8)=**(int **)(*(char **)(p+0xd0)+0x3c);
        }
        i=1;
    set_cc:
        *(int *)(p+0xcc)=i;
        break;
    }
    if(*(int *)(*(char **)(p+0xd0)+8)==5) {
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0)BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepRequest);
        else BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepCreateProfile);
    }else if((u32)(*(int *)(*(char **)(p+0xd0)+8)-1)<=2 && *(int *)(*(char **)(p+0xd0)+0x34) && **(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(p+0xc8)==0) {
        BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepSave);
    }else BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepCreateProfile);
    return 1;
}

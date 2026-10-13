/*
 * function: IRC_RHYTHM_StateAbort
 * address: 0x021B8528
 * packet: pkt_ov104_021B8528
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 174 code bytes then two zero alignment bytes before 021B85D8.
 * symbols:
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_RHYTHM_Finish 0x021B818C thumb ov104
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 *   IRC_RHYTHM_PrintMessage 0x021B7F1C thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *p);
extern int COMPATIBLE_IRC_SYS_StepShareValue(int *p, int value);
extern void IRC_RHYTHM_Finish(u8 *);
extern void IRC_RHYTHM_PrintMessage(u8 *,void *,int,int,s16);
#define CTX(p) (*(u8 **)((p)+0x8b0))
void IRC_RHYTHM_StateAbort(u8 *p,u16 *state) { switch(*state) { case 0: if(COMPATIBLE_IRC_SYS_GetValueDifference(*(void **)(CTX(p)+4))>0) { CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=1; IRC_RHYTHM_Finish(p); return; } if(COMPATIBLE_IRC_SYS_GetValueDifference(*(void **)(CTX(p)+4))<0) *state=1; break; case 1: CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=2; *state=2; break; case 2: IRC_RHYTHM_PrintMessage(p+0xcc,p+0xbc,4,0,0); *state=3; break; case 3: if(COMPATIBLE_IRC_SYS_StepShareValue(*(void **)(CTX(p)+4),6)) *state=4; break; case 4: IRC_RHYTHM_Finish(p); break; } }

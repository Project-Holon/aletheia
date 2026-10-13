/*
 * function: FLDMMDL_ACMD_AnimeWaitEndFaceDown
 * address:  0x02199ED4
 * packet:   pkt_ov021_02199ED4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Former blocker (now filed in src/matched/arm9): BILLBOARD_ACT_GetEntryLastCommand (0x020508EC, arm9, unlabelled leaf, the integrator's).
 * Verified EXACT from a scratch file (region arm9, --arm, dsi/1.1p1 -O4,p):
 *
 *   u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out)
 *   {
 *       u16 v = *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x1c);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_AnimeWaitEndFaceDown(u32 a)
{
    u32 s;
    u32 r;
    u16 out;

    s = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)a)));
    r = FLDMMDL_CallDrawGetProc((void *)a, 0);
    if (r != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand((u8 *)s, (u16)r, &out) == 0) {
            return 0;
        }
    }
    FLDMMDL_SetDirDispCheckPause(a, 1);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}

/*
 * function: FLDMMDL_ACMD_AnimeWaitEnd
 * address:  0x02198F20
 * packet:   pkt_ov021_02198F20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted 2026-10-01: the arm9 leaf BILLBOARD_ACT_GetEntryLastCommand is now filed EXACT
 * (src/matched/arm9/BILLBOARD_ACT_GetEntryLastCommand.c), which witnesses the call.
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_AnimeWaitEnd(u32 a)
{
    u32 r;
    u16 out;

    FLDMMDL_GetMoveCmdWork((void *)a);
    r = FLDMMDL_CallDrawGetProc((void *)a, 0);
    if (r != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand((u8 *)FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)a))), (u16)r, &out) == 1) {
            FLDMMDL_IncAcmdSeq(a);
            return 1;
        }
    }
    return 0;
}

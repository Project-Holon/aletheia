/*
 * function: FLDMMDL_DRAW_CheckBlactReady
 * address:  0x0219FE20
 * packet:   pkt_ov021_0219FE20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: BILLBOARD_ACT_GetEntryLastCommand (0x020508EC) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out) reads a u16 at record+0x1C, stores it, returns a range test; see the pending ov021 files that already name it
 *
 * symbols:
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 FLDMMDL_GetObjCode(void *p);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out);

u32 FLDMMDL_DRAW_CheckBlactReady(u32 a, u32 a1, u32 a2, u32 a3)
{
    u32 t;
    u16 out;

    if (FLDMMDL_GetObjCode((void *)a) != 0x7B) {
        return 1;
    }
    t = (u16)FLDMMDL_CallDrawGetProc((void *)a, 0);
    if (t != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand((u8 *)FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a)), t, &out) == 1) {
            return 1;
        }
    }
    return 0;
}

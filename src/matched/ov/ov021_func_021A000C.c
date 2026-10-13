/*
 * function: FLDMMDL_DRAW_UpdateBlactFlags
 * address:  0x021A000C
 * packet:   pkt_ov021_021A000C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: BILLBOARD_ACT_SetEntryEnabled (0x020507F0) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   void BILLBOARD_ACT_SetEntryEnabled(u8 *p, int i, u32 v) { *(u32 *)(*(u8 **)(p + 0x18) + i * 40 + 0x18) = v; }  (EXACT, verified)
 *
 * symbols:
 *   BILLBOARD_ACT_SetEntryFlags  0x020507A0  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   FLDMMDL_ACMD_CheckAnimePaused  0x02197C9C  thumb  ov021
 *   FLDMMDL_BLACT_GetEntryHookFlag  0x0219C648  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int FLDMMDL_BLACT_GetEntryHookFlag(u32 a);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_ACMD_CheckAnimePaused(u32 a);
extern int FLDMMDL_CheckStatusBitVanish(void *a0);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
extern int BILLBOARD_ACT_SetEntryFlags(void *p, int idx, u32 x);

void FLDMMDL_DRAW_UpdateBlactFlags(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 f;
    u32 k;

    f = 1;
    k = FLDMMDL_BLACT_GetEntryHookFlag(a);
    if (d == 0) {
        if (e == 1) {
            if (k == 1 && FLDMMDL_CheckStatusBit(a, 0x10) != 0) f = 0;
        } else {
            if (k == 1 && FLDMMDL_ACMD_CheckAnimePaused(a) == 1) f = 0;
        }
    }
    BILLBOARD_ACT_SetEntryEnabled((void *)b, c, f);
    f = 1;
    if (FLDMMDL_CheckStatusBitVanish((void *)a) == 1) f = 0;
    BILLBOARD_ACT_SetEntryFlags((void *)b, c, f);
}

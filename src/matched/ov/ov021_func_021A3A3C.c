/*
 * function: FIELD_PLAYER_CORE_CheckAnimePaused
 * address:  0x021A3A3C
 * packet:   pkt_ov021_021A3A3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: relocation evidence, BILLBOARD_ACT_GetEntryLastCommand (0x020508EC, arm9 ARM leaf,
 * the integrator's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --arm --region arm9:
 *   int BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 0x28;
 *       u16 v = *(u16 *)(e + 0x1C);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb
 *   FLDMMDL_ACMD_CheckAnimePaused  0x02197C9C  thumb
 *   FLDMMDL_BLACT_GetEntryHookFlag  0x0219C648  thumb
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern int FLDMMDL_ACMD_CheckAnimePaused(u32 a);
extern int FLDMMDL_BLACT_GetEntryHookFlag(u32 a);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(u8 *p, int i, u16 *out);

int FIELD_PLAYER_CORE_CheckAnimePaused(u32 *p)
{
    u16 v;
    u32 h;
    u32 k;

    h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)p[7])));
    if (FLDMMDL_ACMD_CheckAnimePaused(p[7]) == 1 && FLDMMDL_BLACT_GetEntryHookFlag(p[7]) == 1)
        return 1;
    k = FLDMMDL_CallDrawGetProc((void *)p[7], 0);
    if (k != 0xFFFF && BILLBOARD_ACT_GetEntryLastCommand((u8 *)h, (u16)k, &v) != 0 && v == (0xFFFF >> 2))
        return 1;
    return 0;
}

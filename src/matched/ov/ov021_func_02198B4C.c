/*
 * function: FLDMMDL_ACMD_MarkInit
 * address:  0x02198B4C
 * packet:   pkt_ov021_02198B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetFieldMap(void *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FLDEFF_GYOE_SetMMdl(u32, u32, u32, u32);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

void FLDMMDL_ACMD_MarkInit(u32 a, u32 b, u32 a3)
{
    u32 *p;

    p = FLDMMDL_InitMoveCmdWork(a, 8, a3);
    p[0] = b;
    p[1] = FLDEFF_GYOE_SetMMdl(FIELDMAP_GetEffect((u8 *)FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys((void *)a))), a, b, 1);
    FLDMMDL_IncAcmdSeq((u8 *)a);
}

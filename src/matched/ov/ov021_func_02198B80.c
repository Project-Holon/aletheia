/*
 * function: FLDMMDL_ACMD_MarkWait
 * address:  0x02198B80
 * packet:   pkt_ov021_02198B80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern int FLDEFF_GYOE_IsFinished(u32);
extern void FIELD_EFFECT_DeleteObject(u32);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

int FLDMMDL_ACMD_MarkWait(u32 a)
{
    u32 *p;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    if (FLDEFF_GYOE_IsFinished(p[1]) == 1) {
        FIELD_EFFECT_DeleteObject(p[1]);
        FLDMMDL_IncAcmdSeq((u8 *)a);
        return 1;
    }
    return 0;
}

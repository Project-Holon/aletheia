/*
 * function: FLDMMDL_ACMD_DrawIfInitialized
 * address:  0x02197C78
 * packet:   pkt_ov021_02197C78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysCheckStatusBit  0x0216D4D4  thumb  ov010
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysCheckStatusBit(int a0, int a1);
extern int FLDMMDL_CheckMoveBitDrawInitComp(void *a0);
extern void FLDMMDL_CallDrawProc(void *a0);

void FLDMMDL_ACMD_DrawIfInitialized(u32 a)
{
    if (FLDMMDL_SysCheckStatusBit((int)FLDMMDL_GetMmdlSys((void *)a), 4) == 0 && FLDMMDL_CheckMoveBitDrawInitComp((void *)a) != 0) {
        FLDMMDL_CallDrawProc((void *)a);
    }
}

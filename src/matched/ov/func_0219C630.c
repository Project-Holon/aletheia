/*
 * function: FLDMMDL_BLACT_IsReservePending
 * address:  0x0219C630
 * packet:   pkt_0219C630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_CheckReserveLeft  0x0219CCF0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern int FLDMMDL_BLACT_CheckReserveLeft(u8 *s);

int FLDMMDL_BLACT_IsReservePending(void *p)
{
if (FLDMMDL_BLACT_CheckReserveLeft((u8 *)FLDMMDL_SysGetBlActCont(p)) == 1) {
    return 1;
}
return 0;
}


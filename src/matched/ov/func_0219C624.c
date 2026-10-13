/*
 * function: FLDMMDL_BLACT_RegisterLoadedRes
 * address:  0x0219C624
 * packet:   pkt_0219C624
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_RegisterAddRes  0x0219CEAC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 FLDMMDL_BLACT_RegisterAddRes(u32);

int FLDMMDL_BLACT_RegisterLoadedRes(void *p)
{
return FLDMMDL_BLACT_RegisterAddRes(FLDMMDL_SysGetBlActCont(p));
}


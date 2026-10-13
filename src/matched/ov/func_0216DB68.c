/*
 * function: FLDMMDL_CheckStatusBitHeightGetOff
 * address:  0x0216DB68
 * packet:   pkt_0216DA5C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_CheckStatusBitHeightGetOff.c \
 *       --func FLDMMDL_CheckStatusBitHeightGetOff --addr 0x0216DB68 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckStatusBit(int a0, int a1);

int FLDMMDL_CheckStatusBitHeightGetOff(void *a0)
{
    if (FLDMMDL_CheckStatusBit((int)a0, 512))
        return 1;
    return 0;
}

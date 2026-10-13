/*
 * function: FLDMMDL_CheckMoveBitAcmd
 * address:  0x0216DC4C
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
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010

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
 *   python tools/match.py one --src src/matched/FLDMMDL_CheckMoveBitAcmd.c \
 *       --func FLDMMDL_CheckMoveBitAcmd --addr 0x0216DC4C --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);

int FLDMMDL_CheckMoveBitAcmd(void *a0)
{
    if (FLDMMDL_CheckMoveBit(a0, 512))
        return 1;
    return 0;
}

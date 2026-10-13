/*
 * function: FLDMMDL_SetAttrOffset
 * address:  0x0216D900
 * packet:   pkt_0216D89C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Twelve-byte struct copy between an interior member of the
 * object and a caller-supplied 3-word record: the compiler
 * emits ldm/stm plus the odd word.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_SetAttrOffset.c \
 *       --func FLDMMDL_SetAttrOffset --addr 0x0216D900 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct { u32 a, b, c; } Triple;

void FLDMMDL_SetAttrOffset(void *p, const Triple *q)
{
    *(Triple *)((char *)p + 104) = *q;
}

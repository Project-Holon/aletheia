/*
 * function: ENCEFF_Delete
 * address:  0x021CF480
 * packet:   pkt_021CF480
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
 *   ENCEFF_FreeWork  0x021CF54C  thumb  ov021
 *   ENCEFF_UnloadOverlays  0x021CF5AC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
struct Res021CF;
extern void ENCEFF_FreeWork(u8 *p);
extern void ENCEFF_UnloadOverlays(struct Res021CF *r);

int ENCEFF_Delete(void *a)
{
ENCEFF_FreeWork((u8 *)a);
ENCEFF_UnloadOverlays((struct Res021CF *)a);
return func_020307B0(a);
}


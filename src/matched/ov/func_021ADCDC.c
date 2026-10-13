/*
 * function: FLDEFF_IWAKUDAKI_Delete
 * address:  0x021ADCDC
 * packet:   pkt_021ADCDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FLDEFF_IWAKUDAKI_FreeResources  0x021ADD38  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Q;
extern void FLDEFF_IWAKUDAKI_FreeResources(struct Q *q);
extern u32 func_020307B0(void *p);

void FLDEFF_IWAKUDAKI_Delete(u32 a, u8 *p)
{
    FLDEFF_IWAKUDAKI_FreeResources((struct Q *)p);
    func_020307B0(p);
}

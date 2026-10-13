/*
 * function: DWC_CloseConnectionHardFromServer
 * address:  0x0216B7E0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns -3 when DWC_IsServerMyself rejects the pointer, else the DWCi_CloseConnectionHard result.
 *
 * symbols:
 *   DWC_IsServerMyself  0x0216BA08  arm  ov009
 *   DWCi_CloseConnectionHard  0x0216BEA4  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int DWC_CloseConnectionHardFromServer(void *p)
{
    int DWC_IsServerMyself(void);
    int DWCi_CloseConnectionHard(void *);
    if (DWC_IsServerMyself() == 0) return -3;
    return DWCi_CloseConnectionHard(p);
}

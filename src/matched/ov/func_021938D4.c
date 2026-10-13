/*
 * function: FIELD_WFBC_Delete
 * address:  0x021938D4
 * packet:   pkt_021938D4
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
 *   FIELD_WFBC_FreeResources  0x02193C80  thumb  ov021
 *   FLDMMDL_SysSetDrawEnable  0x0216D974  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void FLDMMDL_SysSetDrawEnable(unsigned int *p, unsigned int v);
struct X;
extern void FIELD_WFBC_FreeResources(struct X *x);

u32 FIELD_WFBC_Delete(void *a)
{
FIELD_WFBC_FreeResources((struct X *)a);
if (*(u32 *)((u8 *)(a) + ((5 << 6))) != 0) {
    FLDMMDL_SysSetDrawEnable((unsigned int *)(*(u32 *)((u8 *)(a) + ((5 << 6)))), 1);
}
return func_020307B0(a);
}


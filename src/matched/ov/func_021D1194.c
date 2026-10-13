/*
 * function: FIELD_SAVEANIME_Delete
 * address:  0x021D1194
 * packet:   pkt_021D1194
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
 *   FIELD_SAVEANIME_Stop  0x021D11D8  thumb  ov021
 *   FIELD_SAVEANIME_DeleteWindow  0x021D13F0  thumb  ov021
 *   FIELD_SAVEANIME_DeleteResource  0x021D1254  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void FIELD_SAVEANIME_Stop(u32 *p);
extern u32 FIELD_SAVEANIME_DeleteResource(u32);
extern u32 FIELD_SAVEANIME_DeleteWindow(u32);

int FIELD_SAVEANIME_Delete(void *a)
{
FIELD_SAVEANIME_Stop((u32 *)a);
FIELD_SAVEANIME_DeleteWindow((u32)a);
FIELD_SAVEANIME_DeleteResource((u32)a);
return func_020307B0(a);
}


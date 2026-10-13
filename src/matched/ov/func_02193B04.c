/*
 * function: FIELD_WFBC_SetUp
 * address:  0x02193B04
 * packet:   pkt_02193B04
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
 *   FIELD_WFBC_LoadResources  0x02193C08  thumb  ov021
 *   FIELD_WFBC_SetUpPeople  0x02193D30  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_WFBC_LoadResources(char *p, int heap);
extern u32 FIELD_WFBC_SetUpPeople(u32, u32, u32);

int FIELD_WFBC_SetUp(u32 a, u32 b, u32 c, u32 d)
{
FIELD_WFBC_LoadResources((char *)a, d);
return FIELD_WFBC_SetUpPeople(a, b, c);
}


/*
 * function: POKETRADE_3D_FreeParticleResources
 * address:  0x021E2F2C
 * packet:   pkt_ov119_021E2F2C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_3D_DeleteIcaStreams  0x021E2EA0  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void POKETRADE_3D_DeleteIcaStreams(char *p);
void POKETRADE_3D_FreeParticleResources(void *a0) { POKETRADE_3D_DeleteIcaStreams(a0); }

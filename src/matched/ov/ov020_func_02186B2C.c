/*
 * function: FIELD_WFBC_DATA_LOCAL_PushPersonFront
 * address: 0x02186B2C
 * packet: pkt_ov020_02186B2C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: unsigned index scaling retains separate source/destination multiplies.
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */

typedef unsigned int u32;
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
char *FIELD_WFBC_DATA_LOCAL_PushPersonFront(char *p, char *src) { int i; for (i = 9; i > 0; i--) MI_CpuCopy8(p + (u32)(i - 1) * 24, p + (u32)i * 24, 24); MI_CpuCopy8(src, p, 24); return p; }

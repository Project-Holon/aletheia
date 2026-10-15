/*
 * function: MONOLITH_TOOL_STATS_DeleteWindows
 * address: 0x021B8BF4
 * packet: pkt_ov071_021B8BF4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void MONOLITH_TOOL_STATS_DeleteWindows(void **p) { int i; for (i=0;i<6;i++) BMP_WIN_Delete(p[i]); }

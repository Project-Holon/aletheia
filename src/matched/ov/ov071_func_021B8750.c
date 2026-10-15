/*
 * function: MONOLITH_TOOL_SUMMARY_DeleteWindows
 * address: 0x021B8750
 * packet: pkt_ov071_021B8750
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
void MONOLITH_TOOL_SUMMARY_DeleteWindows(void **p) { BMP_WIN_Delete(p[0]); BMP_WIN_Delete(p[1]); }

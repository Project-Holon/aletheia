/*
 * function: MONOLITH_TOOL_DeleteInfoWindows
 * address: 0x021BA4D4
 * packet: pkt_ov071_021BA4D4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void MONOLITH_TOOL_DeleteInfoWindows(void **p) {
    int i;
    for (i = 0; i < 3; i++) func_020452E8(p[i]);
}

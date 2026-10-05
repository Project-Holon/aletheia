/*
 * function: func_021B817C
 * address: 0x021B817C
 * packet: pkt_ov104_021B817C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 12 bytes of code plus a 4 byte pool word (extent 16, label gap was 12).
 *       Stores r1 at +0x804 and zero halfword at +0x808. No callee, no relocation.
 */
typedef unsigned int u32;
typedef unsigned short u16;
void func_021B817C(char *p, u32 v) {
    *(u32 *)(p + 0x804) = v;
    *(u16 *)(p + 0x808) = 0;
}

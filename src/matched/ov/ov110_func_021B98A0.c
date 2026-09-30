/*
 * function: func_021B98A0
 * address: 0x021B98A0
 * packet: pkt_ov110_021B98A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the initial slot stores the running offset; preload the table entry before the store.
 * symbols:
 *   d_021C1C88 0x021C1C88 data ov110 a4
 *   func_021B98F8 0x021B98F8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *const d_021C1C88[];
extern u32 func_021B98F8(u8 *, u8 *, u16 *, u32);
void func_021B98A0(u8 *p) {
    u32 a = 0xF58;
    u32 b;
    u32 c;
    u32 i;
    u32 offset = 0;
    a -= 0x6C;
    b = 0xF58;
    b -= 0xD8;
    c = 0xF58;
    c -= 0xD8;
    for (i=0; i<27; ++i) {
        u8 *src = d_021C1C88[i];
        *(u32 *)(p+i*4+a) = offset;
        *(u32 *)(p+i*4+b) = func_021B98F8(p, src, (u16 *)(p+0xF58), offset);
        offset += *(u32 *)(p+i*4+c);
    }
}

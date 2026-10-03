/*
 * function: func_021E32C4
 * address:  0x021E32C4
 * packet:   pkt_ov119_021E32C4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020480E4  0x020480E4  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Ctx;
extern void func_020480E4(struct Ctx *c, u32 i);

void func_021E32C4(char *p)
{
    u16 v;

    v = *(u16 *)(p + 0x824);
    if (v != 0xFFFF)
        func_020480E4(*(void **)(p + 0x820), v);
    *(u16 *)(p + 0x824) = 0xFFFF;
}

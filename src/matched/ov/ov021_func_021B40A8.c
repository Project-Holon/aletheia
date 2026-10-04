/*
 * function: func_021B40A8
 * address:  0x021B40A8
 * packet:   pkt_ov021_021B40A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020452E8  0x020452E8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);

void func_021B40A8(u8 *w)
{
    int i;

    func_0201C6EC((struct PrintSys *)(*(u32 *)(w + 0x1B0)));
    func_0201C4C0((struct PrintSys *)(*(u32 *)(w + 0x1B0)));
    for (i = 0; i < 7; i++) {
        func_020452E8((struct Descriptor *)(*(u32 *)(w + 0x164 + i * 4)));
    }
}

/*
 * function: func_021F6EE8
 * address: 0x021F6EE8
 * packet: pkt_ov097_021F6EE8
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_FillRect 0x02043AF4 arm
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Bmp;
extern void BMP_FillRect(struct Bmp *, unsigned, unsigned, unsigned, unsigned, unsigned);
void func_021F6EE8(unsigned p, unsigned i)
{
    unsigned base = p + 0x20;
    BMP_FillRect(func_02045770(*(void **)(base + i * 8)), 0x40, 0x1b, 0x30, 1, 1);
    BMP_FillRect(func_02045770(*(void **)(base + i * 8)), 0x40, 0x1c, 0x30, 1, 2);
}

/*
 * function: func_021BECB8
 * address: 0x021BECB8
 * packet: pkt_ov210_021BECB8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021BE44C 0x021BE44C thumb ov210
 *   func_021BE49C 0x021BE49C thumb ov210
 */
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void func_021BE44C(u8 *, int, unsigned, int, int, unsigned short, unsigned);
extern void func_021BE49C(u8 *);
typedef enum { off_ECB8 = 0x1c4 } Offset;
void func_021BECB8(u8 *p, unsigned message)
{
    Offset offset = off_ECB8;
    BMP_Clear(func_02045770(*(struct Descriptor **)(p + offset)), 6);
    func_021BE44C(p, 15, message, 120, 0, 0x446, 2);
    func_021BE49C(p + offset);
}

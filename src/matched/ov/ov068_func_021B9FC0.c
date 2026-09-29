/*
 * function: func_021B9FC0
 * address:  0x021B9FC0
 * packet:   pkt_ov068_021B9FC0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B908  0x0204B908  arm
 *   func_0204A600  0x0204A600  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204B908(u32 a, u32 b);
extern void func_0204A600(void);

void func_021B9FC0(u8 *p)
{
    int i;
    u16 t;

    t = (*(u16 *)(p + 0x50))++;
    if (t > 0x60) {
        *(u16 *)(p + 0x50) = 0;
    }
    for (i = 2; i < 13; i++) {
        func_0204B908(*(u32 *)(p + i * 4 + 0x18), (u16)(*(u16 *)(p + 0x50) / 12));
    }
    func_0204A600();
}

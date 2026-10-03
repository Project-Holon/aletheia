/*
 * function: func_021D730C
 * address: 0x021D730C
 * packet: pkt_ov116_021D730C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202E54C 0x0202E54C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0202E54C(void *);
void func_021D730C(u8 *p)
{
    if (*(void **)(p + 0x1840)) {
        func_0202E54C(*(void **)(p + 0x1840));
        *(void **)(p + 0x1840) = 0;
    }
}

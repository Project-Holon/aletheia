/*
 * function: func_021C8F7C
 * address: 0x021C8F7C
 * packet: pkt_ov212_021C8F7C
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
extern void func_020307B0(void *);
void func_021C8F7C(u8 *p)
{
    if (*(void **)(p + 12) != 0) {
        func_020307B0(*(void **)(p + 12));
        *(void **)(p + 12) = 0;
    }
}

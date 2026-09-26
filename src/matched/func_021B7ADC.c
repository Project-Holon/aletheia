/*
 * function: func_021B7ADC
 * address:  0x021B7ADC
 * packet:   pkt_021B7ADC
 * region:   ov173
 * status:   EXACT
 * symbols:
 *   func_0204B404  0x0204B404  arm
 *   func_0204B8C4  0x0204B8C4  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;

void func_0204B404(u32 obj, u16 *rect, int n);
void func_0204B8C4(u32 obj, int n);

void func_021B7ADC(unsigned char *p, u32 idx)
{
    u16 local[2];

    if (idx < 4) {
        local[0] = 0x82;
        local[1] = idx * 0x18 + 0x54;
        func_0204B404(*(u32 *)(p + 0x10c), local, 1);
        func_0204B8C4(*(u32 *)(p + 0x10c), 0);
    } else if (idx < 6) {
        local[0] = (idx - 4) * 0x28;
        local[1] = 0xa8;
        func_0204B404(*(u32 *)(p + 0x10c), local, 1);
        func_0204B8C4(*(u32 *)(p + 0x10c), 1);
    } else {
        local[0] = 0xc0;
        local[1] = 0xa0;
        func_0204B404(*(u32 *)(p + 0x10c), local, 1);
        func_0204B8C4(*(u32 *)(p + 0x10c), 2);
    }
}

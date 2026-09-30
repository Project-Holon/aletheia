/*
 * function: func_021B82DC
 * address: 0x021B82DC
 * packet: pkt_ov102_021B82DC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7F18 0x021B7F18 thumb ov102
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7F18(u8 *);
void func_021B82DC(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        if (*(u32 *)(*(u8 **)(p + 0x48c) + 12) == 1) {
            if ((*(u16 *)(p + 0x486))++ > 10) {
                *(u16 *)(p + 0x486) = 0;
                *state = 1;
            }
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_021B7F18(p);
        break;
    }
}

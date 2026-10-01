/*
 * function: func_021B970C
 * address: 0x021B970C
 * packet: pkt_ov217_021B970C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: zero halfword alignment at 021B9772.
 * symbols:
 *   func_021B9AF8 0x021B9AF8 thumb ov217
 *   func_021BABB4 0x021BABB4 thumb ov217
 *   func_021BD61C 0x021BD61C thumb ov217
 */
typedef unsigned int u32;
extern u32 func_021B9AF8(u32);
extern u32 func_021BABB4(u32);
extern u32 func_021BD61C(u32);
void func_021B970C(u32 *p, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: func_021B9AF8(p[4]); break;
    case 2: func_021BABB4(p[5]); break;
    case 3: func_021BD61C(p[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: p[4] = 0; break;
    case 2: p[5] = 0; break;
    case 3: p[6] = 0; break;
    }
}

/*
 * function: func_021B8A30
 * address: 0x021B8A30
 * packet: pkt_ov133_021B8A30
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B8AC8 0x021B8AC8 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021B8AC8(u8 *);
extern void func_021B765C(u8 *, u16, s16, int, u16);
void func_021B8A30(u8 *p)
{
    u32 delta = *(u32 *)(p + 0xa0) - *(u32 *)(p + 0x9c);
    u32 step = delta / 10u;
    if (step < 256) {
        if (delta < 256) {
            step = delta;
            *(int *)(p + 0x98) = 0;
        } else step = 256;
    }
    if (delta > 4096) {
        *(s16 *)(p + 0x1838) -= 512;
        if (*(s16 *)(p + 0x1838) < -12288) *(s16 *)(p + 0x1838) = -12288;
    } else func_021B8AC8(p);
    *(u32 *)(p + 0x9c) += step;
    *(u16 *)(p + 0x182c) -= (u16)step;
    func_021B765C(p, *(u16 *)(p + 0x182c), step, 72, 48);
}

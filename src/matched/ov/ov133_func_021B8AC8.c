/*
 * function: func_021B8AC8
 * address: 0x021B8AC8
 * packet: pkt_ov133_021B8AC8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B765C 0x021B765C thumb ov133
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_021B765C(u8 *, u16, s16, int, u16);
void func_021B8AC8(u8 *p)
{
    int n = *(s16 *)(p + 0x182e);
    if (n < 0) n = -n;
    if (n < 48 && (*(s16 *)(p + 0x1838) != 0 || *(s16 *)(p + 0x183a) != 0)) {
        *(s16 *)(p + 0x1838) += *(s16 *)(p + 0x183a);
        if (*(s16 *)(p + 0x1838) > 0) {
            if (*(s16 *)(p + 0x183a) > 0) *(s16 *)(p + 0x183a) -= 128;
            else *(s16 *)(p + 0x183a) -= 42;
        } else if (*(s16 *)(p + 0x1838) < 0) {
            if (*(s16 *)(p + 0x183a) < 0) *(s16 *)(p + 0x183a) += 128;
            else *(s16 *)(p + 0x183a) += 42;
        }
        n = *(s16 *)(p + 0x1838);
        if (n < 0) n = -n;
        if (n < 512) {
            n = *(s16 *)(p + 0x183a);
            if (n < 0) n = -n;
            if (n < 512) {
                *(s16 *)(p + 0x183a) = 0;
                *(s16 *)(p + 0x1838) = 0;
            }
        }
        func_021B765C(p, *(u16 *)(p + 0x182c), 0, 72, 48);
    }
}

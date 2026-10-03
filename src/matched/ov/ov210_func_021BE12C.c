/*
 * function: func_021BE12C
 * address: 0x021BE12C
 * packet: pkt_ov210_021BE12C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 93D4's s16 parameter widened: caller passes r4 without truncation; F85C r1 is explicitly narrowed to u16.
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_021BF85C 0x021BF85C thumb ov210
 *   func_021BE978 0x021BE978 thumb ov210
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B93B8(char *p);
extern void func_021B93D4(void *, int);
extern void func_021BF85C(u8 *, u16, unsigned int);
extern void func_021BE978(u8 *);
void func_021BE12C(u8 *p, int n)
{
    int value = n + func_021B93B8(*(void **)(p + 0x1E0));
    u8 *data = *(u8 **)(*(u8 **)p + 8);
    if (data[2] == value) {
        data[2] = 255;
        func_021BF85C(p, n, 0);
    } else {
        data[2] = value;
        func_021BF85C(p, n, 1);
    }
    func_021B93D4(*(void **)(p + 0x1E0), n);
    func_021BE978(p);
}

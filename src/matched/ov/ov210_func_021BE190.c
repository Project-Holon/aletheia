/*
 * function: func_021BE190
 * address: 0x021BE190
 * packet: pkt_ov210_021BE190
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: compiled through 021BE20A; remaining 00 00 at 021BE20A is two-byte alignment padding before 021BE20C.
 * prototype: 93D4's s16 parameter widened because the original forwards full r4 without truncation.
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BCEEC 0x021BCEEC thumb ov210
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_021BEA54 0x021BEA54 thumb ov210
 *   func_021BF89C 0x021BF89C thumb ov210
 */
typedef unsigned char u8;
extern int func_021B93B8(void *);
extern int func_021BCEEC(u8 *, int);
extern void func_021B93D4(void *, int);
extern void func_021BEA54(void *);
extern void func_021BF89C(u8 *, int, int);
void func_021BE190(u8 *p, int n)
{
    int value = func_021BCEEC(p, n + func_021B93B8(*(void **)(p + 0x1E0)));
    u8 *data = *(u8 **)(*(u8 **)p + 8);
    if (data[3] == 255) {
        data[3] = value;
    } else if (data[4] == 255) {
        if (data[3] == value)
            data[3] = 255;
        else
            data[4] = value;
    } else if (data[3] == value) {
        data[3] = data[4];
        (*(u8 **)(*(u8 **)p + 8))[4] = 255;
    } else if (data[4] == value) {
        data[4] = 255;
    } else {
        data[3] = data[4];
        (*(u8 **)(*(u8 **)p + 8))[4] = value;
    }
    func_021B93D4(*(void **)(p + 0x1E0), n);
    func_021BEA54(p);
    data = *(u8 **)(*(u8 **)p + 8);
    func_021BF89C(p, data[3], data[4]);
}

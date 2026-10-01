/*
 * function: func_021BE22C
 * address: 0x021BE22C
 * packet: pkt_ov210_021BE22C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. F85C explicitly narrows r1 to u16.
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_021BF85C 0x021BF85C thumb ov210
 *   func_021BEB8C 0x021BEB8C thumb ov210
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct S;
extern int func_021B93B8(char *);
extern void func_021B93D4(struct S *, int);
extern void func_021BF85C(char *, u16, int);
extern void func_021BEB8C(u8 *);
void func_021BE22C(u8 *p, int index)
{
    int sum = index + func_021B93B8(*(char **)(p + 0x1e0));
    u8 *data = *(u8 **)(*(u8 **)p + 8);
    if (data[5] == sum) {
        data[5] = 255;
        func_021BF85C((char *)p, index, 0);
    } else {
        data[5] = sum;
        func_021BF85C((char *)p, index, 1);
    }
    func_021B93D4(*(struct S **)(p + 0x1e0), index);
    func_021BEB8C(p);
}

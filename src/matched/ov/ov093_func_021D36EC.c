/*
 * function: func_021D36EC
 * address: 0x021D36EC
 * packet: pkt_ov093_021D36EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5FA4 0x021D5FA4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
struct Unk021D5FA4; extern void func_021D5FA4(struct Unk021D5FA4 *, u16);
int func_021D36EC(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5FA4((struct Unk021D5FA4 *)m, c[1]);
    return 1;
}

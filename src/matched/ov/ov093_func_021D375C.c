/*
 * function: func_021D375C
 * address: 0x021D375C
 * packet: pkt_ov093_021D375C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D56CC 0x021D56CC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9934(char *, u8);
struct Work; extern void func_021D56CC(struct Work *, u8);
int func_021D375C(u32 *a, int b, u32 *c)
{
    int m;
    u8 k;
    k = c[1];
    m = func_021B9934((char *)a[1], c[0]);
    func_021D56CC((struct Work *)m, k);
    return 1;
}

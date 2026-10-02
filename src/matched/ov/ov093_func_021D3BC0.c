/*
 * function: func_021D3BC0
 * address: 0x021D3BC0
 * packet: pkt_ov093_021D3BC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D69A0 0x021D69A0 thumb ov093
 */
typedef unsigned char u8;
extern int func_021B9934(char *, u8);
extern void func_021D69A0(u8 *, int, u8);
int func_021D3BC0(char *p, int unused, unsigned int *a)
{
    int obj = func_021B9934(*(char **)(p + 4), a[0]);
    func_021D69A0((u8 *)obj, a[1], a[2]);
    return 1;
}

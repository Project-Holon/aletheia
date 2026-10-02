/*
 * function: func_021D3D50
 * address: 0x021D3D50
 * packet: pkt_ov093_021D3D50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B9934(char *, u8);
extern void func_021D67D8(u8 *, u16);
int func_021D3D50(char *p, int unused, unsigned int *a)
{
    int obj = func_021B9934(*(char **)(p + 4), a[0]);
    func_021D67D8((u8 *)obj, a[1]);
    return 1;
}

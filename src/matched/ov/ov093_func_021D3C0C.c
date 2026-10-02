/*
 * function: func_021D3C0C
 * address: 0x021D3C0C
 * packet: pkt_ov093_021D3C0C
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
 *   func_021D6D5C 0x021D6D5C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B9934(char *, u8);
extern void func_021D6D5C(u8 *, u16);
int func_021D3C0C(char *p, int unused, unsigned int *a)
{
    int obj = func_021B9934(*(char **)(p + 4), a[0]);
    func_021D6D5C((u8 *)obj, a[1]);
    return 1;
}

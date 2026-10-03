/*
 * function: func_021D3BE0
 * address: 0x021D3BE0
 * packet: pkt_ov093_021D3BE0
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
 *   func_021D65C8 0x021D65C8 thumb ov093
 */
typedef unsigned char u8;
struct Work;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D65C8(struct Work *, struct Work *);
int func_021D3BE0(char *p, int unused, unsigned int *a)
{
    u8 *first = func_021B9934(*(char **)(p + 4), (u8)a[0]);
    u8 *second = func_021B9934(*(char **)(p + 4), (u8)a[1]);
    func_021D65C8((struct Work *)second, (struct Work *)first);
    return 1;
}

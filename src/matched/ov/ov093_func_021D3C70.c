/*
 * function: func_021D3C70
 * address: 0x021D3C70
 * packet: pkt_ov093_021D3C70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 */
typedef unsigned char u8;
struct Arr;
extern char *func_021B9AEC(char *, int);
extern void func_021B9D10(char *, struct Arr *, int);
int func_021D3C70(char *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    struct Arr *obj = (struct Arr *)func_021B9AEC(*(char **)(p + 4), index);
    func_021B9D10(*(char **)p, obj, index);
    return 1;
}

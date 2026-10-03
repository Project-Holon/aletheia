/*
 * function: func_021BD4E4
 * address: 0x021BD4E4
 * packet: pkt_ov093_021BD4E4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021BD518 0x021BD518 thumb ov093
 */
typedef unsigned char u8;
extern char *func_021B9AEC(char *, int);
typedef unsigned int u32;
extern u8 *func_021B9C00(void *p, u32 i);
extern void func_021BD518(u8 *, u8 *);
void func_021BD4E4(u8 *p, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)func_021B9AEC(*(char **)(p + 8), i);
    first = func_021B9C00(arr, a);
    second = func_021B9C00(arr, b);
    func_021BD518(p, first);
    func_021BD518(p, second);
}

/*
 * function: func_021C6158
 * address: 0x021C6158
 * packet: pkt_ov093_021C6158
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
typedef unsigned char u8;
struct Arr;
extern char *func_021B9AEC(char *, int);
extern void func_021B9D10(char *, struct Arr *, int);
extern void func_021CD4B0(void *, unsigned int, ...);
void func_021C6158(u8 *p, u8 *a)
{
    unsigned int i;
    struct Arr *arr;
    for (i = 0; i < a[0]; i++) {
        arr = (struct Arr *)func_021B9AEC(*(char **)(p + 8), a[i + 1]);
        func_021CD4B0(*(void **)(p + 12), 0x2a, a[i + 1]);
        func_021B9D10(*(char **)(p + 4), arr, a[i + 1]);
    }
}

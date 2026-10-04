/*
 * function: func_021BCB90
 * address: 0x021BCB90
 * packet: pkt_ov209_021BCB90
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 fourth parameter pins its spill ahead of the index copy
 * symbols:
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021BD75C 0x021BD75C thumb ov209
 *   func_021BE29C 0x021BE29C thumb ov209
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B9398(char *p, int index);
extern void func_021BD75C(char *p, unsigned char *dest, unsigned text0, unsigned index);
extern void func_021BE29C(char *, u16, int, int);
void func_021BCB90(char *p, int index, int a, u16 b, int c)
{
    u32 v;
    u32 low;
    v = func_021B9398(*(void **)(p + 0xC2C), index);
    low = v & 0x0FFFFFFF;
    func_021BD75C(p, (unsigned char *)a, *(u32 *)(p + index * 4 + 0x4C), low);
    if ((v & 0xF0000000) >> 28) func_021BE29C(p, low, b, c);
}

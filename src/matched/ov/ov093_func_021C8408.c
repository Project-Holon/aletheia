/*
 * function: func_021C8408
 * address: 0x021C8408
 * packet: pkt_ov093_021C8408
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BB914 0x021BB914 thumb ov093
 */
typedef unsigned char u8;
extern void *func_021B86B8(void ***);
extern int func_021B8DDC(int);
extern u8 func_021B8FF4(u8 *);
extern void func_021BB914(int *);
void func_021C8408(u8 *p, int a)
{
    unsigned int t = (unsigned int)func_021B86B8(*(void ****)(p + 4));
    int k = func_021B8DDC(a);
    if (t <= 1 && k == func_021B8FF4(*(u8 **)(p + 4))) func_021BB914(*(int **)p);
}

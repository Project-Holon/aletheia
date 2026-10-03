/*
 * function: func_02177280
 * address:  0x02177280
 * packet:   pkt_ov014_02177280
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   d_02179780     0x02179780  data   a1
 *   func_02030734  0x02030734  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_021790E4  0x021790E4  thumb  ov014
 *   func_02178E1C  0x02178E1C  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A4;
extern char d_02179780[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0203D798(void);
extern u16 func_0208F1B4(void);
extern int func_021790E4(u32 heap, int a, int b);
extern void func_02178E1C(u32 v);

int func_02177280(int a, int b, u32 c, int d)
{
    u8 *st;
    u8 *w;

    func_0203D798();
    st = func_0203D798();
    if (g_021797A4 != 0)
        return 0;
    w = func_02030734(a, 0xCF8, 1, d_02179780, 0xed);
    g_021797A4 = w;
    w[0xCE6] = 0xff;
    if (func_021790E4(a, b, d) == 0)
        return 0;
    func_02178E1C(*(u32 *)(st + 0x50));
    *(u32 *)(w + 0xC64) = c;
    w[0xCE7] = 0;
    w[0xCE4] = 0;
    *(u16 *)(w + 0xC68) = func_0208F1B4();
    return 1;
}

/*
 * function: func_021B8A98
 * address: 0x021B8A98
 * packet: pkt_ov172_021B8A98
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BDFFC 0x021BDFFC thumb ov172
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B6E88 0x021B6E88 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char *func_021BDFFC(void *);
extern u32 func_020399A8(void);
extern u32 func_0203D1A4(u32 p);
extern void func_021B6E88(char *p, void *q);

void func_021B8A98(int a, u32 b, char *list, char *q)
{
    char *p;
    u8 n, i;
    p = func_021BDFFC(*(void **)(q + 0x3dc));
    n = (b >> 3) & 0xff;
    func_0203D1A4(func_020399A8());
    for (i = 0; i < n; i++)
        func_021B6E88(p, list + i * 8);
}

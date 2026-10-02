/*
 * function: func_021E97BC
 * address:  0x021E97BC
 * packet:   pkt_ov093_021E97BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E97F8  0x021E97F8  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E9884  0x021E9884  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern void func_021E97F8(void *a, u8 *b, int c);
extern void func_021E9728(void *p, u32 v);
extern int func_021E9884(void *p);

void func_021E97BC(char *p, u8 *a, int b)
{
    *(u8 **)(p + 0xbc) = a;
    *(u32 *)(p + 0xc0) = func_021D5440(a);
    *(int *)(p + 0xb8) = b;
    func_021E97F8(*(void **)(p + 0x180), *(u8 **)(p + 0xbc), b);
    func_021E9728(p, (u32)func_021E9884);
}

/*
 * function: func_021E98BC
 * address:  0x021E98BC
 * packet:   pkt_ov093_021E98BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E96C4  0x021E96C4  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern void func_021E9728(void *p, u32 v);
extern int func_021E96C4(char *p, int *st);

void func_021E98BC(char *p, u8 *a, int b)
{
    *(u8 **)(p + 0xbc) = a;
    *(u32 *)(p + 0xc0) = func_021D5440(a);
    *(int *)(p + 0xb8) = b;
    func_021E9728(p, (u32)func_021E96C4);
}

/*
 * function: func_021E9808
 * address:  0x021E9808
 * packet:   pkt_ov093_021E9808
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E9848  0x021E9848  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E9884  0x021E9884  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021E9848(void *a, u32 *b, int c);
extern void func_021E9728(void *p, u32 v);
extern int func_021E9884(char *p);

void func_021E9808(char *p, u32 *q, int c)
{
    u32 v = *q;

    *(u32 *)(p + 0xbc) = v;
    *(int *)(p + 0xc0) = func_021D5440((u8 *)v);
    *(u32 **)(p + 0x170) = q;
    *(int *)(p + 0xb8) = c;
    func_021E9848(*(void **)(p + 0x180), q, c);
    func_021E9728(p, (u32)func_021E9884);
}

/*
 * function: func_021C62BC
 * address:  0x021C62BC
 * packet:   pkt_ov136_021C62BC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F73C   0x0201F73C  thumb
 *   func_02041B6C    0x02041B6C  arm
 *   func_02045334            0x02045334  arm
 *   func_02045374   0x02045374  arm
 *   func_02045730   0x02045730  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0201F73C(void *, u32, u32, u32);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void *func_02045730(void *);
extern void func_02041B6C(void *);
void func_021C62BC(u8 *p)
{
    void *q;
    func_0201F73C(*(void **)(*(u8 **)(p + 8) + 0xA8), 2, 0x3E2, 0xD);
    q = *(void **)(*(u8 **)(p + 8) + 0xA8);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
}

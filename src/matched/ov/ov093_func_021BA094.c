/*
 * function: func_021BA094
 * address: 0x021BA094
 * packet: pkt_ov093_021BA094
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201A920 0x0201A920 thumb
 */
typedef unsigned int u32;
struct Party;
extern struct Party *func_0201A920(u32);
struct S { char pad[0x298]; void *a[4]; void *b[4]; void *c; };
void func_021BA094(struct S *p)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        p->a[i] = func_0201A920(0x12);
        p->b[i] = func_0201A920(0x12);
    }
    p->c = func_0201A920(0x12);
}

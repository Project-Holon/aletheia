/*
 * unit: yes
 * function: func_021B65A8, func_021B65B4
 * address: 0x021B65A8
 * packet: pkt_ov067_021B65A8
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extent includes the unlabelled tail-call follower at 0x021B65B4.
 * symbols:
 *   func_021B6600 0x021B6600 thumb ov067
 *   func_021B69F8 0x021B69F8 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 */
extern void *func_021B6600(unsigned char *p, unsigned int id);
extern unsigned int func_021B69F8(void *p);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);

unsigned int func_021B65A8(unsigned char *p, unsigned int id)
{
    return func_021B69F8(func_021B6600(p, id));
}

int func_021B65B4(unsigned char *p, unsigned int id)
{
    *(int *)(p + 8) = 0;
    *(int *)p = -1;
    return func_021B6548(p, id, 1);
}

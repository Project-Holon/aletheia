/*
 * function: func_021BA594
 * address: 0x021BA594
 * packet: pkt_ov181_021BA594
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_021BA4AC 0x021BA4AC thumb ov181
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_021BA4AC(char *, unsigned char *, void *, int);
void func_021BA594(char *p, unsigned char *q)
{
    void *s;
    int y;
    if (*(unsigned short *)(q + 4) < 0x100) {
        s = func_02045770(*(void **)(p + 0x2bc));
        y = *(unsigned short *)(q + 4);
        *(unsigned char *)(p + 0x2cf) |= 1;
    } else {
        s = func_02045770(*(void **)(p + 0x2c4));
        y = *(unsigned short *)(q + 4) - 0x100;
        *(unsigned char *)(p + 0x2cf) |= 2;
    }
    func_021BA4AC(p, q, s, y);
}

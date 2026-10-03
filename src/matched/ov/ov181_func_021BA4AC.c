/*
 * function: func_021BA4AC
 * address: 0x021BA4AC
 * packet: pkt_ov181_021BA4AC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021BAB40 0x021BAB40 data a2
 */
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern unsigned func_0201D304(void *, void *, int);
extern void func_0201C7D0(void *, short, short, void *, void *, unsigned short);
extern const unsigned short d_021BAB40[];
void func_021BA4AC(char *p, unsigned char *q, void *s, int y)
{
    int x;
    unsigned w;
    func_02045CAC(*(void **)(p + 0xb0), *(unsigned *)q, *(void **)(p + 0xb4));
    if (*(unsigned short *)(q + 0xa) == 0) {
        x = *(short *)(q + 0xc) + *(short *)(q + 0xe);
    } else if (*(unsigned short *)(q + 0xa) == 1) {
        w = func_0201D304(*(void **)(p + 0xb4), *(void **)(p + q[9] * 4 + 0xa8), 0);
        x = *(short *)(q + 0xc) + *(short *)(q + 0xe) - w;
    } else if (*(unsigned short *)(q + 0xa) == 2) {
        w = func_0201D304(*(void **)(p + 0xb4), *(void **)(p + q[9] * 4 + 0xa8), 0);
        x = *(short *)(q + 0xc) + *(short *)(q + 0xe) - w / 2;
    }
    func_0201C7D0(s, x, y, *(void **)(p + 0xb4), *(void **)(p + q[9] * 4 + 0xa8), d_021BAB40[q[8]]);
}

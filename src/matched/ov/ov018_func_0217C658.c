/*
 * function: func_0217C658
 * address: 0x0217C658
 * packet: pkt_ov018_0217C658
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0x0217C686.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {
    void *f0;
    int f4;
    s16 f8, fA;
    u16 fC;
    u8 fE, fF, f10, f11, f12, f13;
    int f14;
} Rec;
extern void func_02082BCC(void *, int, int);
void func_0217C658(Rec *p, void *a, int b, u16 c, u8 d, u8 e)
{
    func_02082BCC(p, 0, sizeof(Rec));
    p->f0 = a;
    p->f4 = b;
    p->fC = c;
    p->fE = d;
    p->fF = e;
    p->fA = 15;
    p->f8 = p->fA;
}

/*
 * function: func_021BDD0C
 * address:  0x021BDD0C
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203D844  0x0203D844  arm
 *   func_02085D3C  0x02085D3C  arm
 *   d_021C3B9C     0x021C3B9C  data
 */
typedef struct {
    char pad[0x48];
    int f48;                /* 0x48 */
} Snd;

extern Snd d_021C3B9C;
extern int func_02085D3C(void);
extern void func_0203CBAC(Snd *s, int a, void *b);
extern void func_0203D844(Snd *s);

void func_021BDD0C(void *p, int on)
{
    if (func_02085D3C())
        d_021C3B9C.f48 = 0x79000;
    else
        d_021C3B9C.f48 = 0x5e400;
    if (on)
        func_0203CBAC(&d_021C3B9C, 0, p);
    else
        func_0203D844(&d_021C3B9C);
}

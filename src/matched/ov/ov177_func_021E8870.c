/*
 * function: func_021E8870
 * address:  0x021E8870
 * packet:   pkt_021E8870
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 */

typedef struct {
    char           pad0[0x14];
    int            f14;
    char           pad1[4];
    unsigned short f1c;
} S;

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int, int);
extern void func_02045334(int);

void func_021E8870(S *p)
{
    int r = (int)func_02045770((struct Descriptor *)p->f14);

    func_02043B5C(r, (unsigned char)p->f1c);
    func_02045334(p->f14);
}

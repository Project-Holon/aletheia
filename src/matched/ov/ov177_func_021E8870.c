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
typedef unsigned char  u8;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);

void func_021E8870(S *p)
{
    int r = (int)func_02045770((struct Descriptor *)p->f14);

    func_02043B5C((struct CharBuf *)r, (unsigned char)p->f1c);
    func_02045334((struct Descriptor *)p->f14);
}

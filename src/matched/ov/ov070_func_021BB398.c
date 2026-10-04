/*
 * function: func_021BB398
 * address:  0x021BB398
 * packet:   pkt_ov070_021BB398
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
extern void func_0204B6F4(int, u32, int);

void func_021BB398(int p, u32 val)
{
    short b[2];
    short a[2];
    unsigned i;

    func_0204B454((struct Actor *)*(int *)(p + 0x6A4), (struct PtS *)b, 0);
    for (i = 0; i < 8; i++) {
        func_0204B454((struct Actor *)*(int *)(p + i * 4 + 0x634), (struct PtS *)a, 0);
        if (a[1] == b[1]) {
            break;
        }
    }
    func_0204B6F4(*(int *)(p + i * 4 + 0x634), (u8)val, 0);
}

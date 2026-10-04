/*
 * function: func_021BAFC4
 * address:  0x021BAFC4
 * packet:   pkt_ov206_021BAFC4
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The shared zero is an enum-typed local initialised at declaration (not folded to
 * a literal), which yields the `adds r3, r4, #0` copy for the fourth argument of
 * the fifth func_020439A0 call.
 *
 * symbols:
 *   func_020437AC  0x020437AC  arm
 *   func_0204384C  0x0204384C  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *
 * Addresses are Black-image addresses.
 */

typedef enum { ZERO } Zero;

typedef struct {
    unsigned short f0;
    char pad2[0x4d - 2];
    unsigned char f4d;
    char pad4e[0x8c - 0x4e];
    int f8c;
    int f90;
} Ent;

extern int func_0204384C(int, int, int, int);
extern int func_020450F0(int, int, int, int, int, int, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_020439A0(int, int, int, int, int, int, int, int, int);
extern void func_020437AC(int);

void func_021BAFC4(Ent *e)
{
    Zero z = ZERO;
    int s = func_0204384C(0x9f, 0x19, z, e->f0);
    int q;

    e->f8c = func_020450F0(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f8c);
    func_020439A0(s, q, 8, 0, z, z, 0x20, 0x18, z);

    e->f90 = func_020450F0(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0(s, q, 0xa8, 8, z, z, 0x20, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0(s, q, 0xf8, 8, z, 8, 8, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0(s, q, 0x28, 0x10, 8, 8, 0x18, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0(s, q, 0x80, z, 0, 0x10, 8, 8, 0);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0(s, q, 0x58, 0x10, 8, 0x10, 0x18, 8, z);

    func_020437AC(s);
}

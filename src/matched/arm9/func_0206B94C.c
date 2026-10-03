/*
 * function: func_0206B94C
 * address:  0x0206B94C
 * packet:   pkt_0206B7D0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The two-byte opcode of the same script object func_0206B7D0 steps: bit 9
 * of the status word at +0x08 aborts, bit 0 gates the body, the state byte
 * at +0x8f (read through the +0x18 hook, zero when the hook is null) picks
 * the stop, and the tail advances the program counter at +0x00 by two.
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Obj0206B94C Obj0206B94C;
struct Obj0206B94C {
    u8   *f00;
    u32   f04;
    u32   f08;
    u32   f0c;
    u32   f10;
    u32   f14;
    void (*f18)(Obj0206B94C *);
    u8    pad1c[0x8f - 0x1c];
    u8    f8f;
};

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);

void func_0206B94C(Obj0206B94C *p)
{
    u32 v = p->f08;
    u32 st;
    u32 flag;

    if (!(v & 0x200) && (v & 1)) {
        st = p->f18 ? p->f8f : 0;
        if (st == 1) {
            p->f08 &= ~0x40;
            p->f18(p);
            st = p->f18 ? p->f8f : 0;
            flag = p->f08 & 0x40;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            u32 a = p->f00[1];
            if (!(p->f08 & 0x100)) {
                func_0206DDA4(0x14, &a, 1);
            }
        }
        if (st == 3) {
            p->f08 &= ~0x40;
            p->f18(p);
        }
    }
    p->f00 += 2;
}

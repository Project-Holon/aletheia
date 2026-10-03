/*
 * function: func_021B6A98
 * address:  0x021B6A98
 * packet:   pkt_ov067_021B6A98
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S {
    void *f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x26 - 0x0c];
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
} S;

struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021B6A98(S *p, u32 flag)
{
    p->f04 = flag;
    if (flag) {
        if (p->f08 == p->f2a) {
            p->f08 = p->f2c;
        } else if (p->f08 == p->f28) {
            p->f08 = p->f26;
        }
        func_0204B878(p->f00, p->f08);
    } else {
        if (p->f08 == p->f2c) {
            p->f08 = p->f2a;
        } else if (p->f08 == p->f26) {
            p->f08 = p->f28;
        }
        func_0204B878(p->f00, p->f28);
    }
}

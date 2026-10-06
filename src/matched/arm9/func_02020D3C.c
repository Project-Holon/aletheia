/*
 * unit:     no
 * address:  0x02020D3C
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02020D3C
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *
 * A destructor: frees two owned sub-objects at +4 and +8 if present, then
 * hands the object itself to a common finalizer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020D3C.c \
 *       --func func_02020D3C --addr 0x02020D3C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct D {
    u8    pad[4];
    void *f4;
    void *f8;
};

struct Obj020437AC;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_02020D3C(struct D *p)
{
    if (p->f4 != 0) {
        func_02045808(p->f4);
    }
    if (p->f8 != 0) {
        func_020437AC(p->f8);
    }
    func_020307B0(p);
}

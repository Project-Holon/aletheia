/*
 * unit:     yes
 * function: func_02013930
 * address:  0x02013930
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0     0x020307B0  arm
 *   func_020130DC     0x020130DC  thumb
 *
 * The subsystem destructor: the +0x5C buffer is released and its pointer
 * cleared (the store inside the guard, not after it), then the teardown is
 * handed to func_020130DC with the object left in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013930.c  *       --func func_02013930 --addr 0x02013930 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj {
    u8  pad00[0x5C];
    u32 f5c;        /* +0x5C */
};

extern void func_020307B0(void *p);
extern void func_020130DC(struct Obj *p);

void func_02013930(struct Obj *p)
{
    if (p->f5c != 0) {
        func_020307B0((void *)p->f5c);
        p->f5c = 0;
    }
    func_020130DC(p);
}

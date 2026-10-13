/*
 * unit:     yes
 * function: BTL_SETUP_ClearWithSlots
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
 *   BTL_SETUP_FreeSlots     0x020130DC  thumb
 *
 * The subsystem destructor: the +0x5C buffer is released and its pointer
 * cleared (the store inside the guard, not after it), then the teardown is
 * handed to BTL_SETUP_FreeSlots with the object left in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ClearWithSlots.c  *       --func BTL_SETUP_ClearWithSlots --addr 0x02013930 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj {
    u8  pad00[0x5C];
    u32 f5c;        /* +0x5C */
};

extern u32 func_020307B0(void *p);
extern void BTL_SETUP_FreeSlots(struct Obj *p);

void BTL_SETUP_ClearWithSlots(struct Obj *p)
{
    if (p->f5c != 0) {
        func_020307B0((void *)p->f5c);
        p->f5c = 0;
    }
    BTL_SETUP_FreeSlots(p);
}

/*
 * function: FLD_TRADE_Delete
 * address:  0x021CC040
 * packet:   pkt_ov021_021CC040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Frees the three buffers held by a battle-subway mon object and then the object itself.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef struct Obj {
    unsigned char pad0[8];
    void *f8;
    void *fC;
    void *f10;
} Obj;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void FLD_TRADE_Delete(Obj *o)
{
    func_020307B0(o->f8);
    func_020307B0(o->fC);
    func_020307B0(o->f10);
    func_020307B0(o);
}

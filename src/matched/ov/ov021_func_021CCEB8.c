/*
 * function: func_021CCEB8
 * address:  0x021CCEB8
 * packet:   pkt_ov021_021CCEB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fetches three handles for the work block: an ov021 object, a 0x54 sub-entry of it, and the record for the work's id.
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *f0;
    u8 pad4[8];
    u16 hC;
    u8 padE[0xa0 - 0xe];
    void *fA0;
    void *fA4;
    void *fA8;
} Work;

extern void *func_02188C54(void *p);
extern void *func_021904B0(void *p, u32 id);
extern void *func_0201EC64(u16 id);

void func_021CCEB8(Work *w)
{
    void *o = func_02188C54(w->f0);
    w->fA8 = func_021904B0(o, 0x54);
    w->fA4 = o;
    w->fA0 = func_0201EC64(w->hC);
}

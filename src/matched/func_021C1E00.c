/*
 * function: func_021C1E00
 * address:  0x021C1E00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer with one argument load: passes the word at offset 0xc on
 * to func_021C0E3C.  Reached from func_021C1D74's veneer.
 *
 * symbols:
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[3];
    u32 a;
} Rec;

extern void func_021C0E3C(u32);

void func_021C1E00(Rec *p)
{
    func_021C0E3C(p->a);
}

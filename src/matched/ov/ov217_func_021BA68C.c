/*
 * function: func_021BA68C
 * address:  0x021BA68C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: passes the word at offset 0x14 on to func_021C0E3C.
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
    u32 w[5];
    u32 a;
} Rec;

extern void func_021C0E3C(void *p);

void func_021BA68C(Rec *p)
{
    func_021C0E3C((void *)p->a);
}

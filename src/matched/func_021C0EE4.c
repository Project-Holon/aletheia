/*
 * function: func_021C0EE4
 * address:  0x021C0EE4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Whether two words of a record are equal.  Reached only from the tail-call
 * veneer func_021C0E64.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[2];
    u32 a;
    u32 b;
} Rec;

int func_021C0EE4(Rec *p)
{
    return p->a == p->b;
}

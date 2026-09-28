/*
 * function: func_021C0EDC
 * address:  0x021C0EDC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears two words of a record.  Reached only from the tail-call veneer
 * func_021C0E5C.
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

void func_021C0EDC(Rec *p)
{
    p->a = 0;
    p->b = 0;
}

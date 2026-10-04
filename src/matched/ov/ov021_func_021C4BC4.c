/*
 * function: func_021C4BC4
 * address:  0x021C4BC4
 * packet:   pkt_ov021_021C4BC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Applies the record's two parameters to the owner's map object.
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 owner;
    u16 h4;
    u16 h6;
} S;

extern u32 func_021ABE18(u32 a);
extern void func_021C6628(u32 o, u16 v);
typedef unsigned char  u8;
extern void func_021C6580(u8 *p, int i);

void func_021C4BC4(S *s)
{
    u32 o = func_021ABE18(s->owner);

    func_021C6628(o, s->h6);
    func_021C6580((u8 *)o, s->h4);
}

/*
 * function: func_02164708
 * address:  0x02164708
 * packet:   pkt_ov010_02164708
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag id of an entry: the first halfword of its 10-byte record in
 * d_02171534, offset by 900.
 *
 * symbols:
 *   func_021646E8  0x021646E8  thumb  ov010
 *   d_02171534     0x02171534  data
 */

typedef unsigned short u16;

typedef struct Rec10 {
    u16 flag;
    u16 rest[4];
} Rec10;

extern int func_021646E8(u16 id);
extern const Rec10 d_02171534[];

u16 func_02164708(u16 id)
{
    return d_02171534[func_021646E8(id)].flag + 900;
}

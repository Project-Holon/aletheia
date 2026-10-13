/*
 * function: BSUBWAY_COMM_SetSendRetireSelect
 * address:  0x02167BB4
 * packet:   pkt_ov010_02167BB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 BSUBWAY_COMM_SetSendData.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x0C];
    u16 h0c_b0 : 3;
    u16 b3 : 1;
    u16 h0c_rest : 12;
    u8 pad0e[0x668 - 0x0E];
    u16 h668;
} Obj;

void BSUBWAY_COMM_SetSendRetireSelect(Obj *o, u16 v)
{
    o->b3 = v;
    o->h668 = v;
}

/*
 * function: GAME_BEACON_ACCESSOR_GetDetailsPms
 * packet: pkt_ov010_02165C90
 * address: 0x02165C90
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165CB2.
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Packed {u16 low:8,a:3,b:5;};
struct R {u8 pad[0x48];struct Packed fields;u16 c,d;};
struct Quad {u16 a,b,c,d;};
void GAME_BEACON_ACCESSOR_GetDetailsPms(const struct R *p,struct Quad *q)
{
    q->a=p->fields.a;
    q->b=p->fields.b;
    q->c=p->c;
    q->d=p->d;
}

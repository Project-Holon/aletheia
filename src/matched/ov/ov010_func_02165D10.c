/*
 * function: func_02165D10
 * packet: pkt_ov010_02165D10
 * address: 0x02165D10
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165D1E.
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct S {u32 a,b,c;u32 low:16;u32 first:10;u32 second:6;};
void func_02165D10(const struct S *p,u16 *a,u16 *b)
{
    *a=p->first;
    *b=p->second;
}

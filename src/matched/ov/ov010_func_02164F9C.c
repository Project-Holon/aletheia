/*
 * function: GAME_BEACON_SEARCH_SelectBetterEntry
 * address: 0x02164F9C
 * packet: pkt_ov010_02164F9C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Hdr { u8 x; u8 lo:4; u8 hi:4; u8 flag:1; u8 rest:7; } Hdr;
Hdr *GAME_BEACON_SEARCH_SelectBetterEntry(Hdr *p,Hdr *q) { if(p->flag) return q; if(p->lo>=p->hi || p->lo<q->lo) return q; return p; }

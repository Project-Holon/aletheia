/*
 * function: IRC_RANKING_SeqRun
 * address: 0x021B78B8
 * packet: pkt_ov106_021B78B8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct C C;
struct C { void (*callback)(C *, int *, int); int flag, value, arg; };
void IRC_RANKING_SeqRun(C *p) { if (p->flag == 0) p->callback(p, &p->value, p->arg); }

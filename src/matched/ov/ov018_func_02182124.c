/*
 * function: EVENT_COMM_COMMON_CreateOfferEvent
 * address: 0x02182124
 * packet: pkt_ov018_02182124
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   EVENT_COMM_COMMON_OfferEventMain 0x02182150 thumb ov018
 */

typedef unsigned int u32;
typedef struct { u32 words[13]; } Rec;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern Rec *func_020124E8(void *);
extern int EVENT_COMM_COMMON_OfferEventMain(void *a, int *state, int c);
void *EVENT_COMM_COMMON_CreateOfferEvent(void *a, void *unused, Rec *b) { void *r; r = func_020122C0(a,0,(void *)EVENT_COMM_COMMON_OfferEventMain,0x34); *func_020124E8(r) = *b; return r; }

/*
 * function: BTL_EVENT_FreeFactor
 * address: 0x021D7494
 * packet: pkt_ov093_021D7494
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   data_021F3CB0 0x021F3CB0 data a4
 *   BTL_EVENT_ClearFactor 0x021D74BC thumb ov093
 */
typedef struct { unsigned int serial; void *head; unsigned int used; void *pool[0x84]; } List;
extern List data_021F3CB0;
extern void BTL_EVENT_ClearFactor(int);
void BTL_EVENT_FreeFactor(void *p) { if (data_021F3CB0.used) { BTL_EVENT_ClearFactor((int)p); data_021F3CB0.pool[--data_021F3CB0.used] = p; } }

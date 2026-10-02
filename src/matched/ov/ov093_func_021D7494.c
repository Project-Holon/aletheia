/*
 * function: func_021D7494
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
 *   func_021D74BC 0x021D74BC thumb ov093
 */
typedef struct { unsigned int serial; void *head; unsigned int used; void *pool[0x84]; } List;
extern List data_021F3CB0;
extern void func_021D74BC(int);
void func_021D7494(void *p) { if (data_021F3CB0.used) { func_021D74BC((int)p); data_021F3CB0.pool[--data_021F3CB0.used] = p; } }

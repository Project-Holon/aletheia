/*
 * function: func_021D74C8
 * address: 0x021D74C8
 * packet: pkt_ov093_021D74C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021F3ECC 0x021F3ECC data a4
 */
typedef struct { unsigned int count; unsigned short keys[0x60]; } Tbl;
extern Tbl g_021F3ECC;
void func_021D74C8(void) { Tbl *p = &g_021F3ECC; unsigned int i; p->count = 0; for (i = 0; i < 0x60; i++) p->keys[i] = 0; }

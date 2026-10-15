/*
 * unit: yes
 * function: EVENT_POKE_STATUS_AddMs5000, EVENT_POKE_STATUS_IsMs5000
 * address: 0x0215A490
 * packet: pkt_ov010_0215A490
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes unlabelled range-test EVENT_POKE_STATUS_IsMs5000; function-start seed.
 */
typedef unsigned short u16;
u16 EVENT_POKE_STATUS_AddMs5000(unsigned a) { return a + 5000; }
int EVENT_POKE_STATUS_IsMs5000(unsigned a) { if (a >= 5000) return 1; return 0; }

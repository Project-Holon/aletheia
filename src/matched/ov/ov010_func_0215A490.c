/*
 * unit: yes
 * function: EVENT_TRAINER_GetSecondaryScriptId, EVENT_TRAINER_IsSecondaryScriptId
 * address: 0x0215A490
 * packet: pkt_ov010_0215A490
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes unlabelled range-test EVENT_TRAINER_IsSecondaryScriptId; function-start seed.
 */
typedef unsigned short u16;
u16 EVENT_TRAINER_GetSecondaryScriptId(unsigned a) { return a + 5000; }
int EVENT_TRAINER_IsSecondaryScriptId(unsigned a) { if (a >= 5000) return 1; return 0; }

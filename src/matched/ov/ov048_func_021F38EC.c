/*
 * function: FIELD_GIMMICK_GATE_DeleteWork
 * address: 0x021F38EC
 * packet: pkt_ov048_021F38EC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELD_GIMMICK_GATE_FreeBoardRecord 0x021F39A8 thumb ov048
 *   FIELD_GIMMICK_GATE_FreeNewsList 0x021F3C14 thumb ov048
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 */
extern void FIELD_GIMMICK_GATE_FreeBoardRecord(void **p);
extern void FIELD_GIMMICK_GATE_FreeNewsList(char *p);
extern void FIELDMAP_FreeCommonWork(unsigned char *p, int id);
void FIELD_GIMMICK_GATE_DeleteWork(int *p) { if(p) {FIELD_GIMMICK_GATE_FreeBoardRecord((void **)p);FIELD_GIMMICK_GATE_FreeNewsList((char *)p);FIELDMAP_FreeCommonWork((unsigned char *)p[1],0);} }

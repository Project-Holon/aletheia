/*
 * function: FIELD_GIMMICK_GATE_GetBoardFacing
 * address: 0x021F3790
 * packet: pkt_ov048_021F3790
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int *FIELDMAP_GetCommonWork(char *,int);
u8 FIELD_GIMMICK_GATE_GetBoardFacing(char *p) { return (u8)(*(int **)((char *)FIELDMAP_GetCommonWork(p,0)+0x1c))[5]; }

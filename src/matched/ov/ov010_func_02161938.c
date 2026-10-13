/*
 * function: EVENT_FIELD_PROCLINK_InitAnimNode
 * address: 0x02161938
 * packet: pkt_ov010_02161938
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_SysSearchMoveCode 0x0216DE54 thumb ov010
 *   FLDMMDL_SysSearchObjId 0x0216DE94 thumb ov010
 */

extern void *FLDMMDL_SysSearchMoveCode(void *, unsigned int);
extern void *FLDMMDL_SysSearchObjId(void *, unsigned int);
void EVENT_FIELD_PROCLINK_InitAnimNode(void *p, unsigned int id) { if (id == 0xf2) FLDMMDL_SysSearchMoveCode(p, 0x30); else if (id != 0xf1) FLDMMDL_SysSearchObjId(p, id); }

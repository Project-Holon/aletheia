/*
 * function: FLD_VREQ_SetSubMasterBrightness
 * address: 0x021D324C
 * packet: pkt_ov021_021D324C
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov021/field_palace_sys.c and filed here.
 */

typedef unsigned char u8;
typedef struct { u8 pad[0x35]; u8 f35; u8 pad36; u8 f37; } Obj_021D324C;
void FLD_VREQ_SetSubMasterBrightness(Obj_021D324C *p, u8 v);

void FLD_VREQ_SetSubMasterBrightness(Obj_021D324C *p, u8 v) { p->f35 = 1; p->f37 = v; }

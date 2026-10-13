/*
 * function: GIMMICK46_SetMmdlVanish
 * address: 0x021F4064
 * packet: pkt_ov046_021F4064
 * region: ov046
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK46_FindMmdlByObjId 0x021F4020 thumb ov046
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GIMMICK46_FindMmdlByObjId(u32,int);
extern void FLDMMDL_SetStatusBitVanish(u32 *,u32);
void GIMMICK46_SetMmdlVanish(u32 a,int b,u32 c) { u32 *p; p=(u32 *)GIMMICK46_FindMmdlByObjId(a,b); if(p) FLDMMDL_SetStatusBitVanish(p,c); }

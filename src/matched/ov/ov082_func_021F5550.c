/*
 * function: FLD_FACEUP_StartClose
 * address: 0x021F5550
 * packet: pkt_ov082_021F5550
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetFaceUpWorkPtr 0x02189A60 thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   FLD_FACEUP_CloseEventMain 0x021F55A0 thumb ov082
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u8 *FIELDMAP_GetFaceUpWorkPtr(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FLD_FACEUP_CloseEventMain(void *a0, int *st);
void *FLD_FACEUP_StartClose(void *p) { u8 *obj = GAMESYSTEM_GetFieldMap(p); switch ((unsigned int)*(void **)FIELDMAP_GetFaceUpWorkPtr(obj)) { case 0: return 0; default: return func_020122C0(p,0,(void *)FLD_FACEUP_CloseEventMain,0); } }

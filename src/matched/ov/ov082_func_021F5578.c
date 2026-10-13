/*
 * function: FLD_FACEUP_Delete
 * address: 0x021F5578
 * packet: pkt_ov082_021F5578
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetFaceUpWorkPtr 0x02189A60 thumb ov021
 *   FLD_FACEUP_Release 0x021F5648 thumb ov082
 */
typedef unsigned char u8;
extern void **FIELDMAP_GetFaceUpWorkPtr(u8 *p);
extern void FLD_FACEUP_Release(int p, void *w);
void FLD_FACEUP_Delete(u8 *p) { void *w = *FIELDMAP_GetFaceUpWorkPtr(p); FLD_FACEUP_Release((int)p, w); }

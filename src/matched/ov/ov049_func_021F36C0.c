/*
 * function: FIELD_GIMMICK_MODELS_A_Init
 * address: 0x021F36C0
 * packet: pkt_ov049_021F36C0
 * region: ov049
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_AllocCommonWork 0x02189764 thumb ov021
 *   FIELD_GIMMICK_MODELS_A_PlaceModels 0x021F3714 thumb ov049
 *   FIELD_GIMMICK_MODELS_A_InitExtra 0x021F3864 thumb ov049
 */
#include "../include/Obj20549.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p,int id,int a,int b);
extern void FIELD_GIMMICK_MODELS_A_PlaceModels(unsigned int a0,unsigned int a);
extern void FIELD_GIMMICK_MODELS_A_InitExtra(void *q,unsigned char *p);
void FIELD_GIMMICK_MODELS_A_Init(unsigned char *p) { unsigned short h; void *q; h=FIELDMAP_GetHeapId((u8 *)((int)p)); q=FIELDMAP_AllocCommonWork(p,0,h,2); ((struct Obj20549 *)q)->f0=h; FIELD_GIMMICK_MODELS_A_PlaceModels((unsigned int)q,(unsigned int)p); FIELD_GIMMICK_MODELS_A_InitExtra(q,p); }

/*
 * function: FIELD_FK_DEMO_DeleteBuildAnime
 * address: 0x021F38D4
 * packet: pkt_ov056_021F38D4
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_BUILDMODEL_DeleteNode 0x0218C860 thumb ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim 0x0218C69C thumb ov021
 */
#include "../include/Obj03166.h"
extern void FIELD_BUILDMODEL_DeleteNode(void *);
extern void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *,int,int,int);
void FIELD_FK_DEMO_DeleteBuildAnime(unsigned char *p) { if (((struct Obj03166 *)p)->f0) { FIELD_BUILDMODEL_DeleteNode(((struct Obj03166 *)p)->f0); FIELD_BUILDMODEL_PlayEntryAnim(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,1); FIELD_BUILDMODEL_PlayEntryAnim(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,3); *(int *)&((struct Obj03166 *)p)->f0=0; ((struct Obj03166 *)p)->f4=0; *(int *)&((struct Obj03166 *)p)->f8=0; } }

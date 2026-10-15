/*
 * function: RESEARCH_TOP_InitFields
 * address: 0x021BA504
 * packet: pkt_ov217_021BA504
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 * symbols:
 *   RESEARCH_TOP_ClearResources 0x021BA8FC thumb ov217
 *   RESEARCH_TOP_ClearCommandQueue 0x021BA674 thumb ov217
 *   RESEARCH_TOP_ClearMessages 0x021BA5E4 thumb ov217
 *   RESEARCH_TOP_ClearFont 0x021BA5B4 thumb ov217
 *   RESEARCH_TOP_ClearLabels 0x021BA858 thumb ov217
 *   RESEARCH_TOP_ClearUnits 0x021BA9E8 thumb ov217
 *   RESEARCH_TOP_ClearActor 0x021BAA40 thumb ov217
 *   RESEARCH_TOP_ClearPaletteAnime 0x021BAAC4 thumb ov217
 */
#include "../include/Obj03376.h"
extern void RESEARCH_TOP_ClearResources(void *);
extern void RESEARCH_TOP_ClearCommandQueue(void *);
extern void RESEARCH_TOP_ClearMessages(void *);
extern void RESEARCH_TOP_ClearFont(void *);
extern void RESEARCH_TOP_ClearLabels(void *);
extern void RESEARCH_TOP_ClearUnits(void *);
extern void RESEARCH_TOP_ClearActor(void *);
extern void RESEARCH_TOP_ClearPaletteAnime(void *);
void RESEARCH_TOP_InitFields(char *p)
{
    ((struct Obj03376 *)p)->f80=0;((struct Obj03376 *)p)->f84=0;((struct Obj03376 *)p)->f88=0;
    ((struct Obj03376 *)p)->f18=0;((struct Obj03376 *)p)->f20=0;((struct Obj03376 *)p)->f24=0;
    ((struct Obj03376 *)p)->f28=0;((struct Obj03376 *)p)->f8C=2;((struct Obj03376 *)p)->f1C=0;
    RESEARCH_TOP_ClearResources(p);RESEARCH_TOP_ClearCommandQueue(p);RESEARCH_TOP_ClearMessages(p);RESEARCH_TOP_ClearFont(p);
    RESEARCH_TOP_ClearLabels(p);RESEARCH_TOP_ClearUnits(p);RESEARCH_TOP_ClearActor(p);RESEARCH_TOP_ClearPaletteAnime(p);
}

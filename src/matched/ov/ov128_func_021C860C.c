/*
 * unit: yes
 * function: Wf2dmapFriend_DrawEntryOpen, Wf2dmapFriend_NoopA, Wf2dmapFriend_NoopB, Wf2dmapFriend_SetEntryAnim
 * address: 0x021C860C
 * packet: pkt_ov128_021C860C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_SetActorAnimSeq 0x021CA40C thumb ov128
 *   Wf2dmapFriend_DrawEntryBg 0x021C88C0 thumb ov128
 *   Wf2dmapFriend_DrawEntryPage 0x021C8904 thumb ov128
 *   WF2DMAP_TOUCH_UpdateItemBar 0x021CA2DC thumb ov128
 */
#include "../include/Obj00179.h"
#include "../include/Obj14039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void WF2DMAP_TOUCH_SetActorAnimSeq(char *p, int n);
extern void Wf2dmapFriend_DrawEntryBg(s16 *, void *, u8 *);
extern void Wf2dmapFriend_DrawEntryPage(char *p, char *q, void *r, void *s, int t, char *table, int page, u16 heap);
extern void WF2DMAP_TOUCH_UpdateItemBar(char *p);
void Wf2dmapFriend_DrawEntryOpen(u8 *p, u8 *a, u8 *b, int x, int y, u16 c)
{
    ((struct Obj00179 *)p)->f4 = y;
    ((struct Obj00179 *)p)->f0 = x;
    WF2DMAP_TOUCH_SetActorAnimSeq((char *)p, x);
    Wf2dmapFriend_DrawEntryBg((s16 *)(p + 12), b, b + 0x16c);
    Wf2dmapFriend_DrawEntryPage((char *)(p + 12), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    WF2DMAP_TOUCH_UpdateItemBar((char *)p);
}
void Wf2dmapFriend_NoopA(void) {}
void Wf2dmapFriend_NoopB(void) {}
void Wf2dmapFriend_SetEntryAnim(u8 *p, u8 *a, int n)
{
    a[8] = 3;
    ((struct Obj14039 *)p)->f102 = n;
    ((struct Obj14039 *)p)->f100 = 0;
}

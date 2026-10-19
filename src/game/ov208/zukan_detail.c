/*
 * file:     zukan_detail.c
 * unit:     yes
 * function: ZUKAN_DETAIL_MAIN_SwitchScreen
 * address:  0x021BCC84
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wave 13: cut from zukan_detail_main.c by tools/splitfile.py. ZUKAN_DETAIL_MAIN_SwitchScreen
 * is the function whose own __FILE__ pool anchor names this file (string 0x021C8DB0).
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ZUKAN_DETAIL_INFO_SetHeapId 0x021BEA00 thumb
 *   ZUKAN_DETAIL_AREA_SetHeapId 0x021BF784 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetHeapId 0x021C255C thumb
 *   ZUKAN_DETAIL_FORM_SetHeapId 0x021C3B68 thumb
 *   d_021C8DB0 0x021C8DB0 data a1
 *   d_021C8508 0x021C8508 data a4
 *   d_021C8590 0x021C8590 data a4
 *   d_021C86F0 0x021C86F0 data a4
 *   d_021C881C 0x021C881C data a4
 *   ZUKAN_DETAIL_PROCSYS_AllocNode 0x021BC240 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeNode 0x021BC26C thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreateContext 0x021BC35C thumb ov208
 */
#include "zukan_detail_shared_types.h"
#include "zukan_detail_main_shared_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void ZUKAN_DETAIL_INFO_SetHeapId(unsigned short *p, unsigned short v);

extern void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v);

extern void ZUKAN_DETAIL_VOICE_SetHeapId(u16 *dst, u16 value);

extern void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value);

struct Ov208Fsm *ZUKAN_DETAIL_PROCSYS_AllocNode(void *owner, int val, u32 heap);

void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p);

void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Args *m, struct Ov208Main *s);

extern const char d_021C8DB0[];

extern void *d_021C8508[];

extern void *d_021C8590[];

extern void *d_021C86F0[];

extern void *d_021C881C[];

/*
 * 2026-10-04 (D2-16): callee ZUKAN_DETAIL_AREA_SetHeapId filed EXACT as src/matched/ov/ZUKAN_DETAIL_AREA_SetHeapId.c (strh leaf). Still MATCH only because no
 * shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only ZUKAN_DETAIL_AREA_SetHeapId (init for mode 2, another lane) has no witness yet; bytes match.
 */
void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Args *m, struct Ov208Main *s)
{
    void **tbl;
    void *mem;
    if (s->node != 0)
        ZUKAN_DETAIL_PROCSYS_FreeNode(s->node);
    if (s->mem != 0)
        GFL_HEAP_Free(s->mem);
    switch (m->mode) {
    case 1:
        mem = GFL_HEAP_Alloc(s->heap, 2, 1, d_021C8DB0, 0x1c3);
        ZUKAN_DETAIL_INFO_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8508;
        break;
    case 2:
        mem = GFL_HEAP_Alloc(s->heap, 2, 1, d_021C8DB0, 0x1cb);
        ZUKAN_DETAIL_AREA_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8590;
        break;
    case 3:
        mem = GFL_HEAP_Alloc(s->heap, 2, 1, d_021C8DB0, 0x1d3);
        ZUKAN_DETAIL_VOICE_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C86F0;
        break;
    case 4:
        mem = GFL_HEAP_Alloc(s->heap, 2, 1, d_021C8DB0, 0x1db);
        ZUKAN_DETAIL_FORM_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C881C;
        break;
    }
    s->node = ZUKAN_DETAIL_PROCSYS_AllocNode(tbl, (int)s->mem, s->heap);
}

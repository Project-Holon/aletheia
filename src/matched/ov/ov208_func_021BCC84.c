/*
 * function: ZUKAN_DETAIL_MAIN_SwitchScreen
 * address: 0x021BCC84
 * packet: pkt_ov208_021BCC84
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-04 (D2-16): callee ZUKAN_DETAIL_AREA_SetHeapId filed EXACT as src/matched/ov/ov208_func_021BF784.c (strh leaf). Still MATCH only because no
 * shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   ZUKAN_DETAIL_PROCSYS_FreeNode 0x021BC26C thumb
 *   ZUKAN_DETAIL_PROCSYS_AllocNode 0x021BC240 thumb
 *   func_021BEA00 0x021BEA00 thumb
 *   ZUKAN_DETAIL_AREA_SetHeapId 0x021BF784 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetHeapId 0x021C255C thumb
 *   ZUKAN_DETAIL_FORM_SetHeapId 0x021C3B68 thumb
 *   d_021C8DB0 0x021C8DB0 data a1
 *   d_021C8508 0x021C8508 data a4
 *   d_021C8590 0x021C8590 data a4
 *   d_021C86F0 0x021C86F0 data a4
 *   d_021C881C 0x021C881C data a4
 * 2026-10-02: only ZUKAN_DETAIL_AREA_SetHeapId (init for mode 2, another lane) has no witness yet; bytes match.
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Mode { int f0; int mode; };
struct Ov208Slot {
    u16 heap; u16 pad;
    int f4; int f8; int fc; int f10; int f14; int f18; int f1c;
    void *obj;
    void *mem;
};
extern const char d_021C8DB0[];
extern void *d_021C8508[];
extern void *d_021C8590[];
extern void *d_021C86F0[];
extern void *d_021C881C[];
struct Ov208Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p);
extern struct Ov208Obj *ZUKAN_DETAIL_PROCSYS_AllocNode(void *owner, int val, u32 heap);
extern void func_021BEA00(void *mem, u32 heap);
extern void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v);
extern void ZUKAN_DETAIL_VOICE_SetHeapId(u16 *dst, u16 value);
extern void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value);
void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Mode *m, struct Ov208Slot *s)
{
    void **tbl;
    void *mem;
    if (s->obj != 0)
        ZUKAN_DETAIL_PROCSYS_FreeNode(s->obj);
    if (s->mem != 0)
        func_020307B0(s->mem);
    switch (m->mode) {
    case 1:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1c3);
        func_021BEA00(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8508;
        break;
    case 2:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1cb);
        ZUKAN_DETAIL_AREA_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8590;
        break;
    case 3:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1d3);
        ZUKAN_DETAIL_VOICE_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C86F0;
        break;
    case 4:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1db);
        ZUKAN_DETAIL_FORM_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C881C;
        break;
    }
    s->obj = ZUKAN_DETAIL_PROCSYS_AllocNode(tbl, (int)s->mem, s->heap);
}

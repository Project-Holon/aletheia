/*
 * function: COMM_TVT_SYS_PlaceSlotMarker
 * address:  0x021BE210
 * packet:   pkt_ov172_021BE210
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Places a slot marker: k = idx (2 or 3 for slots 0/1 in mode 1), checks the slot with
 * CTVT_COMM_IsSlotActive and CTVT_COMM_GetSlotConnected, then sets the sprite position from the xv/yv byte tables.
 * idx is a u8 slot index (the sibling CTVT_CALL_UpdateMemberWindows walks the same slots with a u8 i). The u8
 * parameter is what keeps the third-call idx reload after the byte copies (wD9r lane48).
 *
 * symbols:
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   CTVT_COMM_IsSlotActive 0x021B8BA4 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   CTVT_COMM_GetSlotParam 0x021B8B94 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021C7048 0x021C7048 data ov172
 *   d_021C704C 0x021C704C data ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q { u8 b[4]; };
struct Pt { u16 x; u16 y; struct Q yv; struct Q xv; };
extern int COMM_TVT_SYS_GetLayoutMode(void *p);
extern u32 CTVT_COMM_IsSlotActive(int unused, char *base, int i);
extern u32 CTVT_COMM_GetSlotConnected(int unused, char *base, int i);
extern char *CTVT_COMM_GetSlotParam(int unused, char *base, int i);
extern void *func_02008510(void *a, int tag);
struct Actor;
struct Obj;
struct StrObj;
struct U16Vec;
struct Vec2;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern const struct Q d_021C7048;
extern const struct Q d_021C704C;
void COMM_TVT_SYS_PlaceSlotMarker(char *a, u8 idx)
{
    struct Pt rc;
    void *h;
    u32 v;
    int mode;
    u32 k;
    mode = COMM_TVT_SYS_GetLayoutMode(a);
    k = idx;
    if (*(int *)(a + 8) == 3) return;
    if (mode == 1) k = (k == 0) ? 2 : 3;
    if (CTVT_COMM_IsSlotActive((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    if (CTVT_COMM_GetSlotConnected((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    rc.xv = d_021C704C;
    rc.yv = d_021C7048;
    h = func_02008510(CTVT_COMM_GetSlotParam((int)a, *(char **)(a + 0x1E4), idx), *(u16 *)a);
    v = (u8)func_0201D304(h, *(u32 *)(a + 0x1C8), 0);
    STRBUF_Delete(h);
    { u32 xk = rc.xv.b[k]; rc.x = xk + (v >> 1); }
    rc.y = rc.yv.b[k];
    CLACT_AddActorSurfacePos(*(void **)(a + 0x1B0), (const struct Vec2 *)(&rc), 0);
    CLACT_SetActorDrawEnable(*(void **)(a + 0x1B0), 1);
    CLACT_RestartActorAnim(*(void **)(a + 0x1B0));
}

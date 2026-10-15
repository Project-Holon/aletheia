/*
 * function: WF2DMAP_TOUCH_CreateEditWidgets
 * address: 0x021C9628
 * packet: pkt_ov128_021C9628
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: the matched callees WF2DMAP_TOUCH_InitTileRecord and WF2DMAP_TOUCH_SetTileRecordField declare 4 parameters,
 *   but this caller passes the heap id as a stack argument (5th for 9ED0, 6th for 9EF4); the
 *   prototypes below carry the real arity. The heap id is u16 here and in all callee prototypes
 *   (narrow param puts its home store first); the inner counter is long.
 * symbols:
 *   WF2DMAP_TOUCH_CreateWidgetHandles 0x021C9E10 thumb ov128
 *   WF2DMAP_TOUCH_CreateTileWidgets 0x021C9E6C thumb ov128
 *   func_021C63AC 0x021C63AC thumb ov128
 *   WF2DMAP_TOUCH_InitTileRecord 0x021C9ED0 thumb ov128
 *   WF2DMAP_TOUCH_SetTileRecordField 0x021C9EF4 thumb ov128
 *   d_021CA564 0x021CA564 data a2
 *   d_021CA538 0x021CA538 data a4
 *   d_021CA7E0 0x021CA7E0 data a4
 *   d_021CA521 0x021CA521 data a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
extern const s16 d_021CA564[][3];
extern const u32 d_021CA538[], d_021CA7E0[];
extern const u8 d_021CA521[];
extern void WF2DMAP_TOUCH_CreateWidgetHandles(u8 *, u8 *, u16);
extern void WF2DMAP_TOUCH_CreateTileWidgets(u8 *, void *);
extern void func_021C63AC(void *p, u32 *out, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u32 unused, u8 g);
extern void WF2DMAP_TOUCH_InitTileRecord(u32, int, const u16 *, u32, u16);
extern void WF2DMAP_TOUCH_SetTileRecordField(u32, int, u32, u32, u32, u16);
static inline int absolute(s16 value) { if (value < 0) return -value; return value; }
void WF2DMAP_TOUCH_CreateEditWidgets(u8 *p, void *unused, u8 *q, u16 heap)
{
    int i, k, x, y; long j;
    const s16 *row;
    WF2DMAP_TOUCH_CreateWidgetHandles(p + 0xf8, q, heap);
    WF2DMAP_TOUCH_CreateTileWidgets(p, q);
    for (k = 0; k < 2; k++) {
        row = d_021CA564[k];
        y = absolute(row[1]);
        x = absolute(row[0]);
        func_021C63AC(q, (u32 *)(p + 0x118 + k * 8), 3, (u8)(x + 2), y + 1, 26, 18, 10, 0, 0);
    }
    for (i = 0; i < 3; i++) {
        WF2DMAP_TOUCH_InitTileRecord((u32)(p + 20 + i * 0x4c), (int)q, (const u16 *)d_021CA564[i], d_021CA538[i], heap);
        for (j = 0; j < 8; j++) {
            WF2DMAP_TOUCH_SetTileRecordField((u32)(p + 20 + i * 0x4c), (int)q, j, d_021CA521[j], d_021CA7E0[j], heap);
            *(void **)(p + 0x20 + j * 4) = p + 0x118;
            *(void **)(p + 0x6c + j * 4) = p + 0x120;
            *(void **)(p + 0xb8 + j * 4) = p + 0x120;
        }
    }
}

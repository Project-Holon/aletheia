/*
 * function: Wf2dmapFriend_InitItemWidgets
 * address: 0x021C7ACC
 * packet: pkt_ov128_021C7ACC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_CreateWindow 0x021C63AC thumb ov128
 *   Wf2dmapFriend_CopyPos 0x021C88AC thumb ov128
 *   WIFI_2DCHAR_Create 0x021C3EE0 thumb ov127
 *   WIFI_2DCHAR_SetupCells 0x021C4044 thumb ov127
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_021CA564 0x021CA564 data a4
 *   d_021CA688 0x021CA688 data a4
 *   d_021CA650 0x021CA650 data a4
 *   d_021CA638 0x021CA638 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u16 a, b, c, d; } Rect;
struct MsgBank;
struct Obj;
struct R;
struct U16Vec;
extern void Wf2dmapFriend_CreateWindow(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
extern void Wf2dmapFriend_CopyPos(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap);
extern void *WIFI_2DCHAR_Create(void *, void *, u32, u32);
extern void WIFI_2DCHAR_SetupCells(u8 *, int, int, int, int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
typedef struct { s16 x, y, z; } V3;
typedef struct { u32 a, b; } W2;
extern const V3 d_021CA564[];
extern const W2 d_021CA688[];
extern const Rect d_021CA650;
extern const Rect d_021CA638;
static inline int iabs(int v)
{
    return v < 0 ? -v : v;
}
void Wf2dmapFriend_InitItemWidgets(u8 *p, void *unused, u8 *ctx, u16 heap)
{
    int i;
    int j;
    Rect r1;
    Rect r2;
    for (i = 0; i < 2; i++) {
        Wf2dmapFriend_CreateWindow(ctx, (u32 *)(p + 0xf0 + i * 8), 3,
            (u8)(iabs(d_021CA564[i].x) + 4), (u8)(iabs(d_021CA564[i].y) + 4), 0x1a, 0x11, 0xa, 0, 0);
    }
    for (j = 0; j < 3; j++)
        Wf2dmapFriend_CopyPos((u16 *)(p + 12 + j * 0x4c), (u16 *)ctx, (u16 *)((const void *)&d_021CA564[j]), 0, heap);
    *(u8 **)(p + 0x14) = p + 0xf0;
    *(u8 **)(p + 0xac) = p + 0xf8;
    *(u8 **)(p + 0x60) = p + 0xf8;
    *(void **)(p + 0x104) = WIFI_2DCHAR_Create(*(void **)(ctx + 0x13c), 0, 0x10, heap);
    WIFI_2DCHAR_SetupCells(*(u8 **)(p + 0x104), 0, 2, 0xe0, heap);
    for (i = 0; i < 4; i++) {
        const W2 *e = &d_021CA688[i];
        *(void **)(p + i * 12 + 0x118) = func_02045EC0(*(struct MsgBank **)(ctx + 4), d_021CA688[i].a);
        *(u16 *)(p + i * 12 + 0x11c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x120) = 0;
        *(void **)(p + i * 12 + 0x148) = func_02045EC0(*(struct MsgBank **)(ctx + 4), e[4].a);
        *(u16 *)(p + i * 12 + 0x14c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x150) = 0;
    }
    *(u32 *)(p + 0x144) = 1;
    *(u32 *)(p + 0x174) = 1;
    *(void **)(p + 0x178) = func_02045EC0(*(struct MsgBank **)(ctx + 4), 0x42);
    *(u16 *)(p + 0x17c) = 0x39e3;
    *(u32 *)(p + 0x180) = 0;
    *(void **)(p + 0x184) = func_02045EC0(*(struct MsgBank **)(ctx + 4), 0x43);
    *(u16 *)(p + 0x188) = 0x39e3;
    *(u32 *)(p + 0x18c) = 0;
    *(struct R **)(p + 0x190) = APP_TASKMENU_RES_Create(1, 14, *(u32 *)(ctx + 0x17c), *(u32 *)(ctx + 0x34), heap);
    Wf2dmapFriend_CreateWindow(ctx, (u32 *)(p + 0x108), 1, 2, 1, 0x1b, 4, 0xa, 0, 0xf);
    *(struct U16Vec **)(p + 0x110) = STRBUF_Create(0x80, heap);
    r1 = d_021CA650;
    *(struct Obj **)(p + 0x1a0) = CLACT_CreateActor(*(void **)(ctx + 0x138), *(u32 *)(ctx + 0x144), *(u32 *)(ctx + 0x14c), *(u32 *)(ctx + 0x154), &r1, 0, heap);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x1a0), 0);
    r2 = d_021CA638;
    *(struct Obj **)(p + 0x1a4) = CLACT_CreateActor(*(void **)(ctx + 0x138), *(u32 *)(ctx + 0x144), *(u32 *)(ctx + 0x14c), *(u32 *)(ctx + 0x154), &r2, 0, heap);
}

/*
 * function: BTLV_CORE_Create
 * address: 0x021E8F20
 * packet: pkt_ov093_021E8F20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   BTL_CLIENT_GetClientId 0x021D3D70 thumb ov093
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   BTLV_SCU_Create 0x021EAF7C thumb ov093
 *   func_021E9024 0x021E9024 thumb ov093
 *   BTL_MSG_Init 0x021EEC78 thumb ov093
 *   gBtlvCoreFileName 0x021F3AC4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Scene {
    void *a, *b;
    u32 c;
    u8 index, pad0d[3];
    int state, f14, f18;
    u8 pad1c[0x90];
    void *buffer, *font0, *font2;
    u8 padb8[0xbc];
    u8 flag, pad175[3];
    void *ctx, *view, *other;
    u16 heap;
    u8 pad186[2];
};
extern const char gBtlvCoreFileName[];
struct GfFont;
struct Tcbl;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 BTL_CLIENT_GetClientId(u8 *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *BTLV_SCU_Create(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap);
extern void *func_021E9024(struct Scene *, void *, u32, void *, void *, void *, int, u16);
extern void BTL_MSG_Init(u32, u32, u32, u32);
struct Scene *BTLV_CORE_Create(void *a, void *b, u32 c, int d, u16 heap)
{
    struct Scene *p;
    p = func_02030734(heap, 0x188, 0, gBtlvCoreFileName, 0x12d);
    p->a = a;
    p->b = b;
    p->c = c;
    p->index = BTL_CLIENT_GetClientId(b);
    p->state = 4;
    p->heap = heap;
    p->buffer = STRBUF_Create(0x200, heap);
    p->font0 = GF_FONT_Create(0x17, 0, 0, 0, heap);
    p->font2 = GF_FONT_Create(0x17, 2, 0, 0, heap);
    p->ctx = TCBL_Create(heap, heap, 0x40, 0x80);
    p->view = BTLV_SCU_Create((u32)p, (u32)p->a, c, (u32)p->ctx, (u32)p->font0, (u32)p->font2, p->index, heap);
    p->other = func_021E9024(p, p->a, c, p->ctx, p->font0, p->b, d, heap);
    p->f14 = 0;
    p->f18 = 0;
    p->flag = 0;
    BTL_MSG_Init((u32)a, p->index, c, heap);
    return p;
}

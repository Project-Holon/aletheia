/*
 * function: func_021F8D10
 * address: 0x021F8D10
 * packet: pkt_ov135_021F8D10
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: ov115 data hint is witnessed by this function loading ov115 via func_02031348; no hint remains MATCH.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031348 0x02031348 arm
 *   func_021F8E88 0x021F8E88 thumb ov135
 *   str_02203C34 0x02203C34 data a1
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    void *handle;
    u32 f4, f8, fc;
    void *f10;
    u32 f14, f18, f1c;
    void (*callback)(void *, void *);
    void *user;
} State;
extern const char str_02203C34[], ov115_id[];
extern const u32 d_021D6338[];
extern int func_021F8E88(void *dialog, u8 *p);
typedef unsigned short u16;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 value, u32 size);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02031348(void *h, u32 id, const void *a, void *b);
extern void func_0200F7B8(u32 mode);
int func_021F8D10(u8 *p)
{
    State *s;
    *(State **)(p + 0x10DC) = func_02030734(0x48, sizeof(State), 0, str_02203C34, 0x263);
    func_02082BCC(*(State **)(p + 0x10DC), 0, sizeof(State));
    s = *(State **)(p + 0x10DC);
    s->handle = func_020120F4(*(void **)(*(u8 **)p + 0x40));
    s->f4 = 0;
    s->f8 = 1;
    s->f10 = p + 0x116C;
    s->fc = 30;
    s->callback = (void (*)(void *, void *))func_021F8E88;
    s->user = p;
    *(u32 *)(p + 0x12EC) = 0;
    if (*(u32 *)(p + 0x20) == 21) s->f14 = 1;
    else s->f14 = 0;
    func_02031348(*(void **)(p + 0x12F0), (u32)ov115_id, d_021D6338, *(State **)(p + 0x10DC));
    func_0200F7B8(0);
    *(u32 *)(p + 0x28) = 3;
    return 2;
}

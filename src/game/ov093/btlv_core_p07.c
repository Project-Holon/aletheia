/*
 * file:     btlv_core_p07.c
 * unit:     yes
 * function: func_021E8E38, func_021E8F08, func_021E8F20
 * address:  0x021E8E38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   d_021F387C 0x021F387C data a4
 *   d_021F3850 0x021F3850 data a4
 *   d_021F3860 0x021F3860 data a4
 *   func_021F7808  0x021F7808  thumb  ov094
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02046788  0x02046788  arm
 *   func_02030734 0x02030734 arm
 *   func_021D3D70 0x021D3D70 thumb ov093
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_021EAF7C 0x021EAF7C thumb ov093
 *   func_021E9024 0x021E9024 thumb ov093
 *   func_021EEC78 0x021EEC78 thumb ov093
 *   d_021F3AC4 0x021F3AC4 data a4
 */
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
struct DispConfig;
struct DispVram;
struct Cfg;
struct GfFont;
struct Tcbl;
struct U16Vec;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

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

extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02046440(u32, u32, u32, u32, u16, u16, void (*)(void));
extern void func_02046BE0(u32, u32);
extern void func_0207DC44(int, int, int, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_021F7808(void);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02046788(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_021D3D70(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *func_021EAF7C(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap);
extern void *func_021E9024(struct Scene *, void *, u32, void *, void *, void *, int, u16);
extern void func_021EEC78(u32, u32, u32, u32);
void func_021E8E38(u16 heap);
void func_021E8F08(void);
struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern const u32 d_021F387C[], d_021F3850[], d_021F3860[];
extern const char d_021F3AC4[];

/*
 * lever: the POWCNT read/OR/write is spelled as assignment, not compound assignment.
 * volatile: 021E8E60 POWCNT; 021E8E8E,021E8E9C,021E8EA4 DISP3DCNT; 021E8EBE BG0CNT.
 */
void func_021E8E38(u16 heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021F387C);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28((struct DispConfig *)d_021F3850);
    func_02046440(0, 1, 0, 1, 0, heap, 0);
    func_02046BE0(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    func_0207DC44(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0207D63C((void *)0x04000050, 2, 0x3d, 0x1f, 3);
    func_0204A48C((const struct Cfg *)d_021F3860, (u32)d_021F387C, heap);
}


void func_021E8F08(void)
{
    func_021F7808();
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
    func_02046788();
}

struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap)
{
    struct Scene *p;
    p = func_02030734(heap, 0x188, 0, d_021F3AC4, 0x12d);
    p->a = a;
    p->b = b;
    p->c = c;
    p->index = func_021D3D70(b);
    p->state = 4;
    p->heap = heap;
    p->buffer = func_020457B0(0x200, heap);
    p->font0 = func_0201D7EC(0x17, 0, 0, 0, heap);
    p->font2 = func_0201D7EC(0x17, 2, 0, 0, heap);
    p->ctx = func_0203101C(heap, heap, 0x40, 0x80);
    p->view = func_021EAF7C((u32)p, (u32)p->a, c, (u32)p->ctx, (u32)p->font0, (u32)p->font2, p->index, heap);
    p->other = func_021E9024(p, p->a, c, p->ctx, p->font0, p->b, d, heap);
    p->f14 = 0;
    p->f18 = 0;
    p->flag = 0;
    func_021EEC78((u32)a, p->index, c, heap);
    return p;
}

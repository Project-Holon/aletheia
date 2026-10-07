/*
 * file:     unit_021C6000_p03.c
 * unit:     yes
 * function: func_021C67E8, func_021C6804, func_021C6874, func_021C68F0
 * address:  0x021C67E8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021C63B8  0x021C63B8  thumb  ov111
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0201F35C  0x0201F35C  thumb
 *   func_0201D304  0x0201D304  thumb
 *   d_021C8768     0x021C8768  data  a2
 */
struct Cfg;
struct CharBuf;
struct Descriptor;
struct StrObj;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x32FA];
    u8 list[0x13];
    u8 count;
} Work_021C67E8;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x68];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Info;

typedef struct {
    u8 pad0[0x1C];
    void *bg;
    u8 pad20[0x32FA - 0x20];
    u8 list[0x13];
} Work_021C6874;

typedef unsigned short u16;

typedef short s16;

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work_021C68F0;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);
extern void func_021C63B8(Work_021C6874 *p, void *a, int sel, int y, int idx);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201F35C(void *ctx, int n, u32 kind, u32 mode, u32 flag);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_021C67E8(Work_021C67E8 *p, int v);
void func_021C6804(void *p, Info *info);
void func_021C6874(Work_021C6874 *p, int scroll, int flush, int idx);
void func_021C68F0(Work_021C68F0 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx);
extern const u16 d_021C8768[];


/*
 * Addresses are Black-image addresses.
 */
void func_021C67E8(Work_021C67E8 *p, int v)
{
    p->list[p->count] = v;
    p->count++;
}


void func_021C6804(void *p, Info *info)
{
    int i;

    for (i = 0; i < 13; i++) {
        func_021C67E8(p, i);
    }
    if (info->b0) {
        func_021C67E8(p, 14);
        func_021C67E8(p, 13);
    }
    if (info->b1) {
        func_021C67E8(p, 15);
    }
    if (info->b2) {
        func_021C67E8(p, 16);
    }
    if (info->b3) {
        func_021C67E8(p, 17);
    }
    if (info->b4) {
        func_021C67E8(p, 18);
    }
}


void func_021C6874(Work_021C6874 *p, int scroll, int flush, int idx)
{
    void *bg = p->bg;
    int i;
    int top = -(scroll / 16);

    func_02043B5C(func_02045770(bg), 0);
    for (i = 0; i < 5; i++) {
        func_021C63B8(p, bg, p->list[i + top], scroll % 16 + i * 16, idx);
    }
    if (flush) {
        func_02045334(bg);
        func_02045374(bg);
        func_02041B6C(func_02045730(bg));
    }
}


void func_021C68F0(Work_021C68F0 *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx)
{
    u32 w;

    func_0201F35C(s, n, kind, mode, 1);
    w = func_0201D304(s, (u32)p->f31FC, 0);
    func_0201C7D0(func_02045770(a), x - (w + dx), y, s, p->f31FC, d_021C8768[idx]);
}

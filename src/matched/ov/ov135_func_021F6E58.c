/*
 * function: func_021F6E58
 * address:  0x021F6E58
 * packet:   pkt_021F6E58
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F50EC  0x021F50EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02202608  0x02202608  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_021F72C4  0x021F72C4  thumb
 *   func_0200AD9C  0x0200AD9C  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02034714  0x02034714  arm
 *   func_02031348  0x02031348  arm
 *   str_02203B6C   0x02203B6C  data  a1
 *   d_021E75B4     0x021E75B4  data  ov119
 *   d_021E75CC     0x021E75CC  data  ov119
 *   d_021E75FC     0x021E75FC  data  ov119
 *   ov119_id       0x00000077  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x30];
    void *f30;
    void *f34;
    void *f38;
    u32 f3C;
    void *f40;
} Req;

typedef struct {
    void *sys;
    u8 pad4[0x1C - 4];
    u32 f1C;
    u8 pad20[0x40 - 0x20];
    void *f40;
} Ctx;

typedef struct {
    u8 data[0x128];
} Entry;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xB8 - 0x24];
    u32 fB8;
    u8 padBC[0xD4 - 0xBC];
    int cur;
    void *info;
    u8 padDC[0xE4 - 0xDC];
    u8 mon[0x207 - 0xE4];
    s8 f207;
    u8 pad208[0x20C - 0x208];
    Entry arr[8];
    u8 padB4C[0xEA4 - 0xB4C];
    void *saveMon;
    void *fEA8;
    u8 padEAC[0x10DC - 0xEAC];
    Req *req;
    u8 pad10E0[0x12E4 - 0x10E0];
    u32 f12E4;
    u8 pad12E8[0x12F0 - 0x12E8];
    void *f12F0;
} Work;

extern char str_02203B6C[];
extern u8 d_021E75B4[];
extern u8 d_021E75CC[];
extern u8 d_021E75FC[];
extern u8 ov119_id[];

extern void func_021F50EC(Work *p);
struct Ctx;
struct RecDC;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200ADB4(void *sys);
extern void *func_021F72C4(void *e);
extern void func_0200AD9C(void *sys, void *mon);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02031348(void *h, u32 id, void *a, void *b);

int func_021F6E58(Work *p)
{
    Req *d;
    void *tmpl;

    func_021F50EC(p);
    p->req = func_02030734(0x48, 0x44, 0, str_02203B6C, 0x5E);
    func_02082BCC(p->req, 0, 0x44);
    d = p->req;
    p->saveMon = func_02202608(0x48);
    d->f30 = func_020120F4(p->ctx->f40);
    d->f3C = p->ctx->f1C;
    switch (p->kind) {
    case 7:
        d->f38 = d->f34 = func_0200ADB4(p->ctx->sys);
        d->f40 = p->info = func_021F72C4(p->mon);
        tmpl = d_021E75FC;
        break;
    case 8:
        if (p->f207 != 0) {
            d->f38 = p->mon;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        d->f34 = d->f38;
        d->f40 = p->info = func_021F72C4(p->mon);
        tmpl = d_021E75B4;
        break;
    case 10:
        if (p->f207 != 0) {
            d->f38 = p->mon;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        func_0200AD9C(p->ctx->sys, p->saveMon);
        d->f34 = p->saveMon;
        d->f40 = p->info = func_021F72C4(p->mon);
        tmpl = d_021E75CC;
        break;
    case 9:
        func_02019CE0(p->fEA8, p->saveMon);
        d->f34 = p->fEA8;
        d->f38 = &p->arr[p->cur];
        d->f40 = p->info = func_021F72C4(&p->arr[p->cur]);
        tmpl = d_021E75CC;
        break;
    default:
        func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
        break;
    }
    func_02031348(p->f12F0, (u32)ov119_id, tmpl, p->req);
    p->fB8 = 1;
    p->f12E4 = 0;
    return 1;
}

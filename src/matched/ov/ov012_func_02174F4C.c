/*
 * function: func_02174F4C
 * address:  0x02174F4C
 * packet:   pkt_ov012_02174F4C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02030734  0x02030734  arm
 *   func_02167518  0x02167518  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_0216F40C  0x0216F40C  thumb
 *   str_02175630   0x02175630  data  ov012
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f000;
    u8 pad004[0x18 - 4];
    u8 slot[4][0x2c];
    u8 pad0c4[0xcc - 0x18 - 4 * 0x2c];
    u8 fcc[4];
    u8 fd0[4];
    u8 pad0d4[0xdc - 0xd4];
    u8 fdc;
    u8 fdd;
    u8 pad0de[0x134 - 0xde];
    void *f134[4];
    u8 f144[4];
    void *f148[4];
    u8 pad158[0x170 - 0x158];
} Work;

struct Entry;
struct Link;
struct Obj;
struct Party;
extern char str_02175630[];
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02167518(u32 a, u32 b, u32 c, u32 d);
extern struct Party *func_0201A920(u32 heap);
struct BigObj;
struct Rec534;
extern void *func_02012934(const struct BigObj *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_02008494(void *src, void *dst);
extern void func_02087C6C(void *p);
extern void func_0216F40C(void *a, u32 b, u32 c, u32 d, u32 e);

Work *func_02174F4C(const struct Obj *obj, u32 a1, u32 a2, u32 a3)
{
    Work *w;
    u32 idx;
    int i;
    u8 *s;
    u32 v;

    idx = func_0203D1A4((struct Link *)func_020399A8());
    w = func_02030734(0x41, 0x170, 1, str_02175630, 0x35);
    w->f000 = func_02167518(4, a1, 0x41, 0);
    for (i = 0; i < 4; i++) {
        w->f134[i] = func_02030734(0x41, 0x678, 1, str_02175630, 0x38);
        w->f148[i] = func_0201A920(0x41);
    }
    for (i = 0; i < 4; i++) {
        w->fcc[i] = 0xff;
        w->fd0[i] = 0xff;
    }
    w->fdc = 0xff;
    w->fdd = 0xff;
    func_0201AC2C(func_02012934((const struct BigObj *)obj), w->f148[idx]);
    s = w->slot[idx];
    func_02008494((void *)a2, s);
    func_02087C6C(s + 0x20);
    s[0x26] = 1;
    v = 1;
    if (a3 == 1) {
        v = 0;
    }
    s[0x27] = v;
    s[0x28] = 0x64;
    func_0216F40C(w->f134[idx], (u32)obj, 1, 0, 0x41);
    w->f144[idx] = 1;
    return w;
}

/*
 * function: func_02166854
 * address:  0x02166854
 * packet:   pkt_ov010_02166854
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the 0x128-byte task for func_02166908, stores its arguments,
 * then fills a 232-entry flag byte table (+0x30) and a 20-entry halfword
 * table (+0x08) from a lookup object, zero padding the halfwords.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009794  0x02009794  thumb
 *   func_020095C8  0x020095C8  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02166908  0x02166908  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Task {
    u8 f00;
    u8 pad01[7];
    u16 h[20];
    u8 flag[232];
    u8 pad118[4];
    u32 f11c;
    u32 f120;
    u32 f124;
};

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02009470Ent;
struct Sub02009470Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 func_02009794(const struct Sub02009470Obj *obj, u32 n);
extern u8 func_020095C8(const struct Sub02009470Obj *obj);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern void func_02166908();

void *func_02166854(void *a, u8 b, u32 c, u32 d, u32 e)
{
    void *task;
    struct Task *t;
    void *o;
    int i;
    int n;
    int j;

    task = func_020122C0(a, 0, func_02166908, 0x128);
    t = func_020124E8(task);
    t->f00 = b;
    t->f124 = e;
    t->f11c = c;
    t->f120 = d;
    o = func_02009470(func_02012EBC(func_020120F4(a)));
    for (i = 1; i < 0xE9; i++) {
        j = i - 1;
        if (func_02009794(o, i))
            t->flag[j] = 1;
        else
            t->flag[j] = 0;
    }
    n = func_020095C8(o);
    if (n > 20)
        n = 20;
    for (i = 0; i < n; i++)
        t->h[i] = func_0200856C((const struct Sub0200852CObj *)func_0200973C(o, i));
    for (; i < 20; i++)
        t->h[i] = 0;
    return task;
}

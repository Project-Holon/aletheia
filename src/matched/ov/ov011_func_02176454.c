/*
 * function: func_02176454
 * address:  0x02176454
 * packet:   pkt_ov011_02176454
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02031324  0x02031324  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201BA34  0x0201BA34  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201AB34  0x0201AB34  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_02034714  0x02034714  arm
 *   d_02177010     0x02177010  data  ov011  a1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 w0;
    u8  pad4;
    u8  b5;
    u8  b6;
} Arg;

extern u8 d_02177010[];
extern u8 *func_0203159C(int a, int size, int align);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02031324(int heap);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
struct Party;
struct PartyMon;
extern void *func_02012934(const struct BigObj *p);
extern void func_0201BA34(void *p);
extern u32 func_0201AA18(void *p);
extern struct Party *func_0201A920(u32 heap);
extern u32 func_0201AB34(void *p, u32 idx);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_02019CA0(void *p, u32 v);
extern void func_02034714(void *a, int b, void *c);

int func_02176454(int a0, int a1, Arg *arg)
{
    u8 *w;
    int n;
    void *list;
    int i;
    int cnt;

    cnt = 0;
    w = func_0203159C(a0, 0x100, 4);
    func_02082BCC(w, 0, 0x100);
    *(void **)(w + 0xf4) = func_02031324(4);
    list = func_02012934(func_020120F4((const struct Ctx *)arg->w0));
    func_0201BA34(list);
    n = func_0201AA18(list);
    *(void **)(w + 0xf8) = func_0201A920(4);
    for (i = 0; i < n; i++) {
        if (cnt >= arg->b6) {
            break;
        }
        if (func_0201AB34(list, i) == 1) {
            func_0201A98C(*(void **)(w + 0xf8), func_0201AB28(list, i));
            func_02019CA0(func_0201AB28(*(void **)(w + 0xf8), cnt), arg->b5);
            cnt++;
        }
    }
    if (cnt <= 0) {
        func_02034714(d_02177010, 0, d_02177010);
    }
    return 1;
}

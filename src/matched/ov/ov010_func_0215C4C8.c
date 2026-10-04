/*
 * function: func_0215C4C8
 * address:  0x0215C4C8
 * packet:   pkt_ov010_0215C4C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201293C  0x0201293C  thumb
 *   func_02007984  0x02007984  thumb
 *   func_0215C40C  0x0215C40C  thumb  ov010
 *   func_020185F4  0x020185F4  thumb
 *   func_020074D8  0x020074D8  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
struct Sub02007454Entry;
extern u32 func_0201293C(const struct BigObj *p);
extern int func_02007984(void *a);
extern void *func_0215C40C(void *a, void *b);
extern void *func_020185F4(void *p);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void *func_0200CA1C(void *a);
struct Blk37;
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void func_020307B0(void *a);

int func_0215C4C8(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = (void *)func_0201293C(a);
    if (func_02007984(r6) >= 0x2D0)
        return 0;
    r5 = func_0215C40C(a, b);
    func_020074D8(r6, (const struct Sub02007454Entry *)((u32)func_020185F4(r5)));
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}

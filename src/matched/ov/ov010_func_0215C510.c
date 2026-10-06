/*
 * function: func_0215C510
 * address:  0x0215C510
 * packet:   pkt_ov010_0215C510
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0215C40C  0x0215C40C  thumb  ov010
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
struct Blk37;
struct Party;
struct PartyMon;
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA18(void *p);
struct Spec;
extern void *func_0215C40C(void *a, struct Spec *s);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void func_020307B0(void *a);

int func_0215C510(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = func_02012934(a);
    if ((int)func_0201AA14(r6) <= (int)func_0201AA18(r6))
        return 0;
    r5 = func_0215C40C(a, b);
    func_0201A98C(r6, r5);
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}

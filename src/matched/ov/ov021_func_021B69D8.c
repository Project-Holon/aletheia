/*
 * function: func_021B69D8
 * address:  0x021B69D8
 * packet:   pkt_ov021_021B69D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_021690A4  0x021690A4  thumb  ov010
 *   func_02087C88  0x02087C88  arm
 *   func_0200A940  0x0200A940  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_0200A8C8  0x0200A8C8  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Owner {
    u8 f0;
    u8 f1;
    u8 month;
    u8 day;
    u8 rest[0x50];
};

extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(void *, void *);
struct Big;
struct Rec;
struct U16Vec;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
struct Entry;
struct Strbuf;
extern void *func_021690A4(int a0);
struct OSOwnerInfo;
extern void func_02087C88(struct OSOwnerInfo *info);
extern int func_0200A940(void *, int, int, void *);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(u32, u32, void *, int, int, int);
extern void func_02045808(struct U16Vec *vec);

u32 func_021B69D8(void *a, void *b)
{
    void *r5 = func_0215A5E4(b);
    u32 s8 = func_02159B10(a, b);
    void *r4;
    int r6;
    int fl;
    void *v;
    u32 r7;
    struct Owner o;

    r4 = func_0200A8A0(func_02012EBC(r5));
    r5 = func_021690A4((int)r5);
    func_02087C88((struct OSOwnerInfo *)(&o));
    r6 = func_0200A940(r4, o.month, o.day, r5);
    fl = func_0200A8F8(r4, r6);
    fl = fl != 1;
    r6 = (int)func_0200A8C8(r4, r6);
    r7 = (u32)func_02158F74(func_0215A5F4(b));
    v = func_020457B0(8, 0x8001);
    func_02045924(v, (const u16 *)r6);
    func_0201EE0C(r7, s8, v, fl, 1, 2);
    func_02045808(v);
    return 0;
}

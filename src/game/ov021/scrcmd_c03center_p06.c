/*
 * file:     scrcmd_c03center_p06.c
 * unit:     yes
 * function: func_021B6934, func_021B69B0, func_021B69D8, func_021B6A78, func_021B6AA4
 * address:  0x021B6934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_02158F58  0x02158F58  thumb ov010
 *   func_02188D24  0x02188D24  thumb ov021
 *   func_021BB990  0x021BB990  thumb ov021
 *   ov055_id       0x00000037  data  a1
 *   d_021F45F0     0x021F45F0  data  ov055  a4
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_021690A4  0x021690A4  thumb  ov010
 *   func_02087C88  0x02087C88  arm
 *   func_0200A940  0x0200A940  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_0200A8C8  0x0200A8C8  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_0200A8AC  0x0200A8AC  thumb
 */
struct BigObj;
struct Sub0200852CObj;
struct Big;
struct Rec;
struct U16Vec;
struct Entry;
struct Strbuf;
struct OSOwnerInfo;
struct WordSet;
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

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *, u32, u32);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int, int *, const int *);
extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(void *, void *);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern void *func_021690A4(int a0);
extern void func_02087C88(struct OSOwnerInfo *info);
extern int func_0200A940(void *, int, int, void *);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern void *func_02158F74(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern u16 *func_02159AE8(void *a0, void *a1);
extern s32 func_0200A8AC(struct Rec *r);
int func_021B6934(void *a);
int func_021B69B0(void *a, void *b);
u32 func_021B69D8(void *a, void *b);
int func_021B6A78(void *a, void *b);
int func_021B6AA4(u32 a, u32 b);
extern u8 ov055_id[];
extern const int d_021F45F0[];


int func_021B6934(void *a)
{
    void *party = func_02012934(a);
    void *p = func_02012944(a);
    int n = func_0201AA18(party);
    u32 t0 = func_02008530(p);
    int i;

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (t0 == func_02017E1C(mon, 7, 0)
            && func_02017E1C(mon, 5, 0) == 0x283
            && func_02017E1C(mon, 0x4c, 0) == 0)
            return i;
    }
    return -1;
}


/*
 * d_021F45F0 is the ov055 proc table (ov055 is the overlay id passed to
 * func_021BB990), hence the ov055 token on its symbols: line.
 */
int func_021B69B0(void *a, void *b)
{
    func_021BB990((int)ov055_id, (int *)func_02188D24((u8 *)(((u32 *)func_02158F58((int)func_0215A5F4(b)))[1])), d_021F45F0);
    return 0;
}


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
    func_0201EE0C((struct WordSet *)r7, s8, v, fl, 1, 2);
    func_02045808(v);
    return 0;
}


int func_021B6A78(void *a, void *b)
{
    void *t;
    u16 *p;

    t = func_0215A5E4(b);
    p = func_02159AE8(a, b);
    *p = func_0200A8AC(func_0200A8A0(func_02012EBC(t)));
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B6AA4(u32 a, u32 b)
{
return (a + (b * 10));
}

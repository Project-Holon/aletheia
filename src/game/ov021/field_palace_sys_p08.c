/*
 * file:     field_palace_sys_p08.c
 * unit:     yes
 * function: func_021D297C, func_021D29A8, func_021D29F0, func_021D2ADC, func_021D2B18, func_021D2B54
 * address:  0x021D297C
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
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_021A0FA8  0x021A0FA8  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045180  0x02045180  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02008DFC  0x02008DFC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   d_021DD774     0x021DD774  data  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021D2CE8  0x021D2CE8  thumb  ov021
 *   func_021D2D24  0x021D2D24  thumb  ov021
 */
struct Ctx;
struct Desc;
struct Obj;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct CharBuf;
struct Stream;
struct Big;
struct Sub02008C20Obj;
struct BigObj;
struct WordSet;
struct RtcTime;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Entry;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CCC(u8 *p);
extern int func_021A0F30(u32 a, u32 b);
extern int func_021A0F94(u32 link);
extern void func_021A0FA8(int *p);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C54(u8 *p);
extern u16 func_02011330(struct Stream *s);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045180(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u32 offset);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_021904AC(u8 *p);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02041B6C(u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02041300(int, int, int, int, int, int, int);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern u8 *func_02012944(void *p);
extern void *func_02158F74(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0203F4CC(struct RtcTime *time);
extern u32 func_020056EC(u32 v);
extern void *func_02012F2C(int *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_021D2CE8(void *a, int i);
extern u32 func_021D2D24(void *a, u32 v, int c);
void *func_021D297C(void *a);
u32 func_021D29A8(u32 a, u32 *st, u32 *p);
int func_021D29F0(u32 a, u32 b);
int func_021D2ADC(u32 a, u32 b);
int func_021D2B18(u32 a, u32 b);
int func_021D2B54(u32 a, u32 b);
extern const Entry d_021DD774[];


void *func_021D297C(void *a)
{
    void *task = func_020122C0(a, 0, func_021D29A8, 8);
    u32 *w = func_020124E8(task);

    w[0] = (u32)func_0201210C((void *)a);
    w[1] = func_02188CCC((u8 *)w[0]);
    return task;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021D29A8(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        func_021A0F30(p[1], 9);
        st[0]++;
        break;
    case 1:
        if (func_021A0F94(p[1]) == 14) {
            func_021A0FA8((int *)p[1]);
            st[0]++;
        }
        break;
    case 2:
        func_021A0F30(p[1], 0);
        return 1;
    }
    return 0;
}


int func_021D29F0(u32 a, u32 b)
{
    void **q;
    u32 heap, msg, win, s;
    void *m;

    q = (void **)func_02158F58((int)func_0215A5F4((void *)b));
    heap = func_02188C84(q[1]);
    m = (void *)func_02188C54(q[1]);
    if (func_02011330((struct Stream *)a)) {
        msg = (u32)func_02045B38(0, 2, 0x16, heap);
        win = func_02045180(2, 1, 1, 0x1E, 10, 14, 0x40);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)win)), 0xF);
        func_02045334((struct Descriptor *)win);
        func_02045374((struct Cfg *)win);
        func_0201F73C((void *)win, 0, 1, 0xD);
        s = (u32)func_020457B0(0xB4, heap);
        func_02045CAC((struct MsgBank *)msg, 3, (void *)s);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)win)), 0, 0, (void *)s, (void *)func_021904AC(m));
        func_02045334((struct Descriptor *)win);
        func_02041B6C(2);
        func_02045808((struct U16Vec *)s);
        func_02045C04((struct Rec *)msg);
        func_020452E8((struct Descriptor *)win);
    } else {
        func_02041300(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}


int func_021D2ADC(u32 a, u32 b)
{
    void *x = func_0215A5DC((void *)b);
    u32 k1 = func_02159B10((void *)a, (void *)b);
    u32 k2 = func_02159B10((void *)a, (void *)b);

    func_02008DAC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k1, k2);
    return 0;
}


int func_021D2B18(u32 a, u32 b)
{
    void *x = func_0215A5DC((void *)b);
    u32 k = func_02159B10((void *)a, (void *)b);
    u16 *q = func_02159AE8((void *)a, (void *)b);

    *q = func_02008DFC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k);
    return 0;
}


int func_021D2B54(u32 a, u32 b)
{
    void *h;
    u32 name, ws, v;
    void *o;
    u16 *out;
    void *party;
    int i, n;
    void *mon;
    RtcTime t;
    int base;
    int k;
    u32 s0, s1;
    u32 tr;
    u32 e0, e1;

    o = func_0215A5F4((void *)b);
    h = func_020120F4(func_0215A5DC((void *)b));
    name = (u32)func_02012944(h);
    ws = (u32)func_02158F74(o);
    v = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    func_0201F02C((struct WordSet *)ws, 0, (void *)name);
    party = func_02012934(h);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            func_0201EE60((struct WordSet *)ws, 3, func_02017E1C(mon, 5, 0));
            break;
        }
    }
    func_0203F4CC((struct RtcTime *)(&t));
    if (t.minute < 10) {
        base = 0;
        k = func_020056EC(0x1D);
        s0 = 0;
        s1 = 0;
        tr = (u32)func_02012F2C(h);
        e0 = d_021DD774[k].a;
        if (e0 != -1) {
            s0 = func_02008DFC((struct Sub02008C20Obj *)tr, e0);
            func_0201EFA4((struct WordSet *)ws, 1, s0, d_021DD774[k].c, 0, 1);
        }
        e1 = d_021DD774[k].b;
        if (e1 != -1) {
            s1 = func_02008DFC((struct Sub02008C20Obj *)tr, e1);
            func_0201EFA4((struct WordSet *)ws, 2, s1, d_021DD774[k].d, 0, 1);
        }
        if (k < 11) {
            if (e0 != -1 && e1 != -1) {
                if (s0 == 0 || s1 == 0) {
                    k = 0;
                }
            } else if (e1 == -1 && s0 == 0) {
                k = 0;
            }
        }
        if (k < 11) {
            if ((u8)(int)func_02008550((const struct Sub0200852CObj *)name) == 1) {
                k += 11;
            }
        } else {
            k += 11;
        }
    } else if (t.minute < 0x23) {
        base = 0x28;
        k = func_020056EC(0x32);
    } else {
        base = 0x5A;
        k = func_020056EC(0x50);
    }
    *out = func_021D2D24(h, func_021D2CE8(h, base + k), v);
    return 0;
}

/*
 * function: func_021BAB04
 * address:  0x021BAB04
 * packet:   pkt_ov091_021BAB04
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017F90  0x02017F90  thumb
 *   func_02018430  0x02018430  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B9CF4  0x021B9CF4  thumb  ov091
 *   func_021B9C1C  0x021B9C1C  thumb  ov091
 *   func_021B9C64  0x021B9C64  thumb  ov091
 *   func_021B9CB0  0x021B9CB0  thumb  ov091
 *   func_021B9D58  0x021B9D58  thumb  ov091
 *   func_021B9DC0  0x021B9DC0  thumb  ov091
 *   func_021B9BF4  0x021B9BF4  thumb  ov091
 *   func_021B9AC8  0x021B9AC8  thumb  ov091
 *   func_021BB554  0x021BB554  thumb  ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct WordSet;
struct Obj;
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201ED04(struct WordSet *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017F90(void *p);
extern u32 func_02018430(void *p);
extern u32 func_0202136C(u16 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021B9CF4(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color);
extern void func_021B9C64(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color);
extern void func_021B9CB0(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color);
extern void func_021B9D58(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern void func_021B9DC0(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern u32 func_021B9BF4(u8 *p, void *mon, u32 param);
extern int func_021B9AC8(u8 *p, void *mon, u8 bit);
extern int func_021BB554(u32 p);

#define W(o) (*(int *)(s + (o)))

void func_021BAB04(u8 *a, u8 *s, int k)
{
    int f = 0;
    u32 ws;
    u32 ws2;
    u32 ws3;
    u32 code;
    u32 m;
    u32 r5;
    u32 r6;
    u32 v;
    u16 r;
    u8 *obj;

    if (*(int *)(*(u8 **)(a + 0x280) + 0x34) == 6 || *(int *)(a + 0x18) == 1) {
        f = 1;
    }
    if (k == 0) {
        ws = (u32)func_0201EC64(*(u16 *)a);
        func_0201EEF4((struct WordSet *)ws, 0, *(void **)s);
        func_021B9CF4(a, W(0x20), (void *)ws, 3, 0x29, 9, 0x440);
        func_0201ED04((struct WordSet *)ws);
    }
    if (k == 0) {
        if (func_02017E1C(*(void **)s, 0xad, 0) == 1) {
            v = func_02017E1C(*(void **)s, 0x6e, 0);
            if (v == 0) {
                func_021B9C1C(a, W(0x20), (u16)7, 0x69, 9, 0x14c0);
            } else if (v == 1) {
                func_021B9C1C(a, W(0x20), (u16)8, 0x69, 9, 0xc80);
            }
        }
    }
    if (f == 0) {
        if ((func_02017F90(*(void **)s) == 0 && *(u16 *)(s + 6) != 0) || W(0x1c) != 8) {
            ws2 = (u32)func_0201EC64(*(u16 *)a);
            func_0201EFA4((struct WordSet *)ws2, 0, func_02018430(*(void **)s), 3, 0, 1);
            if (k == 0) {
                func_021B9D58(a, W(0x20), (void *)ws2, 2, 9, 0x23, 0x440);
            } else {
                func_021B9DC0(a, W(0x20), (void *)ws2, 2, 9, 0x23, 0x440);
            }
            func_0201ED04((struct WordSet *)ws2);
            func_0204B3DC((struct Obj *)W(0x40), 0);
        } else {
            if (*(u16 *)(s + 6) == 0) {
                func_0204B878((struct Obj *)W(0x40), 6);
            } else {
                switch (func_02017F90(*(void **)s)) {
                case 1: func_0204B878((struct Obj *)W(0x40), 1); break;
                case 2: func_0204B878((struct Obj *)W(0x40), 3); break;
                case 3: func_0204B878((struct Obj *)W(0x40), 2); break;
                case 4: func_0204B878((struct Obj *)W(0x40), 5); break;
                case 5: func_0204B878((struct Obj *)W(0x40), 4); break;
                }
            }
            func_0204B3DC((struct Obj *)W(0x40), 1);
        }
    }
    m = W(0x1c);
    if (m != 8) {
        if (m == 6) {
            m = 0x81;
        } else if (m == 7) {
            m = 0x82;
        } else {
            m = m + 0x83;
        }
        func_021B9C1C(a, W(0x20), (u16)m, 0x2e, 0x1f, 0x440);
        func_0204B3DC((struct Obj *)W(0x38), 0);
    } else if (f == 1) {
        switch (func_021B9AC8(a, *(void **)s, s[4])) {
        case 0:
        case 1: code = 0x89; break;
        case 2: code = 0x8a; break;
        case 3: code = 0x8b; break;
        }
        func_021B9C1C(a, W(0x20), (u16)code, 0x1d, 0x1f, 0x440);
        func_0204B3DC((struct Obj *)W(0x38), 0);
    } else {
        obj = *(u8 **)(a + 0x280);
        if (*(int *)(obj + 0x34) == 0x10) {
            v = func_021B9BF4(a, *(void **)s, *(u16 *)(obj + 0x44));
            m = 0x8d;
            if (v != 0) {
                m = 0x8c;
            }
            func_021B9C1C(a, W(0x20), (u16)m, 0x2e, 0x1f, 0x440);
            func_0204B3DC((struct Obj *)W(0x38), 0);
        } else {
            ws2 = (u32)func_0201EC64(*(u16 *)a);
            func_0201EFA4((struct WordSet *)ws2, 0, func_02017E1C(*(void **)s, 0xa1, 0), 3, 0, 1);
            if (k == 0) {
                func_021B9D58(a, W(0x20), (void *)ws2, 4, 0x5b, 0x23, 0x440);
            } else {
                func_021B9DC0(a, W(0x20), (void *)ws2, 4, 0x5b, 0x23, 0x440);
            }
            func_0201ED04((struct WordSet *)ws2);
            ws3 = (u32)func_0201EC64(*(u16 *)a);
            func_0201EFA4((struct WordSet *)ws3, 0, *(u16 *)(s + 6), 3, 1, 1);
            if (k == 0) {
                func_021B9D58(a, W(0x20), (void *)ws3, 5, 0x39, 0x23, 0x440);
            } else {
                func_021B9DC0(a, W(0x20), (void *)ws3, 5, 0x39, 0x23, 0x440);
            }
            func_0201ED04((struct WordSet *)ws3);
            if (k == 0) {
                func_021B9C64(a, W(0x20), 6, 0x52, 0x23, 0x440);
            } else {
                func_021B9CB0(a, W(0x20), 6, 0x52, 0x23, 0x440);
            }
        }
    }
    r5 = func_02017E1C(*(void **)s, 6, 0);
    if (r5 != 0) {
        func_0204B3DC((struct Obj *)W(0x3c), 1);
        if (func_0202136C(r5) == 1) {
            func_0204B878((struct Obj *)W(0x3c), 1);
        } else {
            func_0204B878((struct Obj *)W(0x3c), 0);
        }
    } else {
        func_0204B3DC((struct Obj *)W(0x3c), 0);
    }
    r6 = func_021BB554((u32)s);
    r = 1;
    if (r6 == 3) {
        r = 0;
    } else if (func_02017F90(*(void **)s) != 0) {
        r = 5;
    } else if (r6 == 2) {
        r = 4;
    } else if (r6 == 1) {
        r = 3;
    } else if (r6 == 0) {
        r = 2;
    }
    func_0204B878((struct Obj *)W(0x30), r);
    W(0x18) = 1;
}

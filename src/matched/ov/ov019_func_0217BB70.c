/*
 * function: func_0217BB70
 * address:  0x0217BB70
 * packet:   pkt_ov019_0217BB70
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0217AEE8  0x0217AEE8  thumb  ov019
 *   func_0217AEFC  0x0217AEFC  thumb  ov019
 *   func_0217AF38  0x0217AF38  thumb  ov019
 *   func_0217AF4C  0x0217AF4C  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_0217F7E4  0x0217F7E4  thumb  ov019
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Entry {
    u8 pad0[0xB];
    u8 bB;
    u8 padC[0x8C - 0xC];
} Entry;

typedef struct Work {
    u8    pad0[0x2910];
    Entry entries[10];
} Work;

extern void *func_02188CB4(u8 *p);
extern void *func_02188C7C(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void  func_02172D20(u8 *w);
extern int   func_02172D68(u8 *w);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern u16   func_0216D588(void *p);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern int   func_0203D1B4(void);
extern u32   func_020362DC(void);
extern int   func_0217AEE8(u16 t);
extern u16   func_0217AEFC(u32 t);
extern int   func_0217AF38(u16 t);
extern int   func_0217AF4C(u8 *w, u16 t);
extern void  func_0217B8E4(u8 *w, int v);
extern void  func_0217BAF0(u8 *w, void *q, int v);
extern int   func_0217BB04(u8 *w);
extern int func_0217F7E4(u32 arg);

int func_0217BB70(u8 *w, u8 *obj, void *q)
{
    void *a;
    void *b;
    void *r;
    u16 t;
    u16 n;
    s16 x;
    s16 y;
    s16 z;

    a = func_02188CB4(q);
    b = func_02188C7C(q);
    if (func_0217BB04(w) == 1) {
        return 1;
    }
    if (func_02172D68(w) == 1) {
        return 0;
    }
    if (obj[0x71] != 0) {
        return 1;
    }
    if (func_0203D1B4() > 1) {
        func_02172D20(w);
        return 0;
    }
    if (func_020362DC() & 1) {
        func_021A3460((u32)a, (u32)(&x), (u32)(&y), (u32)(&z));
        r = func_0216DDC0((u32)b, x, z, 0);
        if (r == 0) {
            return 0;
        }
        t = func_0216D588(r);
        if (func_0217AF38(t) == 0 || func_0217AF4C(w, t) == 0) {
            return 0;
        }
        *(u16 *)(obj + 0x58) = t;
        n = func_0217AEFC(t);
        func_021734A8(w, 0, (u32)(&((Work *)w)->entries[n]));
        if (func_0217AEE8(t) == 0) {
            if (((Work *)w)->entries[n].bB == 0) {
                func_021734A8(w, 1, (u32)(&((Work *)w)->entries[n]));
                func_0217B8E4(w, 5);
            } else {
                func_0217B8E4(w, 0xB);
            }
        } else {
            func_0217B8E4(w, 0xC);
        }
        func_0217BAF0(w, q, 1);
        return 1;
    }
    if (w[0x282E] == 1) {
        func_0217B8E4(w, 4);
        return 1;
    }
    if (func_0217F7E4((u32)q) == 1) {
        if (*(int *)(w + 0x3564) == 1) {
            func_0217BAF0(w, q, 1);
            func_0217B8E4(w, 3);
        }
    } else {
        *(int *)(w + 0x3564) = 1;
    }
    return 0;
}

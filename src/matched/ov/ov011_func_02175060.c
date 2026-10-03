/*
 * function: func_02175060
 * address:  0x02175060
 * packet:   pkt_ov011_02175060
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_02013E90  0x02013E90  thumb
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_02026478  0x02026478  thumb
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_02175598  0x02175598  thumb  ov011
 *   func_02167810  0x02167810  thumb  ov010
 *   func_02167658  0x02167658  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u32 f0;
    u8 pad4[0xe];
    u8 f12;
    u8 pad13;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

extern u16 func_02039338(void);
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern u32 func_02013E90(u32 a, u32 b);
extern int func_021677E4(int, int);
extern int func_02026478(int);
extern int func_021583EC(int, int);
extern int func_02175598(Entry *, int);
extern int func_02167810(int, int);
extern void func_02167658(int, int);
extern void func_021675D0(int, int, int, Entry *);

static inline int func_02175060_check(Entry *e, Entry *me)
{
    if (e->hi == 1) {
        return 1;
    }
    if (e->f12 != 0 && e->f12 != 1) {
        return 1;
    }
    if (func_02013D5C(e->f14) == 1 && func_02013D5C(me->f14) == 1) {
        return 0;
    }
    if (e->a == me->a) {
        if (func_02013D9C(e->f14) == 1 && func_02013D9C(me->f14) == 1) {
            if (e->b == me->b) {
                return 0;
            }
            return 1;
        }
        if (func_02013E90(me->f14, e->f14) == 1) {
            return 0;
        }
        return 1;
    }
    return 1;
}

void func_02175060(u8 *p, int idx)
{
    Entry *e;
    int r;

    e = (Entry *)(p + 0x8c) + idx;
    if (idx != func_02039338()) {
        Entry *me = (Entry *)(p + 0x70);
        e->f0 = func_02175060_check(e, me);
    }
    if (func_021677E4(*(int *)(p + 8), idx) == 1) {
        r = func_02175598(e, func_021583EC(func_02026478(*(int *)(p + 4)), idx));
        if (r != func_02167810(*(int *)(p + 8), idx)) {
            func_02167658(*(int *)(p + 8), idx);
            if (e->f18 != 0) {
                func_021675D0(*(int *)(p + 8), idx, r, e);
            }
        }
    }
}

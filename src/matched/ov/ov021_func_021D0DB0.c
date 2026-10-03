/*
 * function: func_021D0DB0
 * address:  0x021D0DB0
 * packet:   pkt_ov021_021D0DB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The listing extent (568 B) runs over the unlabelled 8-byte follower leaf
 * at 0x021D0FE0 (return *(u32 *)(r1 + 0x150)); the function is 560 B.
 * s is u32 with (int) casts on the clamp (signed clamp, unsigned rank
 * ladder); that and the h, s, rec, rank declaration order give the
 * stack slots.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008E88  0x02008E88  thumb
 *   func_02008E68  0x02008E68  thumb
 *   d_021DE674     0x021DE674  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 species;
    u8 b2;
    u8 b3;
} Mon;

typedef struct {
    u8 valid;
    u8 kind;
    u16 score;
    Mon mons[4];
} Rec;

extern int d_021DE674;

extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u8 *func_0200E8F8(u32 h);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void *func_02030734(u32 heap, u32 size, u32 flag, void *file, u32 line);
extern int func_020072CC(u32 sv, u32 id, u32 heap, void *buf, u32 size);
extern u8 *func_020073D8(u32 sv, u32 id, u32 v);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_020307B0(void *p);
extern void func_0200734C(u32 sv, u32 id);
extern void *func_02008C58(u32 h);
struct Sub02008C20Obj;
extern void func_02008E88(struct Sub02008C20Obj *obj, u32 value);
extern void func_02008E68(void *x, u8 v);

#define U32(o) (*(u32 *)(w + (o)))

void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore)
{
    u16 *st;
    u32 h;
    u32 s;
    u8 *rec;
    u32 rank;
    Rec *e;
    int i;
    Mon *m;
    void *mon;
    u32 h2;
    void *buf;
    void *x;

    st = (u16 *)(w + 0x134);
    s = 0;
    s += st[7] * 1000;
    s += st[8] * 80;
    s += st[1] * 5;
    s += st[3];
    s += st[5] * 5;
    s += st[6] * 2;
    s += st[11] * 15;
    s -= st[0] * 10;
    s -= st[2] * 10;
    s -= st[4] * 2;
    s -= st[9] * 80;
    s -= 500 - st[10];
    if ((int)s < 0) {
        s = 0;
    } else if ((int)s > 9999) {
        s = 9999;
    }

    if (s >= 6000) {
        rank = 6;
    } else if (s >= 5000) {
        rank = 5;
    } else if (s >= 4000) {
        rank = 4;
    } else if (s >= 3000) {
        rank = 3;
    } else if (s >= 2000) {
        rank = 2;
    } else if (s >= 1000) {
        rank = 1;
    } else {
        rank = 0;
    }
    *outRank = rank;
    *outScore = s;

    h = func_02012EBC(func_020120F4(a));
    rec = func_0200E8F8(h);
    e = (Rec *)(rec + (u8)(U32(0x150) != 0) * 20);
    e->valid = 1;
    if (U32(0x124) == 3) {
        e->kind = 0;
    } else if (U32(0x124) == 4) {
        e->kind = 1;
    } else {
        e->kind = 0;
    }
    e->score = s;
    func_02082BCC(e->mons, 0, 0x10);
    for (i = 0; i < (int)U32(0x124); i++) {
        m = &e->mons[i];
        mon = func_0201AB28((void *)U32(0x128), i);
        m->species = func_02017E1C(mon, 5, 0);
        m->b2 = func_02017E1C(mon, 0x6f, 0);
        m->b3 = func_02017E1C(mon, 0x6e, 0);
    }

    if (U32(0x150) != 0) {
        h2 = func_02012EBC(func_020120F4(a));
        buf = func_02030734(0x8004, 0x8004 >> 3, 1, &d_021DE674, 0x277);
        if (func_020072CC(h2, 5, 0x8004, buf, 0x8004 >> 3) == 1) {
            func_02082D44(func_020073D8(h2, 5, 0) + 0x5a0, rec += 0x38, 0x22);
        }
        func_020307B0(buf);
        func_0200734C(h2, 5);
    }

    x = func_02008C58(h);
    func_02008E88(x, s);
    func_02008E68(x, rank);
}

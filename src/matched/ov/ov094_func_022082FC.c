/*
 * function: func_022082FC
 * address: 0x022082FC
 * packet: pkt_ov094_022082FC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0220841E..02208420 is two bytes of zero alignment padding.
 * lever: u8 count retains the result spill; enum VRAM base preserves add
 *   order and register home; zero the loop counter before assigning base.
 * symbols:
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_02208034 0x02208034 thumb ov094
 *   func_0202D034 0x0202D034 thumb
 *   func_02082A60 0x02082A60 arm
 *   func_0220868C 0x0220868C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int w[9]; } Struct36;
typedef struct E {
    void *f0, *f4, *f8, *fc, *f10;
    char p14[0x34];
    int f48, f4c;
    u32 f50;
    int f54, f58, f5c, f60;
    u32 f64;
    int f68;
    u8 f6c;
    char p6d[0x13];
} E;
typedef struct O {
    char p0[0x14];
    char *f14;
    char p18[0x28];
    E e[8];
    u32 lo:4, b4:1, hi:27;
} O;
extern void func_0204B7C8(void *, Struct36 *);
extern u8 func_02208034(u32, int, int, u32 *, u8 *, u8);
extern int func_0202D034(u32, u32);
extern void func_02082A60(const void *, void *, int);
extern void func_0220868C(O *, E *, int);
void func_022082FC(O *o, int idx, int k)
{
    E *e;
    u8 a[10];
    Struct36 buf;
    int color, val;
    u8 n, i;
    enum { VRAM = 0x06400000 } base;
    e = &o->e[idx];
    switch (k) {
    case 0:
        if (o->b4 && !(idx & 1)) break;
        func_0204B7C8(e->f8, &buf);
        n = func_02208034(e->f4c, e->f48, e->f68, &e->f50, a, 6);
        val = e->f50;
        if (e->f4c < 48) val >>= 8;
        switch (func_0202D034(val, e->f4c)) {
        case 0: color = 0; break;
        case 1: color = 0x120; break;
        case 2:
        default: color = 0x240; break;
        }
        for (i = 0; i < 6; i++) {
            base = VRAM;
            func_02082A60(o->f14 + (color + a[i] * 32), (void *)(buf.w[1] + (base + (i + 1) * 32)), 32);
        }
        if (e->f68 > 0) func_0220868C(o, e, n);
        break;
    case 1:
        if (e->f10 == 0) break;
        func_0204B7C8(e->f10, &buf);
        func_02208034(e->f58, e->f54, e->f60, &e->f64, a, 10);
        if (e->f6c == 100) {
            for (i = 0; i < 10; i++) a[i] = 0;
        }
        i = 0;
        base = VRAM;
        for (; i < 10; i++) {
            func_02082A60(o->f14 + (a[i] * 32 + 0x400), (void *)(buf.w[1] + (base + (i + 1) * 32)), 32);
        }
        break;
    }
}

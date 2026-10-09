/*
 * file:     btl_server_p60.c
 * unit:     yes
 * function: func_021C4744, func_021C4838
 * address:  0x021C4744
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8630 0x021B8630 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C334C 0x021C334C thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_0202E7E0 0x0202E7E0 thumb
 *   func_0202E7E4 0x0202E7E4 thumb
 *   func_021C48E0  0x021C48E0  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C4910  0x021C4910  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 *   func_021C48F0  0x021C48F0  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021C4900  0x021C4900  thumb  ov093
 *   func_021C5200  0x021C5200  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_021B8630(u32 **p);
extern u32 func_0202E7E0(void *);
extern u8 func_021B8FF4(u8 *);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern int func_021D5B68(void *p);
extern int func_021D5B48(u8 *);
extern u8 func_021D5440(u8 *);
extern u32 func_0203F0A8(void);
extern u8 *func_021B9934(char *, int);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C334C(u8 *p, u8 *q, int a, int b);
extern void func_021CD64C(void *w, u8 id, ...);
extern void func_0202E7E4(void *);
extern void func_021C48E0(u8 *a);
extern u32 func_021CC8D8(void *, int);
extern void func_021C4910(u8 *p, u32 a, int k);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021BC2B0(u8 *p);
extern u8 *func_021C48F0(u8 *a);
extern int func_021C4F64(u8 *p, u8 *a);
extern u8 *func_021C4900(u8 *a);
extern int func_021C5200(u8 *p);
void func_021C4744(u8 *p);
int func_021C4838(u8 *p, u8 *a, u8 *b);

/*
 * Verified with one --thumb without region, dsi/1.1p1 -O4,p:
 * typedef unsigned int u32;
 * typedef struct { u32 a[8]; } Block;
 * typedef struct { u32 mode, old, other; Block current, previous; } State;
 * 0x0202E7E0 EXACT: u32 func_0202E7E0(State *p) { return p->mode; }
 * 0x0202E7E4 EXACT: void func_0202E7E4(State *p) {
 *     p->old = p->mode; p->previous = p->current; p->mode = 3;
 * }
 * lever: a u64 draw and a separate u32 slot preserve the high-product register.
 * note 2026-10-05 (D8 lane16): witnesses func_0202E7E0 and func_0202E7E4 filed as src/matched/arm9/func_0202E7E0.c and func_0202E7E4.c (both EXACT); this file becomes EXACT once the integrator seeds them.
 */
void func_021C4744(u8 *p)
{
    u8 list[4];
    u8 i, n;
    void *work;
    u32 mode, side;
    u8 *desc, *m;
    u32 value, slot;
    u64 draw;
    u8 id;
    int live;
    work = (void *)func_021B8630(*(void **)(p + 4));
    if (work == 0) return;
    mode = func_0202E7E0(work);
    if (mode == 0 || mode == 3) return;
    side = func_021B8FF4(*(u8 **)(p + 4));
    desc = func_021BB85C(*(void **)p, (int)side);
    i = 0;
    n = 0;
    for (; i < desc[9]; i++) {
        m = func_021B990C(*(void **)(p + 8), side, (u8)i);
        if (m != 0) {
            if (func_021D5B68(m) == 0) live = 1;
            else live = 0;
        } else live = 0;
        if (live) {
            if (func_021D5B48(m) == 0) list[n++] = func_021D5440(m);
        }
    }
    if (n == 0) return;
    draw = func_0203F0A8();
    slot = (u32)draw;
    if (n != 0) slot = (u32)((draw * (u32)n) >> 32);
    id = list[slot];
    m = func_021B9934(*(char **)(p + 8), id);
    value = (u32)func_021D59B4(m, 14);
    if (mode == 1) value >>= 1;
    if (value == 0) return;
    if (func_021C334C(p, m, (u16)value, (u32)0)) {
        func_021CD64C(*(void **)(p + 12), (u32)0x5a, 0x53, 4, id, 0xffff0000);
        func_0202E7E4(work);
    }
}


int func_021C4838(u8 *p, u8 *a, u8 *b)
{
    u32 s;
    u8 *q;
    func_021C48E0(a);
    s = func_021CC8D8(p + 0x1D74, 9644);
    func_021C4910(p, 0x1f, (int)b);
    func_021CC95C((u32 *)(p + 0x1D74), s, 9646);
    if (func_021BC2B0(p) == 0) {
        q = func_021C48F0(a);
        if (q != 0) {
            do {
                s = func_021CC8D8(p + 0x1D74, 9652);
                func_021C4910(p, func_021D5440(q), (int)b);
                func_021CC95C((u32 *)(p + 0x1D74), s, 9654);
                func_021C4F64(p, q);
                if (func_021BC2B0(p) != 0) {
                    break;
                }
                q = func_021C4900(a);
            } while (q != 0);
        }
    }
    return func_021C5200(p);
}

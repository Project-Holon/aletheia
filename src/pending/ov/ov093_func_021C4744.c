/*
 * function: func_021C4744
 * address: 0x021C4744
 * packet: pkt_ov093_021C4744
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x0202E7E0 and 0x0202E7E4 have no outside witness.
 * Verified with one --thumb without region, dsi/1.1p1 -O4,p:
 * typedef unsigned int u32;
 * typedef struct { u32 a[8]; } Block;
 * typedef struct { u32 mode, old, other; Block current, previous; } State;
 * 0x0202E7E0 EXACT: u32 func_0202E7E0(State *p) { return p->mode; }
 * 0x0202E7E4 EXACT: void func_0202E7E4(State *p) {
 *     p->old = p->mode; p->previous = p->current; p->mode = 3;
 * }
 * lever: a u64 draw and a separate u32 slot preserve the high-product register.
 * symbols:
 *  func_021B8630 0x021B8630 thumb ov093
 *  func_021B8FF4 0x021B8FF4 thumb ov093
 *  func_021BB85C 0x021BB85C thumb ov093
 *  func_021B990C 0x021B990C thumb ov093
 *  func_021D5B68 0x021D5B68 thumb ov093
 *  func_021D5B48 0x021D5B48 thumb ov093
 *  func_021D5440 0x021D5440 thumb ov093
 *  func_0203F0A8 0x0203F0A8 arm
 *  _ull_mul 0x0209C054 arm
 *  func_021B9934 0x021B9934 thumb ov093
 *  func_021D59B4 0x021D59B4 thumb ov093
 *  func_021C334C 0x021C334C thumb ov093
 *  func_021CD64C 0x021CD64C thumb ov093
 *  func_0202E7E0 0x0202E7E0 thumb
 *  func_0202E7E4 0x0202E7E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void *func_021B8630(void *);
extern u32 func_0202E7E0(void *);
extern u8 func_021B8FF4(u8 *);
extern u8 *func_021BB85C(void *, int);
extern u8 *func_021B990C(void *, u32, u8);
extern int func_021D5B68(u8 *);
extern int func_021D5B48(u8 *);
extern u8 func_021D5440(u8 *);
extern u32 func_0203F0A8(void);
extern u8 *func_021B9934(char *, int);
extern u32 func_021D59B4(void *, int);
extern int func_021C334C(u8 *, u8 *, u16, u32);
extern void func_021CD64C(void *, u32, ...);
extern void func_0202E7E4(void *);
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
    work = func_021B8630(*(void **)(p + 4));
    if (work == 0) return;
    mode = func_0202E7E0(work);
    if (mode == 0 || mode == 3) return;
    side = func_021B8FF4(*(u8 **)(p + 4));
    desc = func_021BB85C(*(void **)p, side);
    i = 0;
    n = 0;
    for (; i < desc[9]; i++) {
        m = func_021B990C(*(void **)(p + 8), side, i);
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
    value = func_021D59B4(m, 14);
    if (mode == 1) value >>= 1;
    if (value == 0) return;
    if (func_021C334C(p, m, value, 0)) {
        func_021CD64C(*(void **)(p + 12), 0x5a, 0x53, 4, id, 0xffff0000);
        func_0202E7E4(work);
    }
}

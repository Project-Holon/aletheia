/*
 * function: func_0218A220
 * address: 0x0218A220
 * packet: pkt_ov096_0218A220
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: existing ov094_func_021F8AE8.c unit omits func_021F8AFC from
 * its parsed function list: four repeated keys leave only func_021F8B28.
 * Concrete bytes correct; caller-only tu suggest-split has no viable cut.
 * lever: advance p itself before indexed store; random draw helper owns
 * its u64 temporary and returns u32 (random-below-n existing idiom).
 * symbols:
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021F8AFC 0x021F8AFC thumb ov094
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02019C90 0x02019C90 thumb
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern int func_0218A2FC(u8 *, int);
extern int func_021D62C4(void *, int);
extern int func_021F8AFC(int);
extern int func_021D59B4(void *, int);
extern int func_021D5444(void *);
extern u32 func_02019C90(u16, u16, u32);
extern u32 func_0203F0A8(void);
static inline u32 draw_below(u32 n)
{
    u64 draw = func_0203F0A8();
    if (n != 0) draw = (draw * n) >> 32;
    return draw;
}
int func_0218A220(u8 *p, int k, int slot)
{
    void *mon;
    int a, b;
    u32 x, y, z, n;
    u32 values[3];
    mon = (void *)func_0218A2FC(p, slot);
    if (func_021D62C4(mon, 0x10) != 0)
        return 0;
    if (k == 0 || k == 2) {
        p += 0x7c;
        p[slot] = func_021F8AFC(slot);
        if (p[slot] != 0)
            return p[slot];
        a = func_021D59B4(mon, 0x10);
        if (a == 0x17 || a == 0x2a || a == 0x47)
            return a;
        a = func_021D5444(mon);
        b = func_021D59B4(mon, 0x13);
        n = 0;
        x = func_02019C90(a, b, 0x1a);
        y = func_02019C90(a, b, 0x1b);
        z = func_02019C90(a, b, 0x1c);
        if (x != 0) values[n++] = x;
        if (y != 0) values[n++] = y;
        if (z != 0) values[n++] = z;
        return values[draw_below(n)];
    }
    return func_021D59B4(mon, 0x10);
}

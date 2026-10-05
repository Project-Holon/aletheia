/*
 * function: func_021BD1A4
 * address:  0x021BD1A4
 * packet:   pkt_ov099_021BD1A4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (wave D2 lane 04): first draft. Structure and all 20 relocations
 * match; 20 bytes differ, all one colour swap: the original keeps the 0x1b8 base temp
 * (and later the switch value) in r6 and the index `five` (0, or 1 after func_0203D378()==0)
 * in r5; this draft has them the other way round (r5 and r6). Stack slots now match (out
 * declared before x[2]). Tried: five declared first or last, u32 five, five = 0 before the
 * q load, u32 r (breaks the negative cases, 213 bytes).
 *
 * 2026-10-05 (wave D4 lane 04): DIFF, 20 bytes, unchanged. Tried: 0x1b8 held in a local (0x1b0/0x1ac
 * written as off - 8 / off - 0xc), the same local reused as the switch value r, u8 five: all give the
 * same r5/r6 swap.
 * 2026-10-05 (wave D5 lane 08): DIFF, 18 bytes. Fixed the jump table: case -1 is written before case -2
 *   (the original lays the -1 return first). Residue is only the r5/r6 colour swap (five vs the
 *   0x1b8/0x248 offset temps and r). Tried: the 0x1b0 store written as = five (no change).
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_020202FC 0x020202FC thumb
 *   func_02012934 0x02012934 thumb
 *   func_021BBA4C 0x021BBA4C thumb ov099
 *   func_021BBDD0 0x021BBDD0 thumb ov099
 *   func_0203D378 0x0203D378 arm
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;

extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern int func_020200CC(void *o);
extern void func_020202FC(void *o, u16 *a, u16 *b);
extern void *func_02012934(void *x);
extern void func_021BBA4C(char *p, void *x);
extern void func_021BBDD0(char *p, int f);
extern int func_0203D378(void);
extern int func_021BCB70(void *a, void *b, void *c);
extern int func_021BCBBC(void *a, void *b, void *c);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC0C4(char *p);
extern void func_0201AC2C(void *a, void *b);
extern void func_021BA8EC(char *p);

int func_021BD1A4(char *p, int v)
{
    int five;
    void *q;
    int r;
    int out;
    u16 x[2];
    void *a;

    five = 0;
    q = *(void **)(p + 0x1b8);
    if (*(u8 *)(p + 0x1b0) != 0) {
        if (func_0201C6C4(q, func_02045770(*(struct Descriptor **)(p + 0x1ac))) == 0) {
            func_02045334(*(struct Descriptor **)(p + 0x1ac));
            *(u8 *)(p + 0x1b0) = 0;
        }
    }
    r = func_020200CC(*(void **)(p + 0xbc));
    func_020202FC(*(void **)(p + 0xbc), &x[1], &x[0]);
    if (x[0] != *(u8 *)(p + 0x1354)) {
        *(u8 *)(p + 0x1354) = x[0];
        if (x[0] == 0) {
            func_021BBA4C(p, func_02012934(*(void **)(p + 0xc4)));
            func_021BBDD0(p, 1);
        } else {
            func_021BBA4C(p, *(void **)(p + 0xcc));
            func_021BBDD0(p, 0);
        }
    }
    if (func_0203D378() == 0) {
        five = 1;
    }
    switch (r) {
    case -1:
        return v;
    case -2:
        return v;
    case 0:
        if (func_021BCB70(*(void **)(p + 0x1348), *(void **)(p + 0xc4), &out) != 0) {
            func_021BAAB8(p, 0x68, 0);
            *(u32 *)(p + 0x1cc) = 0x6b;
            func_021BC0C4(p);
            return v;
        }
        a = func_02012934(*(void **)(p + 0xc4));
        goto tail;
    case 1:
        if (func_021BCBBC(*(void **)(p + 0x1348), *(void **)(p + 0xcc), &out) != 0) {
            func_021BAAB8(p, 0x68, 0);
            *(u32 *)(p + 0x1cc) = 0x6c;
            func_021BC0C4(p);
            return v;
        }
        a = *(void **)(p + 0xcc);
    tail:
        func_0201AC2C(a, *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32 *)(p + 0x1cc) = 0x67;
        break;
    }
    func_021BC0C4(p);
    func_021BA8EC(p);
    return v;
}

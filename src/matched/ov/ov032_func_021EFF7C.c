/*
 * function: func_021EFF7C
 * address:  0x021EFF7C
 * packet:   pkt_ov032_021EFF7C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_021F0A18  0x021F0A18  thumb  ov032
 *   func_021F253C  0x021F253C  thumb  ov032
 *   func_021F08E4  0x021F08E4  thumb  ov032
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_02165C10  0x02165C10  thumb  ov010
 *   func_021F1F00  0x021F1F00  thumb  ov032
 *   func_021F096C  0x021F096C  thumb  ov032
 *   func_021F1340  0x021F1340  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 x, y; } Pair;

extern void func_021F253C(u8 *p, int v);
extern int func_02035D20(u32 *a, u32 *b);
extern int func_021F0A18(u8 *p, Pair *v);
extern int func_021F08E4(u8 *p, Pair *v);
extern void func_02165AC4(int, int, void *, int);
extern int func_02165C10(int);
extern void func_021F1F00(u8 *p, u8 i);
extern int func_021F096C(u8 *p, Pair *v);
extern void func_021F1340(u8 *p, int a, int b);

int func_021EFF7C(u8 *p)
{
    Pair v;
    int r;
    int s;

    if (func_02035D20(&v.x, &v.y) == 0)
        return 0;
    r = func_021F0A18(p, &v);
    if (r != -1) {
        switch (r) {
        case 0:
            return 4;
        case 1:
            func_021F253C(p, 8);
            break;
        case 2:
            return 5;
        case 3:
            func_021F253C(p, 1);
            break;
        }
        return 0;
    }
    r = func_021F08E4(p, &v);
    if (r != -1) {
        func_02165AC4(*(int *)(p + 0x3C), *(int *)(p + 0x40), p + 0x48, p[0x7C] + r);
        if (func_02165C10(*(int *)(p + 0x40)) != 0)
            return 0;
        p[0x7E] = r;
        func_021F1F00(p, r);
        func_021F253C(p, 4);
        return 0;
    }
    s = func_021F096C(p, &v);
    if (s != -1) {
        func_021F1340(p, s, 0);
        return 3;
    }
    return 0;
}

/*
 * file:     btl_server_p51.c
 * unit:     yes
 * function: func_021C1CCC, func_021C1CE4
 * address:  0x021C1CCC
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
 *   func_021C7664 0x021C7664 thumb ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 *   func_021C1D30  0x021C1D30  thumb  ov093
 *   func_021C1D40  0x021C1D40  thumb  ov093
 *   func_021C1D50  0x021C1D50  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021C557C  0x021C557C  thumb  ov093
 */
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021C7664(u8 *, u32, u8 *);
extern int func_021C1D60(u8 *, u8 *, u32);
extern void func_021C1D30(u8 *w);
extern u8 *func_021C1D40(u8 *w);
extern u8 *func_021C1D50(u8 *w);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 func_021D6D7C(u8 *p);
extern void func_021C557C(u8 *p, u8 *a, int k, int flag);
int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q);
void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w);

int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = func_021C7664(p, *x, a);
    return func_021C1D60(p, q, n);
}


void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w)
{
    u8 *t;
    if (q[6] == 9) {
        func_021C1D30(w);
        t = func_021C1D40(w);
        while (t) {
            int k = 3;
            if (func_021D62A8((struct Unk021D62A8 *)t) == 3 && func_021D6D7C(t) == 0) {
                func_021C557C(p, t, k, 1);
            }
            t = func_021C1D50(w);
        }
    }
}

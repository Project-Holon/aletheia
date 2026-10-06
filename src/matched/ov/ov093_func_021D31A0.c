/*
 * function: func_021D31A0
 * address:  0x021D31A0
 * packet:   pkt_ov093_021D31A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 172, compiled 170: trailing 2-byte padding)
 *
 * Levers: the 0x26..0x29 selection is a `static inline u16` helper returning nested
 * ternaries; inlined, its result stays in r0 and each arm branches (the inner join of the
 * u == 3 arm is the unthreaded `b` hop). Written in the caller (ternary, if/else, nested
 * ternary, call in each arm) it is if-converted into r1, and a plain `static` helper is
 * not inlined. `u` is `int` (permuter: u32 put c[1] first into r7 in case 0).
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021EAA6C  0x021EAA6C  thumb  ov093
 *   func_021EAAD8  0x021EAAD8  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *func_021B9AEC(char *p, int i);
extern void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2);
extern void func_021EAA6C(u32 a, int b, int c);
extern int func_021EAAD8(u32 a);
extern int func_021B9F70(u8 *p, int i);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);

static inline u16 sel(u32 u, u32 k)
{
    if (u == 3) {
        return (k != 0) ? 0x26 : 0x27;
    }
    return (k != 0) ? 0x28 : 0x29;
}

int func_021D31A0(u32 *a, int *b, u32 *c)
{
    u32 v;
    int u;
    u8 k;
    char *p;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        v = (u8)c[1];
        p = func_021B9AEC((char *)a[1], u);
        func_021B9C50((u8 **)p, v, 0, 0);
        func_021EAA6C(a[0x15], u, v);
        (*b)++;
        break;
    case 1:
        if (func_021EAAD8(a[0x15]) != 0) {
            u = (u8)c[1];
            if (u == 1) {
                return 1;
            }
            k = func_021B9F70((u8 *)a[0], (u8)c[0]);
            func_021EA678((char *)a[0x15], sel(u, k), (int *)c);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * file:     unit_021B6DC0_p03.c
 * unit:     yes
 * function: func_021B721C, func_021B72CC
 * address:  0x021B721C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0204A298  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021D99D0     0x021D99D0  data   ov021  a1
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 */
struct WordSet;
struct Blk34;
struct SaveBlock;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Ent { u32 k; u32 v; };

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_02158F74(void *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02159B10(void *a, void *b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_020307B0(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_020127A4(struct SaveBlock *p);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
int func_021B721C(u32 a, u32 b);
int func_021B72CC(u32 a, u32 b);
extern const u8 d_021D99D0[];


/*
 * Same func_0204A298 lookup as func_021B72CC; the table is const so its
 * byte load is scheduled ahead of the `str r0,[sp]` that passes &cnt.
 */
int func_021B721C(u32 a, u32 b)
{
    void *s;
    u32 v;
    u32 k;
    u32 idx;
    u32 p1;
    u32 p2;
    u32 t;
    struct Ent *arr;
    u32 cnt;
    u32 i;

    s = func_0215A5F4((void *)b);
    v = func_02188C84((u8 *)(((u32 *)func_02158F58((int)s))[1]));
    k = func_02159B10((void *)a, (void *)b);
    idx = func_02159B10((void *)a, (void *)b);
    p1 = func_02159B10((void *)a, (void *)b);
    p2 = func_02159B10((void *)a, (void *)b);
    t = (u32)func_02158F74(s);
    arr = (struct Ent *)func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            func_0201EFA4((struct WordSet *)t, p1, arr[i].v, p2, 0, 1);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}


/*
 * Same func_0204A298 lookup as func_021B70D8 / func_021B716C.  Here the
 * table byte d_021D99D0[idx] is loaded ahead of the `str r0,[sp]` that
 * passes &cnt: that needs the table declared const, otherwise the load
 * may alias the stack store and is scheduled after it.
 */
int func_021B72CC(u32 a, u32 b)
{
    void *h;
    u32 v;
    u32 k;
    u32 idx;
    struct Ent *arr;
    u32 cnt;
    u32 i;

    v = func_02188C84((u8 *)(((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]));
    k = func_02159B10((void *)a, (void *)b);
    idx = func_02159B10((void *)a, (void *)b);
    h = func_0215A5E4((void *)b);
    func_020127A4(h);
    arr = (struct Ent *)func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            func_0200C278(func_02012F08(h), arr[i].v);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}

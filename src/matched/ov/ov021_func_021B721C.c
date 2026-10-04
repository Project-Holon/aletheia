/*
 * function: func_021B721C
 * address:  0x021B721C
 * packet:   pkt_ov021_021B721C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same func_0204A298 lookup as func_021B72CC; the table is const so its
 * byte load is scheduled ahead of the `str r0,[sp]` that passes &cnt.
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
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent { u32 k; u32 v; };

extern void *func_0215A5F4(void *p);
struct WordSet;
extern int func_02158F58(int a0);
extern void *func_02158F74(void *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02159B10(void *a, void *b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void func_020307B0(void *p);
extern const u8 d_021D99D0[];

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

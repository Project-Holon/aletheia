/*
 * file:     scrcmd_c03center_p02.c
 * unit:     yes
 * function: func_021B5C80, func_021B5CE8
 * address:  0x021B5C80
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C2D0  0x0200C2D0  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 */
struct Blk34;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02012F08(int *p);
extern void func_0200C2D0(struct Blk34 *p, u32 i, u16 *dest);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
int func_021B5C80(void *a, void *b);
int func_021B5CE8(void *a, void *b);


/*
 * Addresses are Black-image addresses.
 */
int func_021B5C80(void *a, void *b)
{
    void *t;
    struct WordSet *w;
    unsigned int k;
    u16 *out;
    int i;
    int n;
    u16 arr[6];

    t = func_0215A5E4(b);
    w = func_02158F74(func_0215A5F4(b));
    k = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    func_0200C2D0(func_02012F08(t), k, arr);
    for (i = 0, n = 0; i < 6; i++) {
        if (arr[i] != 0) {
            func_0201EE60(w, n, arr[i]);
            n++;
        }
    }
    *out = n;
    return 0;
}


int func_021B5CE8(void *a, void *b)
{
    u16 v[6];
    void *mon;
    u32 slot;
    u32 which;
    u16 *out;
    u16 sum;
    u16 max;
    u32 i;

    slot = func_02159B10(a, b);
    which = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    if (func_0215B4AC(b, slot, &mon) == 0) {
        *out = 0;
        return 0;
    }
    sum = 0;
    v[0] = func_02017E1C(mon, 0x46, 0);
    v[1] = func_02017E1C(mon, 0x47, 0);
    v[2] = func_02017E1C(mon, 0x48, 0);
    v[3] = func_02017E1C(mon, 0x49, 0);
    v[4] = func_02017E1C(mon, 0x4a, 0);
    v[5] = func_02017E1C(mon, 0x4b, 0);
    max = 0;
    for (i = 0; i < 6; i++) {
        sum += v[i];
        if (max < v[i]) {
            max = v[i];
        }
    }
    switch (which) {
    case 0:
        *out = sum;
        break;
    case 1:
        *out = max;
        break;
    case 2:
        *out = v[0];
        break;
    case 3:
        *out = v[1];
        break;
    case 4:
        *out = v[2];
        break;
    case 5:
        *out = v[3];
        break;
    case 6:
        *out = v[4];
        break;
    case 7:
        *out = v[5];
        break;
    }
    return 0;
}

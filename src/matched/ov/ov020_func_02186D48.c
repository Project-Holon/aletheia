/*
 * function: func_02186D48
 * address:  0x02186D48
 * packet:   pkt_ov020_02186D48
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127C4  0x020127C4  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020127F0  0x020127F0  thumb
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02186090  0x02186090  thumb  ov020
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_02193904  0x02193904  thumb  ov021
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_02193C04  0x02193C04  thumb  ov021
 *   func_021867B4  0x021867B4  thumb  ov020
 *   func_021867A8  0x021867A8  thumb  ov020
 *   func_021869AC  0x021869AC  thumb  ov020
 *   func_021869B8  0x021869B8  thumb  ov020
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_021869D8  0x021869D8  thumb  ov020
 *   func_021869D0  0x021869D0  thumb  ov020
 *   func_02193BE4  0x02193BE4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct {
    int f0;
    int f4;
} Ent;

extern int func_0215A5F4(int a);
extern int func_0215A5E4(int a);
extern int func_020127C4(int a);
extern int func_02159B10(int a0, int a1);
extern u16 *func_02159AE8(int a0, int a1);
extern int func_02186278(int p, int which);
extern Ent *func_02158F58(int a);
extern int func_02188C98(int a);
extern int func_0218DC70(int a);
extern int func_02188CB4(int a);
extern int func_02188C7C(int a);
extern int func_020127F0(int a);
extern void func_021A3460(int o, s16 *x, s16 *y, s16 *z);
extern int func_0216DDC0(int a, int x, int y, int z);
extern int func_02186090(void);
extern int func_0216D588(int a);
extern void func_02193904(int a);
extern int func_0219390C(int a, int b);
extern int *func_02193C00(int a);
extern int func_02193C04(int a);
extern int func_021867B4(int a);
extern int func_021867A8(int a);
extern int func_021869AC(int a);
extern int func_021869B8(int a);
extern int func_021938F4(int a);
extern int func_021869D8(int a);
extern int func_021869D0(int a);
extern int func_02193BE4(int a, int b);

int func_02186D48(int a0, int a1)
{
    int cur;
    int st;
    int id;
    int *rec;
    int sub;
    int b;
    int obj;
    int c;
    int d;
    int w;
    int kind;
    u16 *out;
    Ent *ent;
    int m;
    int s;
    s16 v[3];

    m = func_0215A5F4(a1);
    b = func_0215A5E4(a1);
    c = func_020127C4(b);
    kind = func_02159B10(a0, a1);
    out = func_02159AE8(a0, a1);
    if (kind == 3) {
        *out = func_02186278(c, 0);
    } else {
    ent = func_02158F58(m);
    m = func_0218DC70(func_02188C98(ent->f4));
    d = func_02188CB4(ent->f4);
    w = func_02188C7C(ent->f4);
    s = func_020127F0(b);
    func_021A3460(d, &v[2], &v[1], &v[0]);
    obj = func_0216DDC0(w, v[2], v[0], 0);
    if (obj != 0) {
        cur = func_02186090();
        st = func_0216D588(obj);
        func_02193904(m);
        sub = func_0219390C(m, cur);
        if (sub != 0) {
            rec = func_02193C00(sub);
            id = func_02193C04(sub);
        }
    }
    switch (kind) {
    case 0:
        *out = rec[6];
        break;
    case 1:
        *out = func_021867B4(id);
        break;
    case 2:
        *out = func_021867A8(id);
        break;
    case 3:
        break;
    case 4:
        *out = func_021869AC(s);
        break;
    case 5:
        *out = func_021869B8(s);
        break;
    case 6:
        if (func_021938F4(m) == 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 7:
        *out = func_021869D8(s);
        break;
    case 8:
        *out = func_021869D0(s);
        break;
    case 9:
        *out = cur;
        break;
    case 10:
        *out = func_02193BE4(m, cur);
        break;
    case 11:
        *out = st;
        break;
    }
    }
    return 0;
}

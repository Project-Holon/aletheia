/*
 * function: func_0216AD70
 * address:  0x0216AD70
 * packet:   pkt_ov010_0216AD70
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_0216662C  0x0216662C  thumb  ov010
 *   func_0216AEE8  0x0216AEE8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

typedef struct {
    u32 lo : 11;
    u32 pad : 12;
    u32 f : 6;
    u32 rest : 3;
} Bits;

extern int func_02159B10();
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern int func_02012138();
extern int func_021767A0();
extern int func_02012FB0();
extern int func_02166618();
extern int func_0216662C();
extern void func_0216AEE8();

int func_0216AD70(int a0, int a1)
{
    int kind;
    u16 *out;
    void *x;
    void *y;
    int t;
    Bits v;
    Bits w;

    kind = func_02159B10(a0, a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    x = func_0215A5DC((void *)a1);
    y = func_0215A5E4((void *)a1);
    func_0200E0B0(func_02012EBC((struct Big *)y));
    t = func_02012138(x);
    switch (kind) {
    case 0:
        if (func_021767A0(t, y) == 4)
            *out = 1;
        else
            *out = 0;
        break;
    case 1:
        *out = func_02166618(func_02012FB0(y));
        break;
    case 2:
        *out = func_0216662C(func_02012FB0(y));
        break;
    case 3:
        func_0216AEE8(a1, &v);
        *out = v.lo;
        break;
    case 4:
        func_0216AEE8(a1, &w);
        *out = w.f;
        break;
    }
    return 0;
}

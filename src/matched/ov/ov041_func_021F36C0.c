/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov041_021F36C0
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The counter is 32-bit with a u8 wraparound increment, so its (u16)
 * conversion is a separate value and the counter spills to [sp+4]; a u8
 * counter stays in a register.  i = 0 sits between the BE760 call and the
 * table copy (the store is scheduled above the call into r2); as the for
 * initialiser it lands after the copy loop.  s declared last puts it in r5.
 *
 * symbols:
 *   d_021F40A4     0x021F40A4  data  a4
 *   d_021F4208     0x021F4208  data  a4
 *   d_021F4660     0x021F4660  data  a1
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    V v[10];
} T;

extern int d_021F40A4;
extern T d_021F4208;
extern u8 d_021F4660[];
extern s16 d_020A1B38[];

extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern char *func_021BE480(void *p, int i, u16 j);
extern void  func_021BE4A4(void *p, int i, u16 j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void  func_0207AF1C(void *m, int a, int b);

void func_021F36C0(void *a0)
{
    char *e;
    unsigned int i;
    u8 j;
    int k;
    T tbl;
    void *s;

    s = (void *)func_02188D2C(a0);
    func_02189764(a0, 1, func_02188C84(a0), 0x730);
    func_021BE760(s, &d_021F40A4, 0);
    i = 0;
    tbl = d_021F4208;
    for (; i < 10; i = (u8)(i + 1)) {
        e = func_021BE480(s, 0, i);
        func_021BE4A4(s, 0, i, 1);
        *(V *)e = tbl.v[i];
        k = ((d_021F4660[i] << 14) >> 4) * 2;
        func_0207AF1C(e + 0x18, d_020A1B38[k], d_020A1B38[k + 1]);
        for (j = 0; j < 4; j++) {
            func_021BE6B8(func_021BE674(s, 0, i, j * 2), 0);
            func_021BE6B8(func_021BE674(s, 0, i, j * 2 + 1), 0);
        }
    }
}

/*
 * function: func_021F3838
 * address:  0x021F3838
 * packet:   pkt_ov046_021F3838
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 */

typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern s16 d_020A1B38[];

extern int func_021BE480(char *p, unsigned i, int j);
extern void  func_021BE4A4(void *p, int i, u16 j, int v);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void  func_0207AF1C(void *m, int a, int b);

void func_021F3838(void *a0, int a1, V *a2, u16 *a3, int a4, int a5)
{
    char *e;
    void *b;
    int i;
    int k;

    e = (char *)func_021BE480(a0, (int)0, (u16)a1);
    *(V *)e = *a2;
    if (a3) {
        k = (*a3 >> 4) * 2;
        func_0207AF1C(e + 0x18, d_020A1B38[k], d_020A1B38[k + 1]);
    }
    func_021BE4A4(a0, 0, a1, a5);
    for (i = 0; i < a4; i++) {
        b = func_021BE674(a0, 0, (u16)a1, (u16)i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
        func_021BE700(a0, 0, a1, i, 0);
    }
}

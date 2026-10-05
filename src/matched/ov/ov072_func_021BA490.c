/*
 * function: func_021BA490
 * address:  0x021BA490
 * packet:   pkt_ov072_021BA490
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB778  0x021BB778  thumb  ov072
 *   func_021BB790  0x021BB790  thumb  ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   d_021BBD60     0x021BBD60  data  ov072
 *   func_021BA86C  0x021BA86C  thumb  ov072
 *   func_021BA7F8  0x021BA7F8  thumb  ov072
 *   func_021BAE9C  0x021BAE9C  thumb  ov072
 *   func_021BA7D4  0x021BA7D4  thumb  ov072
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    u8 pad10[8];
    u16 f18;
    u16 f1A;
    u16 f1C;
    u16 f1E;
} W;

extern char d_021BBD60[];
extern u32 func_021BB778(char *p, int n);
extern void func_021BB790(char *p, int *a, int *b, int *c);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021BA86C(char *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5);
extern int func_021BA7F8(void *p, u16 x, u16 y);
extern void func_021BAE9C(void *p, int a, int b, int c, int s0, int s1, u16 s2);
extern void func_021BA7D4(char *p);

void func_021BA490(W *p, u16 x, u16 y, int a, u32 b, u32 c, u16 heap, int flag)
{
    u32 i;
    u32 n;
    int s0, s1, s2;
    int t0, t1, t2;
    int e;

    i = 0;
    n = func_021BB778((char *)b, 0);
    func_02082BCC(p, 0, 0x28);
    p->fC = 0x3d;
    p->f0 = c;
    p->f8 = func_02030734(heap, p->fC * 0x44, 0, d_021BBD60, 0x8C5);
    func_02082BCC(p->f8, 0, p->fC * 0x44);
    func_021BB790((char *)b, &s0, &s1, &s2);
    for (; i < p->fC; i++) {
        func_021BA86C(p->f8 + i * 0x44, a, i, n, s0, s1, s2, (void *)c, heap, flag);
    }
    e = func_021BA7F8(p, x, y);
    func_021BB790((char *)b, &t0, &t1, &t2);
    func_021BAE9C((char *)p + 0x20, e, n, t0, t1, t2, heap);
    p->f18 = 0;
    p->f1A = 0;
    p->f1C = 0;
    p->f1E = 0;
    func_021BA7D4((char *)p);
}

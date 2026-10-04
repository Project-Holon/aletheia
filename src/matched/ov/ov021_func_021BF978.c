/*
 * function: func_021BF978
 * address:  0x021BF978
 * packet:   pkt_ov021_021BF978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58 0x02188C58 thumb ov021
 *   func_0218FE80 0x0218FE80 thumb ov021
 *   func_0218FEA0 0x0218FEA0 thumb ov021
 *   func_0218FEA4 0x0218FEA4 thumb ov021
 *   func_0218FE78 0x0218FE78 thumb ov021
 *   func_0218FEC0 0x0218FEC0 thumb ov021
 *   func_0218FF00 0x0218FF00 thumb ov021
 */

typedef struct {
    int w[8];
} V8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    V8 v10;
    V8 v30;
    int f50;
    int f54;
    int f58;
} Q;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_02188C58(void *p);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, u32 v);
extern void func_0218FEA4(int);
extern void func_0218FE78(int, V8 *);
extern void func_0218FEC0(u8 *o);
extern void func_0218FF00(int);

void func_021BF978(Q *q)
{
    int r4;
    int r0;

    r4 = (int)func_02188C58((void *)q->f4);
    r0 = (int)func_0218FE80((void *)q->f4);
    q->fc = 60;
    q->f50 = 1;
    q->f54 = 1;
    q->f58 = r0;
    func_0218FEA0((u8 *)r0, (u32)(&q->fc));
    func_0218FEA4(q->f58);
    func_0218FE78(r4, &q->v30);
    q->v10 = q->v30;
    q->v10.w[1] = q->v10.w[1] - 0x64000;
    func_0218FEC0((u8 *)q->f58);
    func_0218FF00(q->f58);
}

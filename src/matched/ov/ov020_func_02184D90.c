/*
 * function: func_02184D90
 * address:  0x02184D90
 * packet:   pkt_ov020_02184D90
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback (0x9c-byte work area), then the 0x18-byte record
 * at +0x10 initialised by func_020141A8 from three u16 fields of q.
 * What closed it: `const Q *q`. Without const the q field loads are kept
 * below the outgoing stack-argument stores and `adds r1,r7` is scheduled
 * first; const lets them hoist (docs/notes/pkt_ov020_02184D38.c.txt has
 * the earlier near miss). The u16 stack parameter s fixes the frame.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_020141A8  0x020141A8  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02184388  0x02184388  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct { u16 f0; u16 f2; s16 f4; u16 f6; } Q;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_02184CEC(void *obj, void *p);
u16 func_020142A4(u16 s);
void func_02184388(void);
void func_020141A8(void *o, int a, int s, int g, int i, int h);

void *func_02184D90(void *p, int unused, int a, const Q *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC(r4, p);
    s = func_020142A4(s);
    func_020141A8(r4 + 0x10, a, (s16)s, q->f0, q->f6, q->f4);
    *(int *)(r4 + 0x2c) = 0;
    *(int *)(r4 + 0x40) = t;
    return r0v;
}

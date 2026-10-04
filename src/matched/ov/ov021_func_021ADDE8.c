/*
 * function: func_021ADDE8
 * address:  0x021ADDE8
 * packet:   pkt_ov021_021ADDE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Src { u32 f0; u32 f4; u32 arr[4]; } Src;
typedef struct Q { Src *src; u32 f4; u32 arr[4]; u32 f18; } Q;

struct G3dOwner;
struct G3dRec;
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_020477A4(u32 a, u16 i);

void func_021ADDE8(u32 a, Q *q)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    int i;

    q->src = (Src *)p[0];
    func_021AC1CC(a, p + 1);
    q->f18 = (u32)func_02047400((void *)q->src->f4, 0, (void *)q->src->f4);
    for (i = 0; i < 4; i++)
        q->arr[i] = (u32)func_02047564((struct G3dOwner *)q->f18, (const struct G3dOwner *)q->src->arr[i], 0);
    q->f4 = (u32)func_0204767C(q->f18, q->arr, 4);
    for (i = 0; i < 4; i++)
        func_020477A4(q->f4, i);
}

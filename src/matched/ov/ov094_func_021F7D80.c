/*
 * function: func_021F7D80
 * address:  0x021F7D80
 * packet:   pkt_ov094_021F7D80
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_0220AF20     0x0220AF20  data   ov094
 *   d_0220AC90     0x0220AC90  data   ov094  a1
 *   func_021FFE48  0x021FFE48  thumb  ov094
 *   func_022003EC  0x022003EC  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F8CB0  0x021F8CB0  thumb  ov094
 *   func_021F8EF8  0x021F8EF8  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x190 - 4];
    void *h190;             /* 0x190 */
    char pad194[0x1ec - 0x194];
    u32 m0 : 8;             /* 0x1ec */
    u32 m1 : 8;
    u32 mrest : 16;
    u16 heap;               /* 0x1f0 */
} Work;

typedef struct {
    int f0;
    int f4;
    int buf[9];         /* 0x08 */
} Job;

extern Work *d_0220AF20;
extern const char d_0220AC90[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern void func_021FFE48(void *h, int b, void *a);
extern void func_022003EC(void *h, void *a, int *buf, int b);
extern int func_021F935C(int a);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F8CB0(void *h, int *p);
extern void func_021F8EF8(void *);

void func_021F7D80(void *a, int b)
{
    Job *o;

    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AC90, 0x2f9);
    o->f4 = 0;
    o->f0 = b;
    func_021FFE48(d_0220AF20->h190, b, a);
    func_022003EC(d_0220AF20->h190, a, o->buf, b);
    d_0220AF20->m1 |= func_021F935C(b);
    func_021F896C(func_02030DA8(d_0220AF20->owner, (void (*)(void *, void *))func_021F8CB0, o, 0), func_021F8EF8, 0);
}

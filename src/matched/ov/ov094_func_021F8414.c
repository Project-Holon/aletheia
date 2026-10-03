/*
 * function: func_021F8414
 * address:  0x021F8414
 * packet:   pkt_ov094_021F8414
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_0220AF20     0x0220AF20  data   ov094
 *   d_0220AC90     0x0220AC90  data   ov094  a1
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F8F30  0x021F8F30  thumb  ov094
 *   func_021F8FB0  0x021F8FB0  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x1EC - 4];
    u32 lo : 16;            /* 0x1EC */
    u32 f : 2;
    u32 hi : 14;
    u16 heap;               /* 0x1F0 */
} Work;

typedef struct {
    int state;              /* 0 */
    u8 b;                   /* 4 */
    int c;                  /* 8 */
    int d;                  /* 0xC */
} St;

extern Work *d_0220AF20;
extern const char d_0220AC90[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern int func_021F935C(int x);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F8F30(void *, void *);
extern void func_021F8FB0(void *);

void func_021F8414(int a, int b, int c)
{
    St *s = sub_02030734((u16)((d_0220AF20->heap & 0x7FFF) | 0x8000), 0x10, 0, d_0220AC90, 0x538);

    if (a != 1) {
        s->state = 0;
        s->b = (a == 3) ? 0 : 1;
        s->c = b;
        s->d = c;
        d_0220AF20->f |= func_021F935C(b);
        func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8F30, s, 0), func_021F8FB0, 0);
    }
}

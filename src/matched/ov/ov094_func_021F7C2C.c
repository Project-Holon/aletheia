/*
 * function: func_021F7C2C
 * address:  0x021F7C2C
 * packet:   pkt_ov094_021F7C2C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * witness: arm9 func_0201C1E8 filed as src/matched/arm9/func_0201C1E8.c.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_0201C1E8  0x0201C1E8  thumb
 *   d_0220AF20     0x0220AF20  data   ov094
 *   d_0220AC90     0x0220AC90  data   ov094  a1
 *   func_021FF348  0x021FF348  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F8BAC  0x021F8BAC  thumb  ov094
 *   func_021F8C78  0x021F8C78  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x190 - 4];
    void *h190;             /* 0x190 */
    char pad194[0x1ec - 0x194];
    u32 m : 8;              /* 0x1ec */
    u32 mrest : 24;
    u16 heap;               /* 0x1f0 */
} Work;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Job;

extern Work *d_0220AF20;
extern const char d_0220AC90[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern int func_0201C1E8(int);
extern int func_021FF348(void *h, int a);
extern int func_021F935C(int a);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F8BAC(void *, void *);
extern void func_021F8C78(void *);

void func_021F7C2C(int a, int b)
{
    Job *o;

    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x18, 0, d_0220AC90, 0x29b);
    o->f4 = 0;
    o->f0 = a;
    o->f8 = 3;
    o->fc = 0;
    o->f14 = func_021FF348(d_0220AF20->h190, a);
    if (func_0201C1E8(b) == 1)
        o->f10 = 0x842;
    else
        o->f10 = 0x6318;
    d_0220AF20->m |= func_021F935C(a);
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8BAC, o, 0), func_021F8C78, 0);
}

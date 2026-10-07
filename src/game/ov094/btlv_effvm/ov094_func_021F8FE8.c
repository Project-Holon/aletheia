/*
 * function: func_021F8FE8
 * address:  0x021F8FE8
 * packet:   pkt_ov094_021F8FE8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F94F8  0x021F94F8  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x188];
    void *h;            /* 0x188 */
    char pad2[0x5C];
    int flag;           /* 0x1E8 */
} Work;

typedef struct {
    int pad0;
    int a;              /* 4 */
    u32 b;              /* 8 */
    u32 c;              /* 0xC */
    void *d;            /* 0x10 */
} Arg;

extern Work *d_0220AF20;

extern int func_021F7EB4(void);
extern void func_021F94F8(void *h, int a, u32 b, u16 c, void *d);
extern void func_021F89BC(void *h);

void func_021F8FE8(void *h, Arg *p)
{
    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h, p->a, p->b, p->c, p->d);
        d_0220AF20->flag = 1;
        func_021F89BC(h);
    }
}

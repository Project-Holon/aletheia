/*
 * function: func_021F8F30
 * address:  0x021F8F30
 * packet:   pkt_ov094_021F8F30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_02200344  0x02200344  thumb  ov094
 *   func_021F6AD0  0x021F6AD0  thumb  ov094
 *   func_021FFD6C  0x021FFD6C  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x190];
    void *obj;          /* 0x190 */
    void *obj2;         /* 0x194 */
    char pad2[0x50];
    u32 x;              /* 0x1E8 */
    u32 a : 8;          /* 0x1EC */
    u32 b : 8;
    u32 rest : 16;
} Work;

typedef struct {
    int state;          /* 0 */
    u8 b;               /* 4 */
    int c;              /* 8 */
    int d;              /* 0xC */
} St;

extern Work *d_0220AF20;

extern void func_02200344(void *o, int c, u32 b, int d);
extern int func_021F6AD0(void *o);
extern int func_021FFD6C(void *o);
extern void func_021F89BC(void *h);

void func_021F8F30(void *h, St *s)
{
    int st;
    u32 m;

    st = s->state;
    switch (st) {
    case 0:
        m = d_0220AF20->a | d_0220AF20->x | d_0220AF20->b;
        if (m)
            return;
        s->state = st + 1;
    case 1:
        func_02200344(d_0220AF20->obj, s->c, s->b, s->d);
        s->state = s->state + 1;
        return;
    case 2:
        if (func_021F6AD0(d_0220AF20->obj2))
            return;
        if (func_021FFD6C(d_0220AF20->obj))
            return;
        func_021F89BC(h);
        return;
    }
}

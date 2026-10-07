/*
 * function: func_021F87EC
 * address:  0x021F87EC
 * packet:   pkt_ov094_021F87EC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_02208918  0x02208918  thumb  ov094
 *   func_022088F4  0x022088F4  thumb  ov094
 *   func_02208924  0x02208924  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x1A4];
    void *obj;          /* 0x1A4 */
    char pad2[0x4C];
    int flag;           /* 0x1F4 */
} Work;

extern Work *d_0220AF20;

extern void func_02208918(char *p, int v);
extern u32 func_022088F4(void *o);
extern void func_02208924(void *o, u32 v);

void func_021F87EC(u32 v)
{
    d_0220AF20->flag = 1;
    func_02208918(d_0220AF20->obj, v);
    if (func_022088F4(d_0220AF20->obj) == 0)
        func_02208924(d_0220AF20->obj, 1);
}

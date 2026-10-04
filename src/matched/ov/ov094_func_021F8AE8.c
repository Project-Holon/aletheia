/*
 * unit:     yes
 * function: func_021F8AE8, func_021F8AFC, func_021F8B10, func_021F8B28
 * address:  0x021F8AE8
 * packet:   pkt_ov094_021F8AE8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F9A7C  0x021F9A7C  thumb  ov094
 *   func_021F9AA4  0x021F9AA4  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x188];
    void *h;            /* 0x188 */
    char pad2[0x8C];
    u32 tbl[1];         /* 0x218 */
} Work;

extern Work *d_0220AF20;

extern int func_021F9A7C(void *h);
extern int func_021F9AA4(void *h);

void func_021F8AE8(int i, u32 v)
{
    d_0220AF20->tbl[i] = v;
}

u32 func_021F8AFC(int i)
{
    return d_0220AF20->tbl[i];
}

int func_021F8B10(void)
{
    return func_021F9A7C(d_0220AF20->h);
}

int func_021F8B28(void)
{
    return func_021F9AA4(d_0220AF20->h);
}

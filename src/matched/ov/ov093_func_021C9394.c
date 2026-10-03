/*
 * function: func_021C9394
 * address:  0x021C9394
 * packet:   pkt_ov093_021C9394
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C9438  0x021C9438  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C9438(int a, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern void func_021D5EA8(u8 *p, int i, u8 n);
extern void func_021CD4B0(void *w, u32 id, ...);

typedef struct {
    u32 w; u8 b[8];
} Ent;

int func_021C9394(int p, const Ent *e)
{
    u8 *a;

    if (func_021C9438(p + 0x1ab8, e->b[0])) {
        a = func_021B9934(*(char **)(p + 8), e->b[0]);
        if (func_021D5B68(a) == 0) {
            func_021D5EA8(a, 1, e->b[1]);
            func_021D5EA8(a, 2, e->b[2]);
            func_021D5EA8(a, 3, e->b[3]);
            func_021D5EA8(a, 4, e->b[4]);
            func_021D5EA8(a, 5, e->b[5]);
            func_021D5EA8(a, 6, e->b[6]);
            func_021D5EA8(a, 7, e->b[7]);
            func_021CD4B0(*(void **)(p + 0xc), 0xb, e->b[0], e->b[1], e->b[2], e->b[3], e->b[4], e->b[5], e->b[6], e->b[7]);
            return 1;
        }
    }
    return 0;
}

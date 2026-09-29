/*
 * function: func_021C8D2C
 * address:  0x021C8D2C
 * packet:   pkt_ov093_021C8D2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C3370  0x021C3370  thumb  ov093
 *   func_021C3394  0x021C3394  thumb  ov093
 *   func_021C33E8  0x021C33E8  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B9934(int a, u8 b);
extern int func_021C3370(int a, int b);
extern int func_021C3394(int a, int b, int c);
extern void func_021C33E8(int a, int b, int c);
extern void func_021C5A1C(int a, int b);
extern void func_021C5A34(int a, int b);
extern void func_021C99A0(int a, void *b);
extern void func_021CD64C(void *w, u8 id, ...);

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent;

u8 func_021C8D2C(int p, const Ent *e, int c)
{
    u8 r = 0;
    int a = func_021B9934(*(int *)(p + 8), e->idx);
    int b = func_021B9934(*(int *)(p + 8), e->b6);

    if (func_021C3370(p, b) == 0) {
        if (e->fl)
            func_021C5A1C(p, a);
        if (e->b7 == 0) {
            r = !func_021C3394(p, b, 1);
        } else {
            r = 1;
        }
        if (r) {
            func_021C33E8(p, b, e->h4);
            if ((u8)e->ha)
                func_021C99A0(p, (void *)&e->h8);
            else if (c)
                func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x38c, e->b6, c, 0xffff0000);
        }
        if (e->fl)
            func_021C5A34(p, a);
    }
    return r;
}

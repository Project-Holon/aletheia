/*
 * function: func_021F1F34
 * address:  0x021F1F34
 * packet:   pkt_ov032_021F1F34
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1F34 0x021F1F34 thumb
 *   func_021F1F9C 0x021F1F9C thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F1F9C(void *task, u8 *s);
extern void func_02021FD8(u32 p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void);
extern void func_02082BCC(void *p, int v, int n);

void func_021F1F34(char *p, u8 *q, int *r)
{
    u8 *t;

    func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1F9C, 0x14, 0);
    t = func_02031290();
    func_02082BCC(t, 0, 0x14);
    *(char **)(t + 0xc) = p;
    *(u8 **)(t + 8) = q;
    t[2] = 2;
    t[3] = (q[0] + 4) << 4;
    func_02021FD8(*(u32 *)(*(char **)(t + 0xc) + 0xac), 3, t[3], 0x10, 4, 0x7fff);
    if (r != 0) {
        *(int **)(t + 0x10) = r;
        (*r)++;
    }
}

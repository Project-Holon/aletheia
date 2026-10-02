/*
 * function: func_021F21B0
 * address:  0x021F21B0
 * packet:   pkt_ov032_021F21B0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F21B0 0x021F21B0 thumb
 *   func_021F21F8 0x021F21F8 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F21F8(void *task, u8 *s);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void *t);
extern void func_02082BCC(void *p, int v, int n);

void func_021F21B0(char *p, char *q, int *r)
{
    void *t;
    u8 *s;

    t = func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F21F8, 0x10, 0);
    s = func_02031290(t);
    func_02082BCC(s, 0, 0x10);
    *(char **)(s + 8) = p;
    *(char **)s = q;
    *(char **)(s + 4) = q + 0x18;
    *(void **)(q + 0x2c) = t;
    if (r != 0) {
        *(int **)(s + 0xc) = r;
        (*r)++;
    }
}

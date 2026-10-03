/*
 * function: func_021F20A8
 * address: 0x021F20A8
 * packet: pkt_ov032_021F20A8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F20E4 0x021F20E4 thumb ov032
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F20E4(void *task, char *q);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
void func_021F20A8(char *p, char *q, int *r)
{
    u8 *t;
    t = func_02031290(func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F20E4, 0x10, 0));
    func_02082BCC(t, 0, 0x10);
    *(char **)(t + 8) = p;
    *(char **)(t + 4) = q;
    if (r != 0) {
        *(int **)(t + 0xc) = r;
        (*r)++;
    }
}

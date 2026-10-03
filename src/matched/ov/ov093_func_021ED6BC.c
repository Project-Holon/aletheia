/*
 * unit:     yes
 * function: func_021ED6BC, func_021ED714
 * address:  0x021ED6BC
 * packet:   pkt_ov093_021ED6BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED724  0x021ED724  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern void *func_021D5844(void *m);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void *node);
extern void func_021ED724(void);

void func_021ED6BC(char *p, u32 k, u32 a)
{
    struct S *t;

    t = (struct S *)func_02031290(func_020311B8(*(u32 *)(p + 0x2c), (void *)func_021ED724, 0x18, 1));
    t->v = func_021D5844(func_021B98AC(*(char *const **)(p + 0x138),
                                              func_021B8ED8(*(u8 **)(p + 0x134), k)));
    t->w = p;
    t->k = k;
    t->cnt = (u8 *)p + 0x40;
    t->f = a;
    t->c = 0;
    (*t->cnt)++;
}

int func_021ED714(char *p)
{
    if (*(u8 *)(p + 0x40) == 0)
        return 1;
    return 0;
}

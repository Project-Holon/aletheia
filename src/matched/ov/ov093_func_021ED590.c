/*
 * unit:     yes
 * function: func_021ED590, func_021ED5D8
 * address:  0x021ED590
 * packet:   pkt_ov093_021ED590
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED5E8  0x021ED5E8  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *p; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

extern u8 func_021B8E70(u8 *p, u32 k);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void *node);
extern void func_021ED5E8(void);

void func_021ED590(char *p, u8 k, u32 a)
{
    struct S *t;

    if (k != 6) {
        t = (struct S *)func_02031290(func_020311B8(*(u32 *)(p + 0x2c), (void *)func_021ED5E8, 0x18, 1));
        t->p = p;
        t->k = k;
        t->a = a;
        t->v = func_021B8E70(*(u8 **)(p + 0x134), k);
        t->cnt = (u8 *)p + 0x40;
        t->c = 0;
        (*t->cnt)++;
    }
}

int func_021ED5D8(char *p)
{
    if (*(u8 *)(p + 0x40) == 0)
        return 1;
    return 0;
}

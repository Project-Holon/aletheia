/*
 * function: func_021ED3D4
 * address:  0x021ED3D4
 * packet:   pkt_ov093_021ED3D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the record from func_02031290 is a struct pointer, not u8 *: the
 * cnt field is then forwarded across the st store instead of being reloaded
 * (u8 * base plus a local kept in r1 gave 84 bytes out).
 *
 * symbols:
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED460  0x021ED460  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct T { char *e; u16 st; u16 pad; u8 *cnt; };

extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void *func_021D5864(void *m);
extern void func_021F7EE8(void *m, int key);
extern void func_021F7A28(u32 a, u32 b);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void *node);
extern void func_021ED460(void);

void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag)
{
    struct T *t;
    u8 *m;
    u8 y;

    t = (struct T *)func_02031290(func_020311B8(*(u32 *)(p + 0x2c), (void *)func_021ED460, 0xc, 1));
    t->e = p + 0x48 + k * 0xc;
    t->cnt = (u8 *)p + 0x41;
    t->st = 0;
    (*t->cnt)++;
    m = func_021B9920(*(void **)(p + 0x138), a, b);
    y = func_021B8E70(*(u8 **)(p + 0x134), k);
    func_021F7EE8(func_021D5864(m), y);
    if (flag == 0)
        func_021F7A28(y, 0x26d);
}

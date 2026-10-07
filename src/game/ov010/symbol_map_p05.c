/*
 * file:     symbol_map_p05.c
 * unit:     yes
 * function: func_02166B58, func_02166C4C, func_02166C7C
 * address:  0x02166B58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0216559C  0x0216559C  thumb  ov010
 *   ov215_id       0x000000D7  data   a1
 *   d_021F7118     0x021F7118  data   ov215  a4
 *   func_02013E40  0x02013E40  thumb
 *   func_02012894  0x02012894  thumb
 *   d_02171F2C  0x02171F2C  data  ov010  a4
 */
struct IcaAnime;
struct Evt;
struct Ctx;
struct Desc;
struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

struct E {
    u32 val;
    u32 key;
};

struct P {
    u16 pad[2];
    u16 f4;
};

extern u32   func_02017E1C(void *obj, u32 key, u32 off);
extern int func_020144DC(int a0, int a1);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void *func_020145CC(void *a0);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void  func_0216559C(u16 x);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02013E40(u32 a);
extern struct P *func_02012894(void *a);
u32 func_02166B58(void *obj, u32 *mode, u32 *args);
void *func_02166C4C(void *a, void *b, void *c);
u32 func_02166C7C(void *a, u32 b);
extern char ov215_id[];
extern char d_021F7118[];
extern struct E d_02171F2C[2];


/*
 * Stage machine on *mode, same family as ov002 func_021542C0.  The second
 * argument to func_020120B4 is pooled 0xD7 (215), a linker overlay id for
 * ov215; the third, 0x021F7118, lies in its window.
 */
u32 func_02166B58(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];
    u32 a1 = args[1];
    u32 a2 = args[2];

    switch (*mode) {
    case 0:
        if (func_02017E1C((void *)args[3], 0x4C, 0) == 0 || func_02017E1C((void *)args[3], 3, 0) == 1) {
            *mode = 7;
        } else {
            *mode = 1;
        }
        break;
    case 1:
        args[4] = a1;
        args[5] = args[3];
        *mode = 2;
        break;
    case 2:
        func_02012374(obj, (struct Evt **)func_021BE8D4((void *)a0, a2, 0, 0));
        *mode = 3;
        break;
    case 3:
        func_02012374(obj, (struct Evt **)func_020144DC(a0, a2));
        *mode = 4;
        break;
    case 4:
        func_020120B4((struct IcaAnime *)a0, (u32)ov215_id, d_021F7118, &args[4]);
        *mode = 5;
        break;
    case 5:
        func_02012374(obj, func_020145CC((void *)a0));
        *mode = 6;
        break;
    case 6:
        func_02012374(obj, (struct Evt **)func_021BE92C((void *)a0, a2, 0, 0, 1, 0, 0));
        func_0216559C(func_02017E1C((void *)args[3], 5, 0));
        *mode = 7;
        break;
    case 7:
        return 1;
    }
    return 0;
}

void *func_02166C4C(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, func_02166B58, 24);
    w = func_020124E8(task);
    w[0] = a;
    w[2] = b;
    w[1] = func_020120F4(a);
    w[3] = c;
    return task;
}


u32 func_02166C7C(void *a, u32 b)
{
    u32 v = func_02013E40(b);
    u32 r;
    int i;
    if (v == 0x1A6)
        return func_02013E40(func_02012894(a)->f4);
    for (i = 0; i < 2; i++) {
        if (d_02171F2C[i].key == v) {
            r = (u16)*(u32 *)((char *)d_02171F2C + i * 8);
            goto done;
        }
    }
    r = 0xFFFF;
done:
    if (r != 0xFFFF)
        v = (u16)r;
    return v;
}

/*
 * file:     symbol_map_p02.c
 * unit:     yes
 * function: func_021665D0, func_021665F0, func_02166618, func_0216662C, func_02166640, func_02166658, func_0216666C
 * address:  0x021665D0
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
 *   func_0216649C  0x0216649C  thumb  ov010
 *   func_02166324  0x02166324  thumb  ov010
 *   func_021663F4  0x021663F4  thumb  ov010
 *   func_021666B8 0x021666B8 thumb ov010
 *   func_02161CDC 0x02161CDC thumb ov010
 *   func_0216670C 0x0216670C thumb ov010
 */
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_0216649C(void *p);
extern int func_02166324(u8 *grid, int id);
extern int func_021663F4(u8 *list, int def, unsigned dir);
extern int func_021666B8(void *, unsigned int *);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02161CDC(void *, void *, u8, u8);
extern int func_0216670C(void *);
int func_021665D0(int a0, int a1);
int func_021665F0(int a0, int a1, int a2);
int func_02166618(int a0);
int func_0216662C(int a0);
int func_02166640(int a0);
u32 func_02166658(void *p, u32 i);
void *func_0216666C(void *a, void *b, void *c);


int func_021665D0(int a0, int a1)
{
    int t4;
    void *p;

t4 = a1 + 0;
    p = (void *)func_0216649C((void *)a0);
loc_021665D8:
    if (p == 0) goto loc_021665E8;
loc_021665DC:
a1 = t4 + 1;
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = func_02166324(p, a1);
loc_021665E6:
    return a0;
loc_021665E8:
a0 = 0x46;
a0 = a0 << 2;
    return a0;}


int func_021665F0(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *p;

t5 = a1 + 0;
t4 = a2 + 0;
    p = (void *)func_0216649C((void *)a0);
loc_021665FA:
    if (p == 0) goto loc_02166614;
loc_021665FE:
a1 = t5 + 1;
a1 = a1 << 0x18;
a2 = t4 << 0x18;
a1 = (unsigned)a1 >> 0x18;
a2 = (unsigned)a2 >> 0x18;
    a0 = func_021663F4(p, a1, a2);
loc_0216660C:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
a0 = a0 - 1;
    return a0;
loc_02166614:
a0 = 4;
    return a0;}


/*
 * Unlabelled leaf: true when the argument plus one, truncated to a byte,
 * is 1.
 */
int func_02166618(int a0)
{
    if ((u8)(a0 + 1) == 1)
        return 1;
    return 0;
}




int func_0216662C(int a0)
{

a0 = a0 + 1;
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 5) goto loc_0216663A;
loc_02166636:
a0 = 1;
    return a0;
loc_0216663A:
a0 = 0;
    return a0;}


/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C37C): true when the
 * argument plus one, truncated to a byte, is 2, 3 or 4. Twin of
 * func_02166618.
 */
int func_02166640(int a0)
{
    u8 t = a0 + 1;

    if ((u8)(t + 0xFE) <= 2)
        return 1;
    return 0;
}


/*
 * Unlabelled leaf (no lr save) called from func_02166734 case 4; 18 bytes
 * plus 2 bytes of alignment padding before func_0216666C.
 */
u32 func_02166658(void *p, u32 i)
{
    if (p == 0)
        return 10;
    return *(u32 *)((u8 *)p + i * 0x1C + 0x14);
}

void *func_0216666C(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, func_021666B8, 32);
    w = func_020124E8(task);
    w[6] = b;
    w[7] = c;
    func_02161CDC(w, a, 1, 0);
    ((int *)w)[2] = func_0216670C(b);
    return task;
}

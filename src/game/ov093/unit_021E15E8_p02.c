/*
 * file:     unit_021E15E8_p02.c
 * unit:     yes
 * function: func_021E1784, func_021E17B0, func_021E17DC
 * address:  0x021E1784
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   data_021F2BE8 0x021F2BE8 data a4
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
struct S;
typedef unsigned char u8;

typedef unsigned int   u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *, void *);
void func_021E1784(int a, int b, int c);
void func_021E17B0(int a, int b, int c);
void func_021E17DC(void *a, void *b, int c);
u32 *func_021E18E0(u32 *p);
extern u32 data_021F2BE8[];


void func_021E1784(int a, int b, int c)
{
    if (c == func_021D775C(2) && func_021D69AC(func_021C7CF4((int *)b, c), 0) == 0)
        func_021D76BC(34, 26);
}


static inline void func_021E17B0_set48(int v)
{
    func_021D76BC(48, v);
}


/*
 * The product passed through a static inline helper is computed before the
 * helper's constant first argument is loaded (no result copy).
 */
void func_021E17B0(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021E17B0_set48(func_021D69AC(func_021C7CF4((int *)b, c), 0) * 100);
}

/*
 * follower: 021E18E0 store-and-return stub included.
 */
void func_021E17DC(void *a, void *b, int c)
{
    void *m;
    int x;
    int y;
    int z;
    u8 *p;
    if (c != func_021D775C(2)) return;
    m = func_021C7CF4(b, c);
    x = func_021D69AC(m, 1);
    y = func_021D69AC(m, 2);
    z = func_021D69AC(m, 0);
    if (x != 0) {
        p = func_021C88A4(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 2;
        p[12] = -x;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 1;
        p[6] = 0;
        func_021C88C8(b, p);
    }
    if (y != 0) {
        p = func_021C88A4(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 4;
        p[12] = -y;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 2;
        p[6] = 0;
        func_021C88C8(b, p);
    }
    if (z != 0) {
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 0;
        p[6] = 0;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, 724);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
    }
}

u32 *func_021E18E0(u32 *p)
{
    *p = 3;
    return data_021F2BE8;
}

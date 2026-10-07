/*
 * file:     unit_02198D3C_p05.c
 * unit:     yes
 * function: func_02198F68, func_02198FB0
 * address:  0x02198F68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021D04A4  0x021D04A4  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_021D04C4  0x021D04C4  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0219BF54  0x0219BF54  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

extern u32 func_0216D6BC(u32, u32);
extern int func_0219BF48(u32 a);
extern void func_021D04A4(void *a);
extern void func_0216D8C0(u32, Vec *);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D7CC(u32);
extern void *func_0216D6D4(void *p);
extern int func_021D04C4(u32 a);
extern u32 func_021AC154(u32);
extern void func_0219BF3C(int a, u32 v);
extern void func_0219BF54(int a0);
int func_02198F68(u32 a);
int func_02198FB0(u32 a);
extern u32 *d_021DDBD4;


/*
 * Addresses are Black-image addresses.
 */
int func_02198F68(u32 a)
{
    u32 t;

    func_0216D6BC(a, 4);
    t = func_0219BF48(a);
    if (t != 0) {
        func_021D04A4((void *)t);
    }
    {
        Vec v = { 0, 0, 0 };
        func_0216D8C0(a, &v);
    }
    func_0216D568((void *)a, 160);
    func_0216D570((char *)a, (2 << 14));
    func_0216D7CC(a);
    return 0;
}


int func_02198FB0(u32 a)
{
    u32 *p;
    u32 r;

    p = func_0216D6D4((void *)a);
    {
        Vec v = { 0, 0, 0 };
        v.y = d_021DDBD4[p[0]];
        func_0216D8C0(a, &v);
        r = func_0219BF48(a);
        if (r != 0) {
            if (func_021D04C4(r) == 1) {
                func_021AC154(r);
                func_0219BF3C(a, 0);
            }
        }
        p[0] = p[0] + 2;
        if (p[0] < 16) {
            return 0;
        }
        v.y = 0;
        func_0216D8C0(a, &v);
    }
    func_0216D568((void *)a, 1344);
    func_0219BF54(a);
    func_0216D7CC(a);
    return 1;
}

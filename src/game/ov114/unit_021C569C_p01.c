/*
 * file:     unit_021C569C_p01.c
 * unit:     yes
 * function: func_021C569C, func_021C56B4, func_021C56CC
 * address:  0x021C569C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02085710  0x02085710  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   g_021D3B68     0x021D3B68  data ov114
 *   g_021D3B84     0x021D3B84  data ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Ov114Global {
    char pad[0x10];
    int  f10;
    int  f14;
    int  f18;
} Ov114Global;

extern void *func_0205A17C(int name, unsigned long size, int align);
extern void func_0205A1B0(int, int, int);
void func_02085710(void *p);
void func_02086028(void *p, int a);
void func_02086078(void *p, int a);
void *func_021C569C(int a, int b);
void func_021C56B4(int a);
void func_021C56CC(void);
extern Ov114Global g_021D3B68;
extern char        g_021D3B84;


/*
 * Thunk: func_0205A17C(10, a, b) through the literal pool.
 */
void *func_021C569C(int a, int b)
{
    return func_0205A17C(0xa, a, b);
}


/*
 * Thunk: func_0205A1B0(10, a, 0) through the literal pool.
 */
void func_021C56B4(int a)
{
    func_0205A1B0(0xa, a, 0);
}


void func_021C56CC(void)
{
    func_02085710((char *)g_021D3B68.f18 + 0x1b8 + 0x800);
    func_021C56B4((int)((void *)g_021D3B68.f18));
    g_021D3B68.f18 = 0;
    func_02086028(&g_021D3B84, 0);
    g_021D3B68.f14 = 3;
    g_021D3B68.f10 = 4;
    func_02086078(&g_021D3B84, 4);
}

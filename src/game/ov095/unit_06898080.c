/*
 * file:     unit_06898080.c
 * unit:     yes
 * function: func_06898080, func_068980CC
 * address:  0x06898080
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_0689D638     0x0689D638  data   ov095  a4
 *   d_0689D630     0x0689D630  data   ov095  a4
 *   d_0689D640     0x0689D640  data   ov095  a4
 */
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021D7040(struct Node *n);
extern int func_021D76BC();
extern void func_021D7704(int key, int m);
extern int func_021D775C(int key);
void func_06898080(void *n);
u8 *func_06898088(u32 *p);
void func_06898094(void);
u8 *func_06898098(u32 *p);
void func_068980A4(void);
u8 *func_068980B0(u32 *p);
void func_068980BC(void);
void func_068980CC(void);
extern u8 d_0689D638[];
extern u8 d_0689D630[];
extern u8 d_0689D640[];


/*
 * Handed extent 0x06898070 (92 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D6F0C (ARM linker stub, not compilable); the seven functions after
 * it (0x06898080..0x068980CC) are this unit. Two of them (0x06898094,
 * 0x06898088) are entries of the {key, fn} table at 0x0689D630 that
 * func_06898020 walks.
 */
void func_06898080(void *n)
{
    func_021D7040(n);
}


u8 *func_06898088(u32 *p)
{
    *p = 1;
    return d_0689D638;
}


void func_06898094(void)
{
}


u8 *func_06898098(u32 *p)
{
    *p = 1;
    return d_0689D630;
}


void func_068980A4(void)
{
    func_021D76BC(0x4a, 1);
}


u8 *func_068980B0(u32 *p)
{
    *p = 2;
    return d_0689D640;
}


void func_068980BC(void)
{
    func_021D7704(0x35, 0x1ab8);
}

void func_068980CC(void)
{
    if (func_021D775C(0x16) == 4)
        func_021D76BC(0x4b, 1);
}

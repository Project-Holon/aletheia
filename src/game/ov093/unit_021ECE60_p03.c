/*
 * file:     unit_021ECE60_p03.c
 * unit:     yes
 * function: func_021ED510, func_021ED53C, func_021ED554, func_021ED56C
 * address:  0x021ED510
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
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 *   func_021ED9EC  0x021ED9EC  thumb  ov093
 *   func_021F7A28  0x021F7A28  thumb  ov094
 */
struct E;
typedef unsigned char u8;

typedef unsigned int   u32;

extern void func_021EDA04(struct E *e);
extern void func_021F87D4(u32 v);
extern void func_021ED9EC(struct E *e);
extern void func_021F7A28(int a, u32 b);
int func_021ED510(u8 *p, int a, int b);
void func_021ED53C(u8 *p, int k);
int func_021ED554(u8 *p, int k);
void func_021ED56C(int a, int b);

int func_021ED510(u8 *p, int a, int b)
{
    func_021EDA04((struct E *)(p + 0x48 + a * 12));
    func_021EDA04((struct E *)(p + 0x48 + b * 12));
    func_021F87D4(0);
    return 1;
}

void func_021ED53C(u8 *p, int k)
{
    func_021ED9EC((struct E *)(p + 0x48 + k * 12));
    func_021F87D4(1);
}

int func_021ED554(u8 *p, int k)
{
    func_021EDA04((struct E *)(p + 0x48 + k * 12));
    func_021F87D4(0);
    return 1;
}

void func_021ED56C(int a, int b)
{
    func_021F7A28(b, 0x25f);
}

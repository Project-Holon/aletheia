/*
 * file:     beacon_view_p07.c
 * unit:     yes
 * function: func_021F0FC8, func_021F0FE8
 * address:  0x021F0FC8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_02165C48 0x02165C48 thumb ov010
 */
struct Sub0204A9D0;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct S S;

extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_02165C48(S *p);
void func_021F0FC8(char *p, u8 *q, int r);
int func_021F0FE8(S *p);

void func_021F0FC8(char *p, u8 *q, int r)
{
    func_0204A9D0((*(int **)(p + 0x170))[q[0]], (struct Sub0204A9D0 *)(*(int *)(p + r * 8 + 0x2d8)));
}

int func_021F0FE8(S *p)
{
    switch (func_02165C48(p)) {
    case 21: return 0;
    case 20: return 1;
    default: return 2;
    }
}

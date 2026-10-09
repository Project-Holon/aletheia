/*
 * file:     unit_021DDB24.c
 * unit:     yes
 * function: func_021DDB24, func_021DDB38, func_021DDB44, func_021DDB58
 * address:  0x021DDB24
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
 *   func_021DDCD8   0x021DDCD8  thumb
 *   d_021F17AC     0x021F17AC  data   ov093  a4
 *   d_021F171C     0x021F171C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

void func_021DDB24(int a, int b, int c, int d);
int *func_021DDB38(int *p);
void func_021DDB44(int a, int b, int c, int d);
int *func_021DDB58(int *p);
/* 021DDB44  shape F2: two stack constants (0xe, 0) */
extern int d_021F17AC[];
extern int d_021F171C[];


/* 021DDB24  shape F2: two stack constants (0xb, 0) */
/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xb; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
void func_021DDB24(int a, int b, int c, int d)
{
    func_021DDCD8(a, b, c, d, 0xb, 0);
}


int *func_021DDB38(int *p)
{
    *p = 2;
    return d_021F17AC;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xe; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
void func_021DDB44(int a, int b, int c, int d)
{
    func_021DDCD8(a, b, c, d, 0xe, 0);
}


int *func_021DDB58(int *p)
{
    *p = 2;
    return d_021F171C;
}

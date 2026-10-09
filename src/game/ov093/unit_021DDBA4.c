/*
 * file:     unit_021DDBA4.c
 * unit:     yes
 * function: func_021DDBA4, func_021DDBB8, func_021DDBC4, func_021DDBD8
 * address:  0x021DDBA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DDCD8   0x021DDCD8  thumb
 *   d_021F17DC     0x021F17DC  data   ov093  a4
 *   d_021F172C     0x021F172C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

void func_021DDBA4(int a, int b, int c, int d);
int *func_021DDBB8(int *p);
void func_021DDBC4(int a, int b, int c, int d);
int *func_021DDBD8(int *p);
/* 021DDBC4  shape F2: two stack constants (2, 0) */
extern int d_021F17DC[];
extern int d_021F172C[];


/* 021DDBA4  shape F2: two stack constants (4, 0) */
/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #4; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
void func_021DDBA4(int a, int b, int c, int d)
{
    func_021DDCD8(a, b, c, d, 4, 0);
}


int *func_021DDBB8(int *p)
{
    *p = 2;
    return d_021F17DC;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #2; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
void func_021DDBC4(int a, int b, int c, int d)
{
    func_021DDCD8(a, b, c, d, 2, 0);
}


int *func_021DDBD8(int *p)
{
    *p = 2;
    return d_021F172C;
}

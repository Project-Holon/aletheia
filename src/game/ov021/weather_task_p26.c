/*
 * file:     weather_task_p26.c
 * unit:     yes
 * function: func_021A6A3C, func_021A6A64
 * address:  0x021A6A3C
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
 *   func_0216D608  0x0216D608  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A6908  0x021A6908  thumb
 */
typedef unsigned short u16;

typedef struct {
    int pad[7];
    int f1c;
} S_021A6A3C;

typedef unsigned int u32;

extern u16 func_0216D608(int a);
extern void func_020061E4(u32 a);
extern int func_021A6908(S_021A6A3C *a, int b, int c);
int func_021A6A3C(S_021A6A3C *a, int b, int c);
int func_021A6A64(S_021A6A3C *a, int b, int c);


int func_021A6A3C(S_021A6A3C *a, int b, int c)
{
    if (func_0216D608(a->f1c) == 2) {
        func_020061E4(0x55e);
    }
    return func_021A6908(a, b, c);
}


int func_021A6A64(S_021A6A3C *a, int b, int c)
{
    if (func_0216D608(a->f1c) == 3) {
        func_020061E4(0x55e);
    }
    return func_021A6908(a, b, c);
}

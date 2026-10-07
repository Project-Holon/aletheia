/*
 * file:     weather_task_p77.c
 * unit:     yes
 * function: func_021A652C, func_021A658C
 * address:  0x021A652C
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
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216D3CC(int a0);
extern u16 func_0216D5F8(void *p);
extern int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
int func_021A652C(void *a, void *b, int c, int d, u16 e, int f);
int func_021A658C(void *a, void *b, int c, int d, u16 e, int f);


int func_021A652C(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 1) {
        if (e != 9) {
            if (e != func_0216D5F8(b) && f == 0) {
                return 3;
            }
            return func_021A658C(a, b, c, d, e, f);
        }
        return 1;
    }
    return 0;
}


int func_021A658C(void *a, void *b, int c, int d, u16 e, int f)
{
    int r;
    int loc;
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A652C(a, b, c, d, e, f);
    }
    r = func_021A5B6C((u32)a, (u32)b, e, (u32)(&loc));
    if (f == 1 && r != 0 && (r & 0x10) == 0) {
        r = 0;
    }
    if (loc != -1) {
        int t;
        func_021AB0F0(loc);
        t = func_021AB0F8(loc);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (f == 1) {
                return 2;
            }
        }
    }
    return 4;
}

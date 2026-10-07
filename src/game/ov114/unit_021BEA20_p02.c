/*
 * file:     unit_021BEA20_p02.c
 * unit:     yes
 * function: func_021BEBA8, func_021BEBC8, func_021BEBE0, func_021BEBF0, func_021BEC00
 * address:  0x021BEBA8
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
 *   func_021BEAB8  0x021BEAB8  arm  ov114
 */
struct Conn;
typedef unsigned char u8;

typedef unsigned int u32;

extern struct Conn *func_021BEAB8(void *mutexInfo_p, struct Conn *handle_p, unsigned long order);
int func_021BEBA8(int a, int b);
int func_021BEBC8(int a, int b);
void func_021BEBE0(int a, int b);
struct Conn *func_021BEBF0(int a, int b);
struct Conn *func_021BEC00(int a, int b);


int func_021BEBA8(int a, int b)
{
    return -(func_021BEAB8((void *)a, (struct Conn *)b, 4) == 0);
}


int func_021BEBC8(int a, int b)
{
    u8 *p = (u8 *)func_021BEC00(a, b);

    return p ? *(u32 *)(p + 0x14) : 0;
}


/*
 * ov114 tail-call thunk: func_021BEAB8(a, b, 1) via `ldr ip,pool; bx ip`.
 */
void func_021BEBE0(int a, int b)
{
    func_021BEAB8((void *)a, (struct Conn *)b, 1);
}


/*
 * ov114 tail-call thunk: func_021BEAB8(a, b, 2) via `ldr ip,pool; bx ip`.
 */
struct Conn *func_021BEBF0(int a, int b)
{
    return func_021BEAB8((void *)a, (struct Conn *)b, 2);
}


struct Conn *func_021BEC00(int a, int b)
{
    return func_021BEAB8((void *)a, (struct Conn *)b, 0);
}

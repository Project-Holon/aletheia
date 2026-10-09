/*
 * file:     net_devwireless.c
 * unit:     yes
 * function: func_02177020, func_02177028, func_02177080, func_02177094, func_021770A8, func_021770CC, func_021770EC
 * address:  0x02177020
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021796A0  0x021796A0  data  a4
 *   g_021797A0     0x021797A0  data   a4
 *   d_0217976C     0x0217976C  data   a1
 *   func_02030734  0x02030734  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02177280  0x02177280  thumb  ov014
 *   func_02177AA8 0x02177AA8 thumb ov014
 *   func_0217796C 0x0217796C thumb ov014
 *   func_021776C4 0x021776C4 thumb ov014
 *   func_020307B0 0x020307B0 arm
 *   func_02177EB0 0x02177EB0 thumb ov014
 *   func_02177560 0x02177560 thumb ov014
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct DevWireless {
    u32 id;
    void (*callback)(void *);
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_0203D798(void);
extern int func_02177280(int a, int b, u32 c, int d);
extern int func_02177AA8(void);
extern void func_0217796C(u32);
extern int func_021776C4(void);
extern u32 func_020307B0(void *p);
extern int func_02177EB0(int a);
extern void func_02177560(void);
void *func_02177020(void);
int func_02177028(int a, u32 b, int c, int d);
int func_02177080(void (*cb)(void));
int func_02177094(u32 a);
int func_021770A0(void);
int func_021770A8(void *arg);
int func_021770CC(void (*cb)(void *));
int func_021770EC(void);
int func_021770F8(void);
int func_021770FC(void);
int func_02177100(void);
extern struct DevWireless *g_021797A0;
extern char d_0217976C[];


void *func_02177020(void)
{
    return (void *)0x021796A0;
}



int func_02177028(int a, u32 b, int c, int d)
{
    int ok;
    struct DevWireless *p;

    if (g_021797A0 != 0)
        return 0;
    p = func_02030734(a, 8, 1, d_0217976C, 0xb4);
    ok = 1;
    g_021797A0 = p;
    p->id = b;
    if (func_0203D798()[0x65] != 5)
        ok = 0;
    return func_02177280(a, c, d, ok);
}


/*
 * extent: trailing two-byte zero alignment padding.
 */
int func_02177080(void (*cb)(void))
{
    if (cb != 0) {
        func_02177AA8();
        cb();
    }
    return func_02177AA8();
}


/*
 * extent: lead and unlabelled tail-call follower at 0x021770A0.
 */
int func_02177094(u32 a)
{
    func_0217796C(a);
    return 1;
}


int func_021770A0(void)
{
    return func_021776C4();
}


int func_021770A8(void *arg)
{
    if (g_021797A0->callback != 0)
        g_021797A0->callback(arg);
    func_020307B0(g_021797A0);
    g_021797A0=0;
    return 1;
}


int func_021770CC(void (*cb)(void *))
{
    if(g_021797A0 != 0) {
        g_021797A0->callback = cb;
        return func_02177EB0((int)func_021770A8);
    }
    return 1;
}


int func_021770EC(void) { func_02177560(); return 1; }


int func_021770F8(void) { return 1; }


int func_021770FC(void) { return 1; }


int func_02177100(void) { return 1; }

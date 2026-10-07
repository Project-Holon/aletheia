/*
 * file:     net_devwireless_p02.c
 * unit:     yes
 * function: func_02177094, func_021770A8, func_021770CC, func_021770EC
 * address:  0x02177094
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
 *   func_0217796C 0x0217796C thumb ov014
 *   func_021776C4 0x021776C4 thumb ov014
 *   g_021797A0 0x021797A0 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_02177EB0 0x02177EB0 thumb ov014
 *   func_02177560 0x02177560 thumb ov014
 */
typedef unsigned int u32;

typedef unsigned char u8;

extern void func_0217796C(u32);
extern int func_021776C4(void);
extern u32 func_020307B0(void *p);
extern int func_02177EB0(int a);
extern void func_02177560(void);
int func_02177094(u32 a);
int func_021770A0(void);
int func_021770A8(void *arg);
int func_021770CC(void (*cb)(void *));
int func_021770EC(void);
int func_021770F8(void);
int func_021770FC(void);
int func_02177100(void);
extern u8 *g_021797A0;

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
    if (*(void (**)(void *))(g_021797A0+4) != 0)
        (*(void (**)(void *))(g_021797A0+4))(arg);
    func_020307B0(g_021797A0);
    g_021797A0=0;
    return 1;
}

int func_021770CC(void (*cb)(void *))
{
    if(g_021797A0 != 0) {
        *(void (**)(void *))(g_021797A0+4)=cb;
        return func_02177EB0((int)func_021770A8);
    }
    return 1;
}

int func_021770EC(void) { func_02177560(); return 1; }

int func_021770F8(void) { return 1; }

int func_021770FC(void) { return 1; }

int func_02177100(void) { return 1; }

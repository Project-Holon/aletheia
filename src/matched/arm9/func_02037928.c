/*
 * function: func_02037928
 * address:  0x02037928
 * packet:   pkt_02037894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788   0x0203D788  arm
 *   func_02037858   0x02037858  arm
 *   func_02038924   0x02038924  arm
 *   func_0203D798   0x0203D798  arm
 *   func_02037288   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037928.c \
 *       --func func_02037928 --addr 0x02037928 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *func_0203D788(void);
extern char *func_0203D798(void);
extern void  func_02037858(void);
extern void  func_02038924(void);
extern void  func_02037288(u16 a0, u16 a1, u32 a2);

extern u8 g_020A7A20[];

u32 func_02037928(u32 a0, u16 a1)
{
    char *b = func_0203D788();
    void (*f1)(void *);
    u32 (*f2)(u32, u32);
    void (*f3)(void *);
    u32 res;
    u32 flag;
    char *a;
    u16 val;

    f1 = *(void (**)(void *))(*(char **)(b + 0x340) + 0x3C);
    f1(func_02037858);

    f2 = *(u32 (**)(u32, u32))(*(char **)(b + 0x340) + 0x44);
    res = f2(a0, 0);

    if (res == 1) {
        f3 = *(void (**)(void *))(*(char **)(b + 0x340) + 0x68);
        f3(func_02038924);

        if (*(u8 *)(b + 0x64) != 0 && *(u16 *)(b + 0x6C) != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = *(u16 *)(a + 0x56);
        func_02037288(a1, val, flag);

        g_020A7A20[1] = 4;
    }

    return res;
}

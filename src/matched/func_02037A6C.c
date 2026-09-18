/*
 * function: func_02037A6C
 * address:  0x02037A6C
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_02038924   0x02038924  arm
 *   func_02037288   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037A6C.c \
 *       --func func_02037A6C --addr 0x02037A6C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *func_0203D788(void);
extern char *func_0203D798(void);
extern void  func_02038924(void);
extern void  func_02037288(u16 a0, u16 a1, u32 a2);
extern u8    g_020A7A20[];

void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3)
{
    char *b = func_0203D788();
    char *a = func_0203D798();
    void (*f1)(void *);
    u32 flag;
    u16 val;
    void (*f2)(u32, u32, u32, u32, u32);

    f1 = *(void (**)(void *))(*(char **)(b + 0x340) + 0x68);
    f1(func_02038924);

    if (a0 != 0) {
        if (*(u8 *)(b + 0x64) != 0 && *(u16 *)(b + 0x6C) != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = *(u16 *)(a + 0x56);
        func_02037288(a2, val, flag);

        g_020A7A20[1] = 4;
    }

    f2 = *(void (**)(u32, u32, u32, u32, u32))(*(char **)(b + 0x340) + 0x48);
    f2(a0, a1, 0, 0, a3);
}

/*
 * function: func_02037894
 * address:  0x02037894
 * packet:   pkt_02037894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   func_0203D788   0x0203D788  arm
 *   func_0203781C   0x0203781C  arm
 *   func_020387A0   0x020387A0  arm
 *   func_02037288   0x02037288  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037894.c \
 *       --func func_02037894 --addr 0x02037894 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *func_0203D798(void);
extern char *func_0203D788(void);
extern void  func_0203781C(void);
extern void  func_020387A0(void);
extern void  func_02037288(u16 a0, u16 a1, u32 a2);

void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    u32 flag;
    u16 val;
    void (*f1)(void *);
    void (*f2)(void *);
    void (*f3)(u32, u32);

    *(u8 *)(a + 0x66) = a0;

    f1 = *(void (**)(void *))(*(char **)(b + 0x340) + 0x3C);
    f1(func_0203781C);

    f2 = *(void (**)(void *))(*(char **)(b + 0x340) + 0x68);
    f2(func_020387A0);

    if (*(u8 *)(b + 0x64) != 0 && *(u16 *)(b + 0x6C) != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    a = func_0203D798();
    val = *(u16 *)(a + 0x56);
    func_02037288(a1, val, flag);

    f3 = *(void (**)(u32, u32))(*(char **)(b + 0x340) + 0x40);
    f3(a2, a3);
}

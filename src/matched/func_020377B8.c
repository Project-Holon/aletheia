/*
 * function: func_020377B8
 * address:  0x020377B8
 * packet:   pkt_020377B8
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
 *   func_02037288   0x02037288  arm
 *   func_02037680   0x02037680  arm
 *   func_020377AC   0x020377AC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020377B8.c \
 *       --func func_020377B8 --addr 0x020377B8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *func_0203D798(void);
extern char *func_0203D788(void);
extern void  func_02037288(u32 a0, u16 a1, u32 a2);
extern void  func_02037680(u32 a0);
extern void  func_020377AC(void);

u32 func_020377B8(u8 arg0)
{
    u32 zero;
    char *a = func_0203D798();
    char *b = func_0203D788();
    u16 val;
    void (*f)(void *);

    *(u8 *)(a + 0x66) = arg0;
    f = *(void (**)(void *))(*(char **)(b + 0x340) + 0x68);
    f(func_020377AC);

    zero = 0;
    val = *(u16 *)(a + 0x56);
    func_02037288(0x80, val, zero);

    func_02037680(zero);
    func_02037680(1);
    func_02037680(2);

    return 1;
}

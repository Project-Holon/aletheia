/*
 * function: func_020379C8
 * address:  0x020379C8
 * packet:   pkt_02037288
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
 *   func_02037858   0x02037858  arm
 *   func_02038924   0x02038924  arm
 *   func_02037288   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *
 * Context teardown through three vtable slots at +0x3c, +0xbc and +0x68 of the
 * object the context's word at +0x340 names.  The first and third are handed a
 * function address as their argument (0x02037858 and 0x02038924), which is why
 * the pool holds two code pointers; the +0xbc slot's answer decides whether the
 * rest runs, and the byte at +1 of the object at 0x020A7A20 is set to 4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020379C8.c \
 *       --func func_020379C8 --addr 0x020379C8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *func_0203D788(void);
extern char *func_0203D798(void);
extern void  func_02037858(u32 arg);
extern void  func_02038924(u32 arg);
extern void  func_02037288(u32 a, u16 b, u32 c);
extern u8    g_020A7A20[];

int func_020379C8(u32 p)
{
    int   r;
    char *c = func_0203D788();

    (*(void (**)(u32))(*(char **)(c + 0x340) + 0x3C))((u32)func_02037858);
    r = (*(int (**)(void))(*(char **)(c + 0x340) + 0xBC))();
    if (r == 1) {
        (*(void (**)(u32))(*(char **)(c + 0x340) + 0x68))((u32)func_02038924);
        func_02037288(p, *(u16 *)(func_0203D798() + 0x56), 0);
        g_020A7A20[1] = 4;
    }
    return r;
}

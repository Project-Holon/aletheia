/*
 * function: func_021BA1C0
 * address: 0x021BA1C0
 * packet: pkt_ov218_021BA1C0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_0204E804 0x0204E804 arm
 *   func_02024004 0x02024004 thumb
 */
extern unsigned func_021B61FC(const unsigned char *);
extern void func_021B6200(unsigned char *);
extern int func_021B9924(void);
typedef unsigned int   u32;
extern void func_021B9B78(char *p, u32 id);
extern int func_0204E804(void);
extern int func_02024004(int);
int func_021BA1C0(unsigned char *task, char *ctx)
{
    switch (func_021B61FC(task)) {
    case 0:
        func_021B9924();
advance:
        func_021B6200(task);
        break;
    case 1:
        if (func_0204E804() == 1)
            break;
        if (func_02024004(1) == 0)
            break;
        func_021B9B78(*(void **)(ctx + 0x28), 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}

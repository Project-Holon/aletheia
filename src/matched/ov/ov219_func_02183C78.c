/*
 * function: func_02183C78
 * address: 0x02183C78
 * packet: pkt_ov219_02183C78
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_02183D14 0x02183D14 thumb ov219
 *   func_02185B74 0x02185B74 thumb ov219
 *   func_02183CEC 0x02183CEC thumb ov219
 *   func_0201C4E4 0x0201C4E4 thumb
 */
extern void func_020310C4(void *);
extern int func_02183D14(char *, char *);
extern void func_02185B74(char *);
extern void func_02183CEC(char *);
extern unsigned func_0201C4E4(void *);
int func_02183C78(void *unused, char *state, int unused2, char *ctx)
{
    int result;
    func_020310C4(*(void **)(ctx + 0xc0a4));
    result = func_02183D14(ctx, state);
    if (*(int *)(ctx + 0xc3a4) != 0)
        func_02185B74(ctx);
    func_02183CEC(ctx);
    func_0201C4E4(*(void **)(ctx + 0xc080));
    return result;
}

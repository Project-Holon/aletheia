/*
 * function: func_021FAD74
 * address: 0x021FAD74
 * packet: pkt_ov186_021FAD74
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FADB6..021FADB8 is two zero alignment bytes.
 * symbols:
 *   func_021FB548 0x021FB548 thumb ov186
 */
extern void func_021FB548(void *, short *, short *);
int func_021FAD74(char *ctx)
{
    short x, y;
    int result;
    if (*(int (**)(char *))(ctx + 0x10) != 0) {
        result = (*(int (**)(char *))(ctx + 0x10))(ctx);
        if (result != 0) *(int (**)(char *))(ctx + 0x10) = 0;
        if (*(int **)(ctx + 0x2c) != 0) {
            func_021FB548(*(void **)(ctx + 8), &x, &y);
            (*(int **)(ctx + 0x2c))[0] = x + 80;
            (*(int **)(ctx + 0x2c))[1] = y;
        }
        return result;
    }
    return 1;
}

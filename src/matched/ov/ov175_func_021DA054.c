/*
 * function: func_021DA054
 * address: 0x021DA054
 * packet: pkt_ov175_021DA054
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB3A4 0x021DB3A4 thumb ov175
 *   func_021DB478 0x021DB478 thumb ov175
 *   func_021DBFA4 0x021DBFA4 thumb ov175
 *   func_021DBFB4 0x021DBFB4 thumb ov175
 */
extern void func_021DB3A4(char *, unsigned long, int, unsigned long);
extern int func_021DB478(char *);
extern void func_021DBFA4(char *);
extern int func_021DBFB4(char *);
int func_021DA054(char *ctx)
{
    int result;
    switch (*(int *)(ctx + 0x128)) {
    case 0:
        func_021DB3A4(ctx, -1, 2, *(unsigned long *)(ctx + 0x1464));
        *(int *)(ctx + 0x128) = 1;
        break;
    case 1:
        result = func_021DB478(ctx);
        if (result == 1) {
            if (**(int **)(ctx + 0x1464) != 0) *(int *)(ctx + 0x128) = 4;
            else *(int *)(ctx + 0x128) = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        func_021DBFA4(ctx);
        *(int *)(ctx + 0x128) = 3;
        break;
    case 3:
        result = func_021DBFB4(ctx);
        if (result == 1) *(int *)(ctx + 0x128) = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}

/*
 * file:     unit_0216AB20_p06.c
 * unit:     yes
 * function: func_0216BBCC, func_0216BBDC, func_0216BC2C
 * address:  0x0216BBCC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021AA8A0  0x021AA8A0  data
 *   func_02195E78  0x02195E78  arm  ov009
 *   g_021AA920  0x021AA920  data
 */
extern int func_02195E78(const int *p);
int *func_0216BBCC(int i);
int *func_0216BBDC(int pid, int flag);
void *func_0216BC2C(int i);
extern int g_021AA8A0[];
extern char g_021AA920[];


/*
 * Address of the i-th word of the table.
 */
int *func_0216BBCC(int i)
{
    return &g_021AA8A0[i];
}


/*
 * DWCi_GetGT2ConnectionByProfileID: the connection slot whose peer profile id matches, or null.
 */
int *func_0216BBDC(int pid, int flag)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && pid == *(int *)(func_02195E78((const int *)g_021AA8A0[i]) + 4)) {
            return func_0216BBCC(i);
        }
    }
    return 0;
}


/*
 * Address of the i-th entry of the eight-byte table.
 */
void *func_0216BC2C(int i)
{
    return g_021AA920 + i * 8;
}

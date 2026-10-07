/*
 * file:     unit_0216AB20_p05.c
 * unit:     yes
 * function: func_0216BB6C, func_0216BB98
 * address:  0x0216BB6C
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
 *   MIi_CpuClear32     0x02082A7C  arm
 *   g_021AA920         0x021AA920  data
 */
extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
int func_0216BB6C(void);
void DWCi_ClearGT2ConnectionList(void);
extern char g_021AA8A0[];
extern char g_021AA920[];


/*
 * Returns the index of the first null word in the 0x20-entry word table, or
 * -1 when the whole table is occupied.
 */
int func_0216BB6C(void)
{
    int i;

    for (i = 0; i < 0x20; i++)
        if (*(int *)(g_021AA8A0 + i * 4) == 0) return i;
    return -1;
}


void DWCi_ClearGT2ConnectionList(void)
{
    MIi_CpuClear32(0, g_021AA8A0, 0x80);
    MIi_CpuClear32(0, g_021AA920, 0x100);
}

/*
 * file:     net_whpipe_p08.c
 * unit:     yes
 * function: func_021779F4, func_02177A34, func_02177A74, func_02177A94, func_02177AA8
 * address:  0x021779F4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   func_021795A4  0x021795A4  thumb  ov014
 *   func_02177ACC  0x02177ACC  thumb  ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02178E38  0x02178E38  thumb  ov014
 *   ctrdgi_task_work 0x021797a4 data
 */
#include "../../matched/include/G_W.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern unsigned short func_021795A4(void);
extern unsigned int func_02177ACC(void);
extern int func_02178E4C(void);
extern u16 func_02178E38(void);
int func_021779F4(void);
int func_02177A34(u16 n);
int func_02177A74(void);
int CTRDGi_IsTaskAvailable(void);
int func_02177AA8(void);
extern struct W *g_021797A4;
extern void *ctrdgi_task_work;


int func_021779F4(void)
{
    if (((u8 *)g_021797A4) == 0)
        return 0;
    if (func_021795A4() == 0 && func_02177ACC() == 0)
        return 0;
    if (func_02178E4C() == 4 || func_02178E4C() == 5)
        return 1;
    return 0;
}


int func_02177A34(u16 n)
{
    if (((u8 *)g_021797A4) == 0)
        return 0;
    if (func_02178E4C() != 4 && func_02178E4C() != 5)
        return 0;
    if (func_02178E38() & (1 << n))
        return 1;
    return 0;
}

/*
 * evidence: original truncates the index to u16 before calling A34; extern follows caller width.
 * extent: trailing two zero bytes are alignment padding.
 */
int func_02177A74(void) { int count = 0; int i = 0; for (; i < 8; i++) { if (func_02177A34(i) != 0) count++; } return count; }


int CTRDGi_IsTaskAvailable(void)
{
    return ctrdgi_task_work != 0;
}

int func_02177AA8(void) { if (g_021797A4 != 0) { if (func_02178E4C() == 1) return 1; return 0; } return 1; }

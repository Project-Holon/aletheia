/*
 * file:     unit_02075C38_p02.c
 * unit:     yes
 * function: func_02075DA0, func_02075DB0, func_02075DC8, func_02075DD8
 * address:  0x02075DA0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   s_data_0215019C  0x0215019C  data
 *   func_02088234   0x02088234  arm
 *   g_0215019C 0x0215019C data
 *   cardi_common        0x02150200  data
 */
struct CARDiCommand {
    int result;
};

struct CARDiCommon {
    struct CARDiCommand *cmd;
};

extern void func_02088234(void);
extern void g_0215019C(void);
void *func_02075DA0(void);
void CARD_CheckEnabled(void);
asm void func_02075DC8(void);
int CARD_GetResultCode(void);
extern void *s_data_0215019C;
extern struct CARDiCommon cardi_common;


void *func_02075DA0(void)
{
    return s_data_0215019C;
}


void CARD_CheckEnabled(void)
{
    if (func_02075DA0() != 0)
        return;
    func_02088234();
}

asm void func_02075DC8(void)
{
    ldr r1, =g_0215019C
    str r0, [r1]
    bx lr
}


int CARD_GetResultCode(void)
{
    return cardi_common.cmd->result;
}

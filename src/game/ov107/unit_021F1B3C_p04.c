/*
 * file:     unit_021F1B3C_p04.c
 * unit:     yes
 * function: func_021F2ED4, func_021F2EE8, func_021F2F04
 * address:  0x021F2ED4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

typedef int BOOL;

extern void MBi_CommChangeParentStateCallbackOnly(u16 aid, int state, void *e_stat);
u16 MBi_calc_nextsendblock(unsigned long next_block, unsigned long next_block_req);
BOOL IsChildAidValid(u16 child_aid);
void MBi_CommCallParentError(u16 aid, u16 errcode);


u16 MBi_calc_nextsendblock(unsigned long next_block, unsigned long next_block_req)
{
    if (next_block_req <= next_block)
        next_block_req = next_block;
    return next_block_req;
}


BOOL IsChildAidValid(u16 child_aid)
{
    if (child_aid >= 1 && child_aid <= 15)
        return 1;
    return 0;
}


void MBi_CommCallParentError(u16 aid, u16 errcode)
{
    u16 e_stat;

    e_stat = errcode;
    MBi_CommChangeParentStateCallbackOnly(aid, 0xD, &e_stat);
}

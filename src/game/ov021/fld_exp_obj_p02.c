/*
 * file:     fld_exp_obj_p02.c
 * unit:     yes
 * function: func_021BE480, func_021BE4A4, func_021BE4B4
 * address:  0x021BE480
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb
 */
#include "../../matched/include/Obj12119.h"
#include "../../matched/include/Obj20142.h"
#include "../../matched/include/Obj20143.h"

typedef unsigned int u32;

int func_021BE480(char *p, unsigned i, int j);
void func_021BE4A4(char *p, int i, int j, int v);
void func_021BE4B4(char *p, int i, int j, int v);


/*
 * Unlabelled leaf in ov021, immediately after func_021BE418's epilogue
 * (0x021BE47C) and before the next traced function at 0x021BE4A4; it saves
 * nothing, so disasm.py prints it inside the pool/.word run.  It is the
 * blocker target of ov010's func_0216C280 (pkt_0216C280), reached across the
 * ov010/ov021 overlay pair.  Element lookup: stride 0x10, null when the +8
 * slot is zero or the index is out of range, else base + index*0x44 + 8.
 */
int func_021BE480(char *p, unsigned i, int j)
{
    char *e = p + i * 0x10;

    if (((struct Obj12119 *)e)->f8 == 0)
        return 0;
    if (i >= 4)
        return 0;
    return ((struct Obj12119 *)e)->fC + j * 0x44 + 8;
}


void func_021BE4A4(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20142 *)e)->fC + j * 0x44) = v;
}


void func_021BE4B4(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20143 *)e)->fC + j * 0x44 + 4) = v;
}

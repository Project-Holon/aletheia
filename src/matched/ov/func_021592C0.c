/*
 * function: SCRIPT_WORK_CmdDebugStack
 * address:  0x021592C0
 * packet:   pkt_021592C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_PopStack  0x02011398  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 VM_PopStack(struct Ring *r);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);

int SCRIPT_WORK_CmdDebugStack(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = VM_PopStack((struct Ring *)a0);
loc_021592CA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_021592D2:
a0 = 0;
    return a0;}

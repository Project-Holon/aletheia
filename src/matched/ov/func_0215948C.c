/*
 * function: SCRIPT_WORK_CmdDiv
 * address:  0x0215948C
 * packet:   pkt_0215948C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_PopStack  0x02011398  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   VM_PushStack  0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 VM_PopStack(struct Ring *r);
extern int func_0209C2B0();
extern int VM_PushStack();

int SCRIPT_WORK_CmdDiv(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = VM_PopStack((struct Ring *)a0);
loc_02159494:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = VM_PopStack((struct Ring *)a0);
loc_0215949C:
a1 = t4 + 0;
    a0 = func_0209C2B0(a0, a1);
loc_021594A2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = VM_PushStack(a0, a1);
loc_021594AA:
a0 = 0;
    return a0;}

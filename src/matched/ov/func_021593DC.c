/*
 * function: SCRIPT_WORK_CmdPushConst
 * address:  0x021593DC
 * packet:   pkt_021593DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   VM_PushStack  0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern int VM_PushStack();

int SCRIPT_WORK_CmdPushConst(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = VM_GetU16((struct Stream *)a0);
loc_021593E4:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = VM_PushStack(a0, a1);
loc_021593EC:
a0 = 0;
    return a0;}

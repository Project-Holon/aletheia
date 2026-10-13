/*
 * function: SCRIPT_WORK_CmdLoadWorkConst
 * address:  0x02159894
 * packet:   pkt_02159894
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);

int SCRIPT_WORK_CmdLoadWorkConst(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a0 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215989C:
a0 = t5 + 0;
    a0 = VM_GetU16((struct Stream *)a0);
loc_021598A4:
*q = a0;
a0 = 0;
    return a0;}

/*
 * function: SCRIPT_WORK_CmdCompareStack
 * address:  0x021594E0
 * packet:   pkt_ov010_021594E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_PopStack  0x02011398  thumb
 *   VM_GetU16  0x02011330  thumb
 *   VM_PushStack  0x0201137C  thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
struct Ring;
struct Stream;
extern u32 VM_PopStack(struct Ring *r);
extern u16 VM_GetU16(struct Stream *s);
extern void VM_PushStack(struct Ring *r, u32 v);

int SCRIPT_WORK_CmdCompareStack(int p)
{
    u32 a = VM_PopStack((struct Ring *)p);
    u32 b = VM_PopStack((struct Ring *)p);
    int r;
    switch (VM_GetU16((struct Stream *)p)) {
    case 0: r = (b < a) ? 1 : 0; break;
    case 1: r = (b == a) ? 1 : 0; break;
    case 2: r = (b > a) ? 1 : 0; break;
    case 3: r = (b <= a) ? 1 : 0; break;
    case 4: r = (b >= a) ? 1 : 0; break;
    case 5: r = (b != a) ? 1 : 0; break;
    case 6: r = (b == 1 || a == 1) ? 1 : 0; break;
    case 7: r = (b == 1 && a == 1) ? 1 : 0; break;
    default: r = 0; break;
    }
    VM_PushStack((struct Ring *)p, r);
    return 0;
}

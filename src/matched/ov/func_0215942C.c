/*
 * function: func_0215942C
 * address:  0x0215942C
 * packet:   pkt_0215942C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * One arm9 getter read twice, folded with '+', written back
 * through the arm9 setter.
 *
 * symbols:
 *   VM_PopStack   0x02011398  thumb
 *   VM_PushStack   0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 VM_PopStack(struct Ring *r);
extern void VM_PushStack(struct Ring *r, u32 v);

int func_0215942C(void *a0)
{
    int v = VM_PopStack(a0);
    int w = VM_PopStack(a0);

    VM_PushStack(a0, w + v);

    return 0;
}

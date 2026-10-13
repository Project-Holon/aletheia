/*
 * function: func_02159404
 * address:  0x02159404
 * packet:   pkt_02159404
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_PopStack  0x02011398  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 VM_PopStack(struct Ring *r);
extern u16 *func_02159AE8(void *a0, void *a1);

int func_02159404(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    a0 = VM_PopStack((struct Ring *)a0);
loc_0215940E:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159418:
*q = t4;
a0 = 0;
    return a0;}

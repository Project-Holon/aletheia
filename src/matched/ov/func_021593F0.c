/*
 * function: func_021593F0
 * address:  0x021593F0
 * packet:   pkt_021593F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   VM_PushStack  0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int func_02159B10(void *, void *);
extern int VM_PushStack();

int func_021593F0(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021593F8:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = VM_PushStack(a0, a1);
loc_02159400:
a0 = 0;
    return a0;}

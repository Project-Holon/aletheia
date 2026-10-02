/*
 * function: func_0216A264
 * address:  0x0216A264
 * packet:   pkt_0216A264
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021D1164(u32 heap, u32 v);
extern int func_021D11B0();

int func_0216A264(int a0, int a1)
{
    int t4;
    void *p;

t4 = a0 + 0;
a0 = *(u16 *)((char *)t4 + 0x10);
a1 = *(int *)((char *)t4 + 8);
    p = func_021D1164(a0, a1);
loc_0216A270:
a1 = *(int *)((char *)t4 + 0x18);
*(void **)((char *)a1 + 0x48) = p;
a0 = *(int *)((char *)t4 + 0x18);
p = *(void **)((char *)a0 + 0x48);
    a0 = func_021D11B0(p, a1);
loc_0216A27C:
    return a0;}

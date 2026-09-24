/*
 * function: func_02155F24
 * address:  0x02155F24
 * packet:   pkt_02155F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   func_021F675C  0x021F675C  thumb
 *   func_021FD904  0x021FD904  thumb
 *   func_021FD938  0x021FD938  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021F675C();
extern int func_021FD904();
extern int func_021FD938();

void func_02155F24(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x18);
a1 = 4;
    a0 = func_021F675C(a0, a1);
loc_02155F30:
*(int *)((char *)t4 + 0x3c) = a0;
a0 = *(int *)((char *)t4 + 0x14);
    if (a0 == 0) goto loc_02155F48;
loc_02155F38:
a0 = *(int *)((char *)t4 + 8);
a0 = *(int *)((char *)a0 + 4);
    a0 = func_021FD904(a0);
loc_02155F40:
a0 = *(int *)((char *)t4 + 8);
a0 = *(int *)((char *)a0 + 4);
    a0 = func_021FD938(a0);
loc_02155F48:
    return;}

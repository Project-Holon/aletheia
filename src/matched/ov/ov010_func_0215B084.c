/*
 * function: func_0215B084
 * address: 0x0215B084
 * packet: pkt_ov010_0215B084
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_0201293C 0x0201293C thumb
 *   func_02007A68 0x02007A68 thumb
 */
typedef unsigned short u16;
extern int func_02159B10(int,int);
extern void *func_0215A5E4(void *a0);
extern int func_0201293C(void *);
extern void func_02007A68(int,int);
int func_0215B084(int a,int b)
{
    int k = func_02159B10(a,b);
    int p = func_0201293C(func_0215A5E4((void *)b));
    if ((u16)(k + 0xFFFF) <= 1) func_02007A68(p,k);
    return 0;
}

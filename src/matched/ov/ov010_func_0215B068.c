/*
 * function: func_0215B068
 * address: 0x0215B068
 * packet: pkt_ov010_0215B068
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_02014314 0x02014314 thumb
 */
typedef unsigned short u16;
extern void *func_0215A5E4(void *a0);
extern char *func_0201296C(int);
extern void func_02014314(char *,int);
int func_0215B068(int a,int b)
{
    func_02014314(func_0201296C(func_0215A5E4((void *)b)), 0x963);
    return 0;
}

/*
 * function: func_0215C558
 * address: 0x0215C558
 * packet: pkt_ov010_0215C558
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_020127A4 0x020127A4 thumb
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 */
typedef unsigned short u16;
extern void *func_0215A5E4(void *a0);
extern int func_020127A4(int);
extern int func_02159B10(int,int);
extern int func_02012F08(int);
extern void func_0200C278(int,int);
int func_0215C558(int a,int b)
{
    void *p = func_0215A5E4((void *)b);
    int k;
    func_020127A4(p);
    k = func_02159B10(a,b);
    func_0200C278(func_02012F08(p),k);
    return 0;
}

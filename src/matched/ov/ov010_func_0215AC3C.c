/*
 * function: func_0215AC3C
 * address: 0x0215AC3C
 * packet: pkt_ov010_0215AC3C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C234 0x0200C234 thumb
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(int,int);
extern int func_02159B10(int,int);
extern int func_0215A5E4(int);
extern int func_02012F08(int);
extern int func_0200C234(int,int);
int func_0215AC3C(int a,int b)
{
    u16 *out = func_02159AE8(a,b);
    int k = func_02159B10(a,b);
    *out = func_0200C234(func_02012F08(func_0215A5E4(b)),k);
    return 0;
}

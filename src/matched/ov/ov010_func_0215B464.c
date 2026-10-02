/*
 * function: func_0215B464
 * address: 0x0215B464
 * packet: pkt_ov010_0215B464
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   d_02171160 0x02171160 data a2
 */
typedef unsigned short u16;
extern int func_02159B10(int,int);
extern u16 *func_02159AE8(void *a0, void *a1);
extern const u16 d_02171160[];
int func_0215B464(int a,int b)
{
    int k = func_02159B10(a,b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = d_02171160[k];
    return 0;
}

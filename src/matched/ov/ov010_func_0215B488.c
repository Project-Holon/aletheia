/*
 * function: func_0215B488
 * address: 0x0215B488
 * packet: pkt_ov010_0215B488
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   d_02171170 0x02171170 data a2
 */
typedef unsigned short u16;
extern unsigned int func_02159B10(void *,void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern const u16 d_02171170[];
int func_0215B488(int a,int b)
{
    int k = func_02159B10((void *)a,(void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = d_02171170[k];
    return 0;
}

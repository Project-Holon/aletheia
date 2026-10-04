/*
 * function: func_0215B7E8
 * address: 0x0215B7E8
 * packet: pkt_ov010_0215B7E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215B4DC 0x0215B4DC thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *,void *);
extern int func_0215B4DC(int,int,int);
int func_0215B7E8(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int k = func_02159B10((void *)a,(void *)b);
    if (func_0215B4DC(b,k,0x4C) != 0) *out = 0x28A; else *out = func_0215B4DC(b,k,5);
    return 0;
}

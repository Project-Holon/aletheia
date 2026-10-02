/*
 * function: func_0215B3DC
 * address: 0x0215B3DC
 * packet: pkt_ov010_0215B3DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012A44 0x02012A44 thumb
 *   func_0216EFA8 0x0216EFA8 thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_02012A44(void *);
extern int func_0216EFA8(int,int);
int func_0215B3DC(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int z = 1;
    if (func_0216EFA8(func_02012A44(func_0215A5E4((void *)b)),1) == 1) *out = 0; else *out = z;
    return 0;
}

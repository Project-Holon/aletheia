/*
 * function: func_0215C584
 * address: 0x0215C584
 * packet: pkt_ov010_0215C584
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
 *   func_0200C29C 0x0200C29C thumb
 */
typedef unsigned short u16;
extern void *func_0215A5E4(void *a0);
typedef unsigned int   u32;
struct Blk34;
struct SaveBlock;
extern void *func_020127A4(struct SaveBlock *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_02012F08(int *p);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
int func_0215C584(int a,int b)
{
    void *p = func_0215A5E4((void *)b);
    int k;
    func_020127A4(p);
    k = func_02159B10((void *)a,(void *)b);
    func_0200C29C(func_02012F08(p),k);
    return 0;
}

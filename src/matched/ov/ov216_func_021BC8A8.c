/*
 * function: func_021BC8A8
 * address: 0x021BC8A8
 * packet: pkt_ov216_021BC8A8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 */
extern void func_0204B3DC(void *,int);
extern void func_0204B3B4(void *);
extern void func_020452E8(void *);
extern void func_0202DC08(void *);
void func_021BC8A8(char *p)
{
    int i=0,j;
    char *base=p+0x15c;
    for(;i<2;i++) {
        char *q=base+i*128;
        func_0204B3DC(*(void **)(q+0x78),0); func_0204B3B4(*(void **)(q+0x78));
        func_0204B3DC(*(void **)(q+0x74),0); func_0204B3B4(*(void **)(q+0x74));
        func_020452E8(*(void **)(q+0x60));
        for(j=0;j<2;j++) func_020452E8(*(void **)(q+0x40+j*16));
        for(j=0;j<4;j++) func_020452E8(*(void **)(q+j*16));
        func_020452E8(*(void **)(q+0x70));
    }
    func_0202DC08(*(void **)(p+0x158));
}

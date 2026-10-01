/*
 * function: func_021D99F0
 * address: 0x021D99F0
 * packet: pkt_ov129_021D99F0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA3D0 0x021DA3D0 thumb ov129
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 * Extent ends with two bytes of zero alignment padding.
 */

extern void func_0204B3B4(int);
extern void func_021DA3D0(char *);
extern void func_020452E8(int);
extern void func_0204ADA4(int);
extern void func_0204A8D4(int);
extern void func_0204AFD8(int);
extern void func_0204B1CC(int);
extern void func_0204A5AC(void);
void func_021D99F0(char *p)  {
    int i;
    char *q;
    for(i=0;i<*(int *)(p+0x23c);i++) func_0204B3B4(*(int *)(p+i*28+12));
    for(i=0;i<2;i++)  {
        q=p+i*28;
        func_0204B3B4(*(int *)(q+0x15c));
        func_0204B3B4(*(int *)(q+0x1e8));
    }
    for(i=0;i<3;i++) func_0204B3B4(*(int *)(p+i*28+0x194));
    func_021DA3D0(p);
    func_020452E8(*(int *)(p+0x310));
    for(i=0;i<3;i++)  {
        q=p+i*4;
        func_0204ADA4(*(int *)(q+0x260));
        func_0204A8D4(*(int *)(q+0x26c));
        func_0204AFD8(*(int *)(q+0x284));
    }
    func_0204B1CC(*(int *)(p+0x25c));
    func_0204A5AC();
}

/*
 * function: func_021DB3E8
 * address: 0x021DB3E8
 * packet: pkt_ov121_021DB3E8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021D9A40 0x021D9A40 thumb ov121
 */
extern void func_02040DA8(int,int,int);
extern void func_0204B3B4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_0204ADA4(void *);
extern void func_020452E8(void *);
extern void func_021D9A40(void *);
void func_021DB3E8(char *p)
{
    int i;
    func_02040DA8(2,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+0xaf4+i*4));
    func_0204B3B4(*(void **)(p+0xaf0));
    func_0204B3B4(*(void **)(p+0xaec));
    func_0204A8D4(*(void **)(p+0xafc));
    func_0204AFD8(*(void **)(p+0xb00));
    func_0204ADA4(*(void **)(p+0xb04));
    func_021D9A40(*(void **)(p+0xab4));
    *(void **)(p+0xab4)=0;
    func_0204ADA4(*(void **)(p+0xba8));
    for(i=0;i<8;i++) func_020452E8(*(void **)(p+0xb08+i*4));
}

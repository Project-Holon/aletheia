/*
 * function: func_021D53D0
 * address: 0x021D53D0
 * packet: pkt_ov123_021D53D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021D4A64 0x021D4A64 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
extern int func_020221A4(void);
extern void func_0204B3B4(void *);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_02030EAC(void *);
extern void func_0204B1CC(void *);
extern void func_0204A5AC(void);
extern void func_0202F038(void *);
extern void func_0201CE48(void *);
extern void func_02027858(void *);
extern void func_021D4A64(char *);
extern void func_020307B0(void *);
extern void func_02028604(void *);
extern void func_020403F4(int);
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_020452E8(void *);
extern void func_02031140(void *);
extern void func_02027FD8(void *);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(void *);
extern void func_020306F0(int);
int func_021D53D0(void *a,int b,u8 *out,char *p)
{
    int i;
    if(!func_020221A4()) return 0;
    for(i=0;i<3;i++) func_0204B3B4(*(void **)(p+i*4+0x2a0));
    func_0204ADA4(*(void **)(p+0x290));
    func_0204A8D4(*(void **)(p+0x294));
    func_0204AFD8(*(void **)(p+0x298));
    func_02030EAC(*(void **)(p+0x2b0));
    func_0204B1CC(*(void **)(p+0x2ac)); func_0204A5AC();
    if(*(void **)(p+0x288)) { func_0202F038(*(void **)(p+0x288)); *(void **)(p+0x288)=0; }
    if(*(void **)(p+0x228)) func_0201CE48(*(void **)(p+0x228));
    if(*(void **)(p+0x238)) { func_02027858(*(void **)(p+0x238)); *(void **)(p+0x238)=0; }
    func_021D4A64(p);
    *(int *)(out+0x1c8)=*(int *)(p+8);
    func_020307B0(*(void **)(p+0x280)); func_020307B0(*(void **)(p+0x284));
    func_02028604(*(void **)(p+0x22c)); func_020403F4(5);
    func_0201C6EC(*(void **)(p+0x234)); func_0201C4C0(*(void **)(p+0x234));
    if(*(void **)(p+0x224)) func_020452E8(*(void **)(p+0x224));
    func_02031140(*(void **)(p+0x230)); func_02027FD8(*(void **)(p+0x254));
    func_020450C8(); func_0203F9B4(); func_020315D4(a); func_020306F0(31);
    return 1;
}

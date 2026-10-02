/*
 * function: func_021D872C
 * address: 0x021D872C
 * packet: pkt_ov129_021D872C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * The caller supplies the pointer through the legacy argless 02021540 thunk.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_021D99F0 0x021D99F0 thumb ov129
 *   func_020450C8 0x020450C8 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02049238 0x02049238 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02045808 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
extern void func_02030EAC(void *);
extern void func_0201D83C(void *);
extern void func_021D99F0(char *);
extern void func_020450C8(void);
extern void func_020434DC(unsigned,unsigned);
extern void func_02043598(unsigned,unsigned);
extern void func_020403F4(unsigned);
extern void func_0203F9B4(void);
extern void func_020215A0(void *,unsigned);
extern void func_02021540(void *);
extern void func_02049238(void *);
extern void func_02051C6C(void *);
extern void func_02045808(void *);
extern void func_020315D4(void *);
extern void func_020306F0(void *);
int func_021D872C(void *a,int b,int c,char *p)
{
    func_02030EAC(*(void **)(p+0x318));
    func_0201D83C(*(void **)(p+0x314));
    func_021D99F0(p);
    func_020450C8();
    func_020434DC(1,0); func_020434DC(2,0); func_020434DC(4,0); func_020434DC(8,0);
    func_02043598(1,0); func_02043598(2,0); func_02043598(4,0); func_02043598(8,0);
    func_020403F4(1); func_020403F4(2); func_020403F4(3); func_020403F4(4);
    func_020403F4(5); func_020403F4(6); func_020403F4(7);
    func_0203F9B4();
    func_020215A0(*(void **)(p+0x290),0);
    func_02021540(*(void **)(p+0x290));
    func_02049238(*(void **)(p+0x258));
    func_02051C6C(*(void **)(p+0x294));
    if(c==0) func_02045808(*(void **)(p+0x348));
    func_020315D4(a);
    func_020306F0((void *)50);
    return 1;
}

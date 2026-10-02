/*
 * function: func_0220C27C
 * address: 0x0220C27C
 * packet: pkt_ov197_0220C27C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(unsigned,unsigned,unsigned,unsigned,u16);
extern int func_0204ABF0(unsigned,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(unsigned,unsigned,unsigned,unsigned);
extern void func_020216B4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049238(unsigned);
void func_0220C27C(char *p)
{
    void *arc = func_020490F4(99,(*(u16 *)(*(char **)p+0xc)&0x7fff)|0x8000);
    *(int *)(p+0x560)=func_0204A6C8(arc,13,1,1,*(u16 *)(*(char **)p+0xc));
    *(int *)(p+0x584)=func_0204ABF0(arc,14,1,224,*(u16 *)(*(char **)p+0xc));
    *(int *)(p+0x590)=func_0204AF28(arc,15,16,*(u16 *)(*(char **)p+0xc));
    func_020216B4(*(void **)(p+8),arc,14,*(u16 *)(*(char **)p+0xc),3,32,112);
    func_02049238(arc);
}

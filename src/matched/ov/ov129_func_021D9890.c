/*
 * function: func_021D9890
 * address: 0x021D9890
 * packet: pkt_ov129_021D9890
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02021640 0x02021640 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02021640(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
void func_021D9890(char *p)
{
    void *pal=*(void **)(p+0x290);
    void *arc=*(void **)(p+0x258);
    func_02049658(arc,6,1,0,0,0,50);
    func_020498F4(arc,10,1,0,0,0,50);
    func_02021640(pal,59,1,50,0,64,0);
    func_02049658(arc,7,5,0,0,0,50);
    func_020498F4(arc,11,5,0,0,0,50);
    func_02049B68(arc,2,4,0,0,50);
    *(int *)(p+0x260)=func_0204ABF0(arc,0,0,0,50);
    *(int *)(p+0x26c)=func_0204A6C8(arc,5,0,0,50);
    *(int *)(p+0x284)=func_0204AF28(arc,12,15,50);
    *(int *)(p+0x268)=func_0204ABF0(arc,4,0,32,50);
    *(int *)(p+0x274)=func_0204A6C8(arc,9,0,0,50);
    *(int *)(p+0x28c)=func_0204AF28(arc,14,17,50);
    *(int *)(p+0x264)=func_0204ABF0(arc,3,0,64,50);
    *(int *)(p+0x270)=func_0204A6C8(arc,8,0,0,50);
    *(int *)(p+0x288)=func_0204AF28(arc,13,16,50);
    func_0201F5BC(4,1,11,0,50);
    func_02049B40(23,5,4,384,32,50);
}

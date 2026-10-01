/*
 * function: func_021C4A48
 * address: 0x021C4A48
 * packet: pkt_ov208_021C4A48
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys; struct Descriptor; struct U16Vec; struct Rec;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *p);
extern void func_02045808(struct U16Vec *p);
extern void func_02045C04(struct Rec *p);
extern void func_020307B0(void *p);
void func_021C4A48(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+0x568)=0;
        func_0201C6EC(*(struct PrintSys **)(p+i*4+0x57c));
        func_020452E8(*(struct Descriptor **)(p+i*4+0x554));
    }
    for(i=0;i<6;i++)func_02045808(*(struct U16Vec **)(p+i*4+0x59c));
    func_02045C04(*(struct Rec **)(p+0x590));
    func_02045C04(*(struct Rec **)(p+0x598));
    func_020307B0(*(void **)(p+0x594));
}

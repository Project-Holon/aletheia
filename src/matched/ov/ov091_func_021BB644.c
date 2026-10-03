/*
 * function: func_021BB644
 * address: 0x021BB644
 * packet: pkt_ov091_021BB644
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_0202865C 0x0202865C thumb
 *   func_02045334 0x02045334 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020310C4(u32);
extern void func_020286C4(u32,u32,u32);
extern int func_02028484(u8 *,u32);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32);
extern void func_0201CE48(u32);
extern void func_02045808(u32);
extern u32 func_02045770(u32);
extern void func_0202865C(u32,u32,int);
extern void func_02045334(u32);
extern int func_0201C6C4(int,u32);
extern void func_02045374(u32);
extern u8 func_02045730(u32);
extern void func_02041B6C(u32 bit);
extern u32 func_0202EE8C(u32,u32,int,int,u16);
extern void func_0201C4E4(int);
#define W(o) (*(u32 *)(s+(o)))
void func_021BB644(u8 *p,u8 *s)
{
    func_020310C4(W(8));
    if (W(0xc) != 0) {
        func_020286C4(W(0x14),W(0xc),W(4));
        if (func_02028484(s+0x18,W(0xc)) == 1) {
            if (W(0x20) == 0 || (func_020362DC() & 3) != 0 || func_02035C60() == 1) {
                if (W(0x20) == 1) func_020061E4(0x547);
                func_0201CE48(W(0xc));
                W(0xc)=0;
                func_02045808(W(0x10));
            } else {
                func_0202865C(W(0x14),func_02045770(W(4)),15);
                func_02045334(W(4));
            }
        }
    }
    if (W(0x24) == 1 && func_0201C6C4(W(0x28),func_02045770(W(4))) == 0) {
        u32 t=W(4);
        W(0x24)=0;
        func_02045334(t);
        func_02045374(t);
        func_02041B6C(func_02045730(t));
        if (W(0x30) == 1) {
            W(0x30)=0;
            W(0x34)=func_0202EE8C(W(8),W(4),15,16,*(u16 *)p);
        }
    }
    func_0201C4E4(W(0x28));
}

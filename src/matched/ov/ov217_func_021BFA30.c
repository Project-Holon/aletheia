/*
 * function: func_021BFA30
 * address:  0x021BFA30
 * packet:   pkt_ov217_021BFA30
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   func_021BFC50 0x021BFC50 thumb ov217
 *   func_021BFB0C 0x021BFB0C thumb ov217
 *   func_021BFBDC 0x021BFBDC thumb ov217
 *   func_021BFE80 0x021BFE80 thumb ov217
 *   func_021BFEE4 0x021BFEE4 thumb ov217
 *   func_021BFB60 0x021BFB60 thumb ov217
 *   func_021BFBB8 0x021BFBB8 thumb ov217
 *   func_021BFB30 0x021BFB30 thumb ov217
 *   func_021C019C 0x021C019C thumb ov217
 *   func_021C0384 0x021C0384 thumb ov217
 *   func_021C03EC 0x021C03EC thumb ov217
 *   func_021C04B0 0x021C04B0 thumb ov217
 *   func_021C07B0 0x021C07B0 thumb ov217
 *   func_021C0820 0x021C0820 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_020056BC(void);
extern void func_021BFC50(void *p);
extern void func_021BFB0C(void *p);
extern void func_021BFBDC(void *p);
extern void func_021BFE80(void *p);
extern void func_021BFEE4(void *p);
extern void func_021BFB60(void *p);
extern void func_021BFBB8(void *p);
extern void func_021BFB30(void *p);
extern void func_021C019C(void *p);
extern void func_021C0384(void *p);
extern void func_021C03EC(void *p);
extern void func_021C04B0(void *p);
extern void func_021C07B0(void *p);
extern void func_021C0820(void *p);
void func_021BFA30(char *p)
{
    int i;
    *(u32 *)(p + 0x20) = 0;
    *(u32 *)(p + 0x24) = 0;
    *(u32 *)(p + 0x3dc) = 0;
    *(u32 *)(p + 0x2c) = 0xf;
    *(u32 *)(p + 0x28) = 0;
    *(u32 *)(p + 0x30) = 0;
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x3c4) = 0;
    *(u32 *)(p + 0x3c8) = 0;
    *(u32 *)(p + 0x3cc) = 0;
    *(u32 *)(p + 0x3d0) = 0;
    *(u32 *)(p + 0x3d4) = 0;
    *(u32 *)(p + 0x3d8) = 0;
    *(u8 *)(p + 0x2b8) = 0;
    *(u8 *)(p + 0x2b9) = 0;
    *(u32 *)(p + 0x2cc) = 0;
    *(u32 *)(p + 0x3bc) = func_020056BC();
    *(u8 *)(p + 0x2fc) = 0;
    *(u8 *)(p + 0x2fd) = 0;
    *(u32 *)(p + 0x3e4) = 0;
    *(u32 *)(p + 0x3e0) = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(p + i * 4 + 0x368) = 0;
    }
    func_021BFC50(p);
    func_021BFB0C(p);
    func_021BFBDC(p);
    func_021BFE80(p);
    func_021BFEE4(p);
    func_021BFB60(p);
    func_021BFBB8(p);
    func_021BFB30(p);
    func_021C019C(p);
    func_021C0384(p);
    func_021C03EC(p);
    func_021C04B0(p);
    func_021C07B0(p);
    func_021C0820(p);
}

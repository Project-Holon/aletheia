/*
 * function: func_02029250
 * address:  0x02029250
 * packet:   pkt_02029250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02029434(u8 *p);
extern void func_02029344(u8 *p, u32 v);
extern void func_02029374(u8 *p);
extern void func_02005D28(void);

void func_02029250(u8 *p)
{
    if (func_02029434(p) == 0) {
        return;
    }
    if (*(u32 *)(p + 0xc) != 0 && *(u32 *)(p + 0xc) != *(u32 *)(p + 8)) {
        func_02005D28();
        func_02029344(p, 8);
        return;
    }
    func_02029374(p);
    func_02029344(p, 0xa);
}

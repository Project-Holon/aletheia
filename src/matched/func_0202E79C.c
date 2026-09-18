/*
 * function: func_0202E79C
 * address:  0x0202E79C
 * packet:   pkt_0202E79C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020084A0  0x020084A0  thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_020084A0(void *p);

void func_0202E79C(u8 *p)
{
    func_02082BCC(p, 0, 0x4c);
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 8) = 0;
    func_020084A0(p + 0xc);
    func_020084A0(p + 0x2c);
}

/*
 * function: func_021B6DB4
 * address:  0x021B6DB4
 * packet:   pkt_ov071_021B6DB4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6E00  0x021B6E00  thumb  ov071
 *   func_021B6E18  0x021B6E18  thumb  ov071
 *   PALANM_BlendChannel  0x02021FD8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct Chan02021FD8;
void func_021B6DB4(int *p, int a, int idx)
{
    void func_02082BCC(void *, int, int);
    int func_021B6E00(unsigned int x);
    int func_021B6E18(int);
    void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
    u8 *e;

    e = (u8 *)p + 0xC + idx * 8;
    func_02082BCC(e, 0, 8);
    e[2] = a;
    PALANM_BlendChannel((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)func_021B6E00(idx), (u16)func_021B6E18(idx), 0, 0);
}

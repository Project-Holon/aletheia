/*
 * function: func_021C72A0
 * address: 0x021C72A0
 * packet: pkt_ov128_021C72A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
extern void func_021CA444(char *);
extern void func_021CA458(void *,void *);
extern void func_02027FD8(void *);
extern void func_02045808(void *);
extern void func_020452E8(void *);
extern void func_020307B0(void *);
void func_021C72A0(u8 *p, int unused, u8 *q)
{
    func_021CA444((char *)q);
    func_021CA458(q,q+12);
    func_02027FD8(*(void **)(p+0x48));
    func_02045808(*(void **)(p+0x30));
    func_02045808(*(void **)(p+0x3c));
    func_02045808(*(void **)(p+0x2c));
    func_020452E8(*(void **)(p+0x1c));
    func_020452E8(*(void **)(p+0xc));
    func_020307B0(*(void **)(p+0x14));
}

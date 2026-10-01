/*
 * function: func_021DCC24
 * address: 0x021DCC24
 * packet: pkt_ov171_021DCC24
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 */
extern void *func_02045B38(int, int, int, unsigned);
extern void *func_0201D7EC(int, int, int, int, unsigned);
extern void *func_0201EC64(unsigned);
extern void *func_0201C440(unsigned);
extern void *func_020457B0(unsigned, unsigned);
void func_021DCC24(char *p)
{
    *(void **)(p+0xb60)=func_02045B38(0,2,0x55,0x8c);
    *(void **)(p+0xb58)=func_0201D7EC(0x17,0,0,0,0x8c);
    *(void **)(p+0xb5c)=func_0201D7EC(0x17,3,0,0,0x8c);
    *(void **)(p+0xb64)=func_0201EC64(0x8c);
    *(void **)(p+0xb6c)=func_0201C440(0x8c);
    *(void **)(p+0xb68)=func_020457B0(0x400,0x8c);
}

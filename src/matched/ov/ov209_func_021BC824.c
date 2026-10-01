/*
 * function: func_021BC824
 * address: 0x021BC824
 * packet: pkt_ov209_021BC824
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 bytes of alignment padding
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045B38(u32, u32, u32, u32);
extern void *func_0201D7EC(int, int, int, int, u32);
extern void *func_0201EC64(u32);
extern u32 func_0201C440(void *);
extern void *func_020457B0(u32, u32);
void func_021BC824(char *p)
{
    *(void **)(p + 0x3C) = func_02045B38(0, 2, 0x114, 0x6B);
    *(void **)(p + 0x38) = func_0201D7EC(0x17, 0, 0, 0, 0x6B);
    *(void **)(p + 0x40) = func_0201EC64(0x6B);
    *(u32 *)(p + 0x48) = func_0201C440((void *)0x6B);
    *(void **)(p + 0x44) = func_020457B0(0x80, 0x6B);
}

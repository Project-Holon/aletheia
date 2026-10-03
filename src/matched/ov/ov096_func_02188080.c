/*
 * function: func_02188080
 * address: 0x02188080
 * packet: pkt_ov096_02188080
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Extent ends with two-byte zero alignment padding.
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02011264 0x02011264 thumb
 *   func_0201C408 0x0201C408 thumb
 *   func_0201C3C0 0x0201C3C0 thumb
 *   func_0218A458 0x0218A458 thumb ov096
 */
typedef unsigned char u8;
extern u8 *func_02011324(void *);
extern void func_02049238(void *);
extern void func_020307B0(void *);
extern void func_02011264(void *);
extern int func_0201C408(void);
extern void func_0201C3C0(void);
extern void func_0218A458(void);
void func_02188080(void *a)
{
    u8 *p;
    p = func_02011324(a);
    func_02049238(*(void **)(p + 0xA4));
    func_02049238(*(void **)(p + 0xA8));
    func_020307B0(p);
    func_02011264(a);
    if (func_0201C408() == 1) func_0201C3C0();
    func_0218A458();
}

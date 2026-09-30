/*
 * function: func_021D9E04
 * address: 0x021D9E04
 * packet: pkt_ov121_021D9E04
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0201CE48(void *);
extern void func_0202F038(u8 *);
extern void func_02028604(void *);
extern void func_02031140(void *);
extern void func_0201F7A8(void *, u32);
extern void func_020452E8(void *);
extern void func_02045808(void *);
extern void func_020307B0(void *);
void func_021D9E04(u8 *p)
{
    if (*(void **)(p + 8)) {
        func_0201CE48(*(void **)(p + 8));
        *(void **)(p + 8) = 0;
    }
    if (*(void **)(p + 0x3c)) {
        func_0202F038(*(void **)(p + 0x3c));
        *(void **)(p + 0x3c) = 0;
    }
    if (*(void **)(p + 0x30)) func_02028604(*(void **)(p + 0x30));
    func_02031140(*(void **)(p + 0xc));
    func_0201F7A8(*(void **)(p + 0x10), 0);
    func_020452E8(*(void **)(p + 0x10));
    func_02045808(*(void **)(p + 0x14));
    func_020307B0(p);
}

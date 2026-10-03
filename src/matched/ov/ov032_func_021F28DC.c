/*
 * function: func_021F28DC
 * address: 0x021F28DC
 * packet: pkt_ov032_021F28DC
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two alignment padding bytes at 0x021F2906 follow the body.
 * symbols:
 *   func_02165940 0x02165940 thumb ov010
 *   func_02010F8C 0x02010F8C thumb
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02165940(unsigned char *p);
extern void func_02010F8C(void *);
extern void func_020307B0(void *);
void func_021F28DC(char *p)
{
    func_02165940(*(void **)(p + 0x38));
    func_02010F8C(*(void **)(p + 0x24));
    func_020307B0(*(void **)(p + 0x4c));
    func_020307B0(*(void **)(p + 0x44));
    func_020307B0(*(void **)(p + 0x40));
    func_020307B0(*(void **)(p + 0x38));
}

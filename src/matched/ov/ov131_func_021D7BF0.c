/*
 * function: func_021D7BF0
 * address: 0x021D7BF0
 * packet: pkt_ov131_021D7BF0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D7E84 0x021D7E84 thumb ov131
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void func_021D7E84(void *, unsigned char *);
struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void func_020307B0(void *);
void func_021D7BF0(void *a, unsigned char *p)
{
    if (*(int *)(p + 4) == 1) func_021D7E84(a, p);
    func_02045C04(*(void **)(p + 0x38));
    func_02045C04(*(void **)(p + 0x3c));
    func_02045C04(*(void **)(p + 0x40));
    func_02045C04(*(void **)(p + 0x44));
    func_02045C04(*(void **)(p + 0x48));
    func_020307B0(*(void **)(p + 0x50));
    func_020307B0(*(void **)(p + 0x58));
    func_020307B0(*(void **)(p + 0x60));
    func_020307B0(*(void **)(p + 0x68));
}

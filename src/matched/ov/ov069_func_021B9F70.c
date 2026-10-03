/*
 * function: func_021B9F70
 * address: 0x021B9F70
 * packet: pkt_ov069_021B9F70
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9FF0 0x021B9FF0 thumb ov069
 *   func_021B9FC8 0x021B9FC8 thumb ov069
 *   func_020061E4 0x020061E4 thumb
 */
extern void func_021B9FF0(void *p, void *list, int idx);
extern void func_021B9FC8(char *p, int i);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void func_021B9F70(char *p, int i)
{
    func_021B9FF0(p, *(void **)(p + 8), (int)((unsigned)i + (unsigned)*(unsigned short *)(p + 0x160) * 10u));
    func_021B9FC8(p, i);
    func_020061E4(0x548);
}

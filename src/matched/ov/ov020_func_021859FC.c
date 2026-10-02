/*
 * function: func_021859FC
 * address: 0x021859FC
 * packet: pkt_ov020_021859FC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02186470 0x02186470 thumb ov020
 *   func_02013DD0 0x02013DD0 thumb
 *   func_02185928 0x02185928 thumb ov020
 *   func_02012B38 0x02012B38 thumb
 *   func_0201444C 0x0201444C thumb
 *   func_020127C4 0x020127C4 thumb
 *   func_021864DC 0x021864DC thumb ov020
 */
typedef unsigned short u16;
extern void func_02186470(void *p);
extern int func_02013DD0(int id);
extern void func_02185928(void *p, const short *s);
extern void *func_02012B38(void *p);
extern unsigned int func_0201444C(void *p);
extern void *func_020127C4(void *p);
extern void func_021864DC(void *p);
void func_021859FC(void *p, const short *s)
{
    func_02186470(p);
    if (func_02013DD0(*(const u16 *)(s + 2)) != 0) {
        func_02185928(p, s);
        if (func_0201444C(func_02012B38(p)) == 0) {
            func_021864DC(func_020127C4(p));
        }
    }
}

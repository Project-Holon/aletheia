/*
 * function: func_021FA064
 * address: 0x021FA064
 * packet: pkt_ov132_021FA064
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: compiled ends 021FA0CE; two zero padding bytes before labelled 021FA0D0.
 * symbols:
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_02005728 0x02005728 thumb
 *   func_021FA3A8 0x021FA3A8 thumb ov132
 *   func_021FA4AC 0x021FA4AC thumb ov132
 *   func_021FA27C 0x021FA27C thumb ov132
 */
typedef unsigned char u8;
extern int func_021F9DFC(void *);
extern unsigned func_02005728(unsigned);
extern void func_021FA3A8(char *, char *, unsigned);
extern void func_021FA4AC(char *);
extern void func_021FA27C(char *);
void func_021FA064(char *p)
{
    u8 i;
    if (func_021F9DFC(*(void **)(p + 0x1e8)) == 0) {
        if (func_02005728(10) == 0) {
            for (i = 0; i < 3; i++) {
                u8 a = func_02005728(4);
                u8 b = func_02005728(60);
                func_021FA3A8(p, p + 0x204 + b * 8, a);
            }
        }
    } else {
        if (*(int *)(p + 0x200) == 1) {
            func_021FA4AC(p);
            *(int *)(p + 0x200) = 0;
        }
        func_021FA27C(p);
    }
}

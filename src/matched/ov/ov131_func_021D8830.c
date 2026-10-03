/*
 * function: func_021D8830
 * address: 0x021D8830
 * packet: pkt_ov131_021D8830
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A2C 0x021D8A2C thumb ov131
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021D9670 0x021D9670 thumb ov131
 *   func_021D9568 0x021D9568 thumb ov131
 *   func_021D92B0 0x021D92B0 thumb ov131
 */

extern void func_021D8A2C(unsigned char *, unsigned char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021D9670(unsigned char *, unsigned char *);
extern void func_021D9568(unsigned char *, unsigned char *);
extern void func_021D92B0(unsigned char *, unsigned char *);
void func_021D8830(unsigned char *a, unsigned char *p)
{
    func_021D8A2C(a,p);
    if (*(int *)(p+8) == 1) {
        if (func_0201C6B4(*(void **)(a+0x84)) == 1) {
            func_021D9670(a,p);
            func_021D9568(a,p);
            *(int *)(p+8)=0;
        }
    } else func_021D92B0(a,p);
    if (p[0x60]) p[0x60]--;
}

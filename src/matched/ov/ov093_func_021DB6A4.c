/*
 * function: func_021DB6A4
 * address: 0x021DB6A4
 * packet: pkt_ov093_021DB6A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021DB650 0x021DB650 thumb ov093
 */
typedef unsigned int   u32;
struct QS;
extern void func_021D7320(struct QS *p, u32 v);
extern int func_021DB650(int,int,int,int,int,unsigned char);

void func_021DB6A4(void *a, int b, int c, int *d)
{
    if (*d == 0) {
        func_021D7320(a, (u32)func_021DB650);
        *d = 1;
    }
}

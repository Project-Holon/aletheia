/*
 * function: func_021C1374
 * address: 0x021C1374
 * packet: pkt_ov099_021C1374
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned short u16;
extern int func_021C1154(char *, int);
extern int func_020399A8(void);
extern int func_02039CB4(unsigned, unsigned, unsigned);
extern unsigned func_02008468(int);
typedef unsigned char  u8;
extern u8 *func_02012944(void *p);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_021BA8EC(char *);
int func_021C1374(char *p, int ret)
{
    int h;
    unsigned count;
    void *q;
    if (func_021C1154(p, ret) == 0) {
        if (func_02039CB4(func_020399A8(), 14, 10) != 0) {
            h = func_020399A8();
            count = func_02008468(h);
            q = func_02012944(*(void **)(p + 0xc4));
            if (func_0203D3A8((void *)h, 0xa04, count, q) != 0) {
                func_021BA8EC(p);
                *(int *)(p + 0x1cc) = 135;
            }
        }
    }
    return ret;
}

/*
 * function: func_021D4AB4
 * address: 0x021D4AB4
 * packet: pkt_ov123_021D4AB4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02012138 0x02012138 thumb
 *   func_02026454 0x02026454 thumb
 *   func_021D4244 0x021D4244 thumb ov123
 */
typedef unsigned int u32;
extern int func_020221A4(char *);
extern void *func_02012138(void *);
extern int func_02026454(void *);
extern void func_021D4244(char *, void *, int);
void func_021D4AB4(char *p)
{
    if (func_020221A4(p) != 0) {
        switch (*(u32 *)(p + 8)) {
        case 2:
        case 3:
            if (func_02026454(func_02012138(*(void **)(p + 0x264))) == 0)
                func_021D4244(p, 0, 0x345);
            break;
        default:
            func_021D4244(p, 0, 0x349);
            break;
        }
    }
}

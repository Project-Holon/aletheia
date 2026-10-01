/*
 * function: func_021BD148
 * address: 0x021BD148
 * packet: pkt_ov209_021BD148
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: unsigned short bitfield base keeps ldrh before the 16/17 extraction; unsigned emits ldr (DIFF1).
 * symbols:
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021BD8C4 0x021BD8C4 thumb ov209
 *   func_021BE5D4 0x021BE5D4 thumb ov209
 */
struct Timer { unsigned short low : 1; unsigned short high : 15; };
extern int func_021B7AB0(char *);
extern int func_021BD8C4(char *, unsigned);
extern void func_021BE5D4(char *, int);
int func_021BD148(char *p)
{
    switch (*(int *)(p + 20)) {
    case 0:
        if (func_021B7AB0(*(char **)(p + 0xc2c)) == -1) (*(int *)(p + 20))++;
        break;
    case 1:
        if (((struct Timer *)(p + 0xc24))->high == 60 || func_021BD8C4(p, ((struct Timer *)(p + 0xc24))->high) == 0) {
            *(int *)(p + 20) = 0;
            func_021BE5D4(p, 0);
            return 4;
        }
        break;
    }
    return 5;
}

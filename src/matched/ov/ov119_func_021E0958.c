/*
 * function: func_021E0958
 * address: 0x021E0958
 * packet: pkt_ov119_021E0958
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0A64 0x021E0A64 thumb ov119
 */
extern int func_021E12AC(void *);
extern void func_021D8E84(void *, int);
extern void func_021E0A64(void *);
void func_021E0958(char *p)
{
    if (func_021E12AC(p) && *(int *)(p + 0xF2C) > 0xB4) {
        func_021D8E84(p, (int)func_021E0A64);
    }
}

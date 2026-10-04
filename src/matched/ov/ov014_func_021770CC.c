/*
 * function: func_021770CC
 * address: 0x021770CC
 * packet: pkt_ov014_021770CC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A0 0x021797A0 data a4
 *   func_021770A8 0x021770A8 thumb ov014
 *   func_02177EB0 0x02177EB0 thumb ov014
 */
typedef unsigned char u8;
extern u8 *g_021797A0;
extern int func_021770A8(void *);
extern int func_02177EB0(int a);
int func_021770CC(void (*cb)(void *))
{
    if(g_021797A0 != 0) {
        *(void (**)(void *))(g_021797A0+4)=cb;
        return func_02177EB0((int)func_021770A8);
    }
    return 1;
}

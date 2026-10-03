/*
 * function: func_021DF370
 * address: 0x021DF370
 * packet: pkt_ov137_021DF370
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate far-field then near-field stores preserve store scheduling.
 * symbols:
 *   func_021E0570 0x021E0570 thumb ov137
 *   func_021E07A4 0x021E07A4 thumb ov137
 *   func_021E0A44 0x021E0A44 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021E0570(u8 *p);
extern void func_021E07A4(void *);
extern u8 *func_021E0A44(void *);
int func_021DF370(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (*(int *)(p + 64) == 1) {
        values = (u16 *)(p + 108);
        *(int *)(p + 284) = values[0] << 12;
        *(int *)(p + 88) = values[0] << 12;
        for (i = 0; i < *(int *)(p + 48); i++) {
            entry = p + 736 + i * 180;
            *(int *)(entry + 28) = values[*(int *)(entry + 16) + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[*(int *)(entry + 16) + 2];
        }
        *(int *)(p + 28) = values[1];
        func_021E0570(p);
        func_021E07A4(p);
        *(u8 **)(p + 40) = func_021E0A44(p);
        *(int *)p = 35;
    }
    return 0;
}

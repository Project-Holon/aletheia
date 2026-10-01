/*
 * function: func_021B9F40
 * address: 0x021B9F40
 * packet: pkt_ov181_021B9F40
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02043658 0x02043658 arm
 *   func_021BA2D8 0x021BA2D8 thumb ov181
 *   func_021BA128 0x021BA128 thumb ov181
 *   func_02047910 0x02047910 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047970 0x02047970 arm
 *   d_021BAC2C 0x021BAC2C data a4
 */
extern unsigned func_02043658(void);
extern void func_021BA2D8(char *);
extern void func_021BA128(char *);
extern int func_02047910(void *, unsigned short, int);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047A60(void *, const void *);
extern void func_02047970(void);
extern const unsigned d_021BAC2C[];
void func_021B9F40(char *p)
{
    unsigned i;
    if (**(int **)p != 1 && (func_02043658() & 1)) {
        func_021BA2D8(p);
        func_021BA128(p);
        for (i = 0; i < *(unsigned *)(p + 0x24); i++)
            func_02047910(*(void **)(p + 0x20), i, 0x1000);
        func_02047964();
        func_020479D8();
        func_02047A60(*(void **)(p + 0x20), d_021BAC2C);
        func_02047970();
    }
}

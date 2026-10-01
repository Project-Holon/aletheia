/*
 * function: func_021EB32C
 * address: 0x021EB32C
 * packet: pkt_ov093_021EB32C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021EB690 0x021EB690 thumb ov093
 *   func_021EB870 0x021EB870 thumb ov093
 *   func_021EBAC0 0x021EBAC0 thumb ov093
 *   func_021EBB20 0x021EBB20 thumb ov093
 *   func_021EBE28 0x021EBE28 thumb ov093
 *   func_021EBE88 0x021EBE88 thumb ov093
 *   func_021EBD90 0x021EBD90 thumb ov093
 *   func_021EBDDC 0x021EBDDC thumb ov093
 *   func_021EBED4 0x021EBED4 thumb ov093
 *   func_021EBF20 0x021EBF20 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*Cb)(int *, u8 *);
extern void *func_021B86B8(void ***);
extern u32 func_021B8588(void *);
extern int func_021B86C8(u8 *);
extern int func_021EB690(int *, u8 *);
extern int func_021EB870(int *, u8 *);
extern int func_021EBAC0(int *, u8 *);
extern int func_021EBB20(int *, u8 *);
extern int func_021EBE28(int *, u8 *);
extern int func_021EBE88(int *, u8 *);
extern int func_021EBD90(int *, u8 *);
extern int func_021EBDDC(int *, u8 *);
extern int func_021EBED4(int *, u8 *);
extern int func_021EBF20(int *, u8 *);
static inline void set(u8 *p, Cb cb)
{
    *(u32 *)(p + 0xe0) = 0;
    *(Cb *)(p + 0xe4) = cb;
    *(u8 **)(p + 0xe8) = p;
    *(u32 *)(p + 0xec) = 0;
}
void func_021EB32C(u8 *p, u32 flag)
{
    int type = (int)func_021B86B8(*(void ****)(p + 0x134));
    p[0x14f] = 0;
    p[0x150] = flag;
    switch (func_021B8588(*(void **)(p + 0x134))) {
    case 0:
        switch (type) {
        default: case 0: case 4: set(p, func_021EB690); return;
        case 1: case 2: set(p, func_021EB870); return;
        case 3: set(p, func_021EBAC0); return;
        }
    case 1:
        switch (type) {
        case 0: set(p, func_021EBB20); return;
        case 3:
            if (!func_021B86C8(*(u8 **)(p + 0x134))) set(p, func_021EBE28);
            else set(p, func_021EBE88);
            return;
        case 1: case 2:
            if (!func_021B86C8(*(u8 **)(p + 0x134))) set(p, func_021EBD90);
            else set(p, func_021EBDDC);
            return;
        }
        break;
    case 2:
        if (type != 3) set(p, func_021EBED4);
        else set(p, func_021EBF20);
        return;
    case 3:
        if (type != 3) set(p, func_021EBED4);
        else set(p, func_021EBF20);
        return;
    }
}

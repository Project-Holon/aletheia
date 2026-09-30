/*
 * function: func_021E31BC
 * address: 0x021E31BC
 * packet: pkt_ov119_021E31BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021E3034 0x021E3034 thumb ov119
 *   func_021E2F2C 0x021E2F2C thumb ov119
 *   func_021E2B68 0x021E2B68 thumb ov119
 */
extern void func_02048AC4(void *);
extern void func_02047E54(void *);
extern void func_020307B0(void *);
extern void func_021E3034(void *, int);
extern void func_021E2F2C(void *);
extern void func_021E2B68(void);
void func_021E31BC(char *p) {
    if (*(void **)(p+0x83c)) func_02048AC4(*(void **)(p+0x83c));
    func_02047E54(*(void **)(p+0x820));
    if (*(void **)(p+12)) {
        func_021E3034(*(void **)(p+12),6);
        func_021E2F2C(*(void **)(p+12));
        func_020307B0(*(void **)(p+12));
        *(void **)(p+12)=0;
    }
    func_021E2B68();
}

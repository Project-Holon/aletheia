/*
 * function: func_021BE4B4
 * address: 0x021BE4B4
 * packet: pkt_ov203_021BE4B4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov203
 *   func_021BE158 0x021BE158 thumb ov203
 *   func_0200566C 0x0200566C thumb
 *   func_0204EA0C 0x0204EA0C arm
 *   func_02011558 0x02011558 thumb
 *   func_020480E4 0x020480E4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_021BF810(void *);
extern void func_021BE158(void *);
extern void func_0200566C(void *);
extern void func_0204EA0C(void);
extern void func_02011558(void *);
extern void func_020480E4(void *, unsigned);
extern void func_02047E54(void *);
extern void func_020307B0(void *);
void func_021BE4B4(char *ctx)
{
    unsigned i;
    func_021BF810(*(void **)(ctx + 0x6c));
    func_021BE158(*(void **)(ctx + 0x20));
    if (*(void **)(ctx + 0x10)) {
        func_0200566C(*(void **)(ctx + 0x10));
        func_0204EA0C();
    }
    func_02011558(*(void **)(ctx + 0x18));
    for (i = 0; i < *(unsigned *)(ctx + 0x2c); i++) {
        func_020480E4(*(void **)(ctx + 0x1c), (*(unsigned short **)(ctx + 0x70))[i]);
    }
    func_02047E54(*(void **)(ctx + 0x1c));
    func_020307B0(*(void **)(ctx + 0x70));
    func_020307B0(ctx);
}

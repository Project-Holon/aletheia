/*
 * function: func_021BDE98
 * address: 0x021BDE98
 * packet: pkt_ov203_021BDE98
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 04000050/04001050 stores DECA/DED0; 04000000/04001000 rereads DED2/DEDC.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BE12C 0x021BE12C thumb ov203
 *   func_021BE0C4 0x021BE0C4 thumb ov203
 *   func_021BE02C 0x021BE02C thumb ov203
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02030EAC(void *);
extern void func_021BE12C(int *);
extern void func_021BE0C4(char *);
extern void func_021BE02C(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_020307B0(void *);
void func_021BDE98(char *ctx)
{
    if (*(int *)(ctx + 20) == 0) func_02030EAC(*(void **)(ctx + 16));
    func_021BE12C((int *)(ctx + 8));
    if (*(int *)(ctx + 20) == 0) {
        func_021BE0C4(ctx + 4);
        func_021BE02C(ctx);
    }
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    func_02082BCC(ctx, 0, 24);
    func_020307B0(ctx);
}

/*
 * function: func_021E2FA8
 * address: 0x021E2FA8
 * packet: pkt_ov183_021E2FA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 */
extern void *func_021FD12C(int, int, unsigned short);
extern void func_021FD170(void *, int, int);
extern void func_021FD860(int, int, int *);
void func_021E2FA8(char *p)
{
    int args[2];
    if (*(void **)(p + 8) == 0)
        *(void **)(p + 8) = func_021FD12C(*(int *)(*(char **)(p + 0x3c) + 8), *(int *)(p + 4), *(unsigned short *)(p + 0x38));
    func_021FD170(*(void **)(p + 8), *(int *)(*(char **)(p + 0x3c) + 8), 0x14b);
    args[0] = 0x80;
    args[1] = 0x60;
    func_021FD860(*(int *)(p + 0x30), 4, args);
}

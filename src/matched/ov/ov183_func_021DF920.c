/*
 * function: func_021DF920
 * address: 0x021DF920
 * packet: pkt_ov183_021DF920
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02025538 0x02025538 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021E02F8 0x021E02F8 thumb ov183
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int func_021F9B9C(char *);
extern char *func_0203159C(void *, unsigned int, unsigned int);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_0201C440(unsigned int);
extern void *func_02025538(unsigned int, unsigned int);
extern int func_021FD12C(int, int, unsigned int);
extern void func_021FD170(int, int, int);
extern int func_021FD760(int, int, int, unsigned int);
extern void func_021FBE54(int, int, unsigned int);
extern void func_021E02F8(char *, char *);
int func_021DF920(void *obj, int unused, char *q)
{
    char *p;
    int i;
    p = func_0203159C(obj, 0x58, func_021F9B9C(*(char **)(q + 0xC)));
    func_02082BCC(p, 0, 0x58);
    *(u16 *)(p + 0x54) = func_021F9B9C(*(char **)(q + 0xC));
    *(void **)(p + 0x48) = func_0201C440(*(u16 *)(p + 0x54));
    *(void **)(p + 0x44) = func_02025538(*(u16 *)(p + 0x54), *(unsigned int *)(q + 4));
    *(int *)(p + 0x38) = func_021FD12C(*(int *)(q + 8), *(int *)(p + 0x48), *(u16 *)(p + 0x54));
    func_021FD170(*(int *)(p + 0x38), *(int *)(q + 8), 0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)(p + i * 4 + 0x3C) = func_021FD760(*(int *)(q + 4), *(int *)(q + 8), i, *(u16 *)(p + 0x54));
    }
    *(u16 *)(q + 0x14) = 0xFFFF;
    *(u8 *)(q + 0x16) = 0xFF;
    *(u8 *)(q + 0x17) = 0xFF;
    *(int *)(q + 0x18) = 0x13;
    func_021FBE54(*(int *)(q + 8), 6, *(u16 *)(p + 0x54));
    func_021E02F8(p, q);
    return 1;
}

/*
 * function: func_0220D464
 * address: 0x0220D464
 * packet: pkt_ov197_0220D464
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02209C2C 0x02209C2C thumb
 *   func_0220D89C 0x0220D89C thumb ov197
 *   func_0220BF20 0x0220BF20 thumb ov197
 *   func_0220D234 0x0220D234 thumb ov197
 *   func_0220D254 0x0220D254 thumb ov197
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220D11C 0x0220D11C thumb ov197
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02209C2C(void *);
extern void func_0220D89C(char **, int);
extern void func_0220BF20(char *, int);
extern int func_0220D234(char *);
extern int func_0220D254(char *);
extern unsigned func_0220BB98(const char *, int);
extern int func_0220D11C(char *);
int func_0220D464(char *p)
{
    switch (*(u8 *)(p + 0x53d)) {
    case 0:
        if (func_02209C2C(*(void **)(p + 0x14c)) == 1) {
            func_0220D89C((char **)p, 0x54d);
            *(u8 *)(p + 0x533) = 2;
            *(u8 *)(p + 0x531) = 0x11;
            func_0220BF20(p, 2);
            ++*(u8 *)(p + 0x53d);
            return 0x10;
        }
        break;
    case 1:
        if (func_02209C2C(*(void **)(p + 0x14c)) == 0) {
            func_0220D234(p);
            ++*(u8 *)(p + 0x53d);
            *(u8 *)(p + 0x531) = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (func_02209C2C(*(void **)(p + 0x14c)) == 1) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char **)p + *(u8 *)(p + 0x533) * 2 + 0x30) = 0;
            *(u8 *)(p + 0x531) = 0x11;
            func_0220BF20(p, 4);
            ++*(u8 *)(p + 0x53d);
            return 0x10;
        }
        break;
    case 3:
        if (func_02209C2C(*(void **)(p + 0x14c)) == 0) {
            func_0220D254(p);
            ++*(u8 *)(p + 0x53d);
            *(u8 *)(p + 0x531) = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (func_02209C2C(*(void **)(p + 0x14c)) == 1) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char **)p + 0x16) = func_0220BB98(p, *(short *)(*(char **)p + *(u8 *)(p + 0x533) * 2 + 0x30));
            *(u8 *)(*(char **)p + 0x2a) = *(u8 *)(p + 0x533);
            *(u8 *)(*(char **)p + 0x18) = 0;
            func_0220BF20(p, 0xd);
            ++*(u8 *)(p + 0x53d);
        }
        break;
    case 5:
        if (func_02209C2C(*(void **)(p + 0x14c)) == 0) return func_0220D11C(p);
        break;
    }
    return 0x11;
}

/*
 * function: func_0220CC18
 * address: 0x0220CC18
 * packet: pkt_ov197_0220CC18
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0220D884 0x0220D884 thumb ov197
 *   func_02025DE8 0x02025DE8 thumb
 *   func_0220D89C 0x0220D89C thumb ov197
 *   func_0220BF20 0x0220BF20 thumb ov197
 *   func_0220B9D8 0x0220B9D8 thumb ov197
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02021ED8(void *);
extern int func_0220D884(char **);
extern int func_02025DE8(void *);
extern void func_0220D89C(char **, int);
extern void func_0220BF20(char *, int);
extern void func_0220B9D8(char *);
int func_0220CC18(char *p)
{
    unsigned sel;
    if (func_02021ED8(*(void **)(p + 8)) != 0) goto done;
    if (func_0220D884((char **)p) == 1) return 0x12;
    sel = func_02025DE8(*(void **)(p + 0x144));
    switch (sel) {
    case 0: case 1: case 2: case 3:
        func_0220D89C((char **)p, 0x54d);
        *(u8 *)(p + 0x533) = (u8)sel;
        *(u8 *)(p + 0x531) = 8;
        func_0220BF20(p, (u8)sel);
        return 0x10;
    case 4:
        if (*(u16 *)(p + 0x540) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u8 *)(p + 0x533) = *(u8 *)(p + 0x542);
            *(u8 *)(p + 0x531) = 9;
            func_0220B9D8(p);
            func_0220BF20(p, 0xd);
            return 0x10;
        }
        break;
    case 5:
        func_0220D89C((char **)p, 0x552);
        *(u16 *)(*(char **)p + 0x16) = 0;
        *(u8 *)(*(char **)p + 0x2a) = 4;
        func_0220BF20(p, 0xa);
        return 0x12;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        *(u16 *)(*(char **)p + 0x16) = 0;
        *(u8 *)(*(char **)p + 0x2a) = 4;
        func_0220BF20(p, 0xa);
        return 0x12;
    case (unsigned)-4: case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-6:
    case (unsigned)-5: case (unsigned)-1:
        break;
    }
done:
    return 4;
}

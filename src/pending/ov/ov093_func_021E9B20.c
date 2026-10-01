/*
 * function: func_021E9B20
 * address: 0x021E9B20
 * packet: pkt_ov093_021E9B20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: eight Thumb veneers at 021E9C60..021E9CE0 have off-image
 *   targets (06899CA5 etc.) and no outside code witness.
 * extent: lead is 320 bytes; eight 16-byte Thumb veneers follow.
 * symbols:
 *   func_021E9C60 0x021E9C60 thumb ov093
 *   func_021E9C70 0x021E9C70 thumb ov093
 *   func_021E9C80 0x021E9C80 thumb ov093
 *   func_021E9C90 0x021E9C90 thumb ov093
 *   func_021E9CA0 0x021E9CA0 thumb ov093
 *   func_021E9CB0 0x021E9CB0 thumb ov093
 *   func_021E9CC0 0x021E9CC0 thumb ov093
 *   func_021E9CD0 0x021E9CD0 thumb ov093
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   ov196_id 0x000000C4 data
 *   ov198_id 0x000000C6 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021E9C60(void *, int);
extern int func_021E9C70(void *);
extern void func_021E9C80(void *);
extern void func_021E9C90(void *, u8, u8);
extern void func_021E9CA0(void *);
extern void func_021E9CB0(void *);
extern void func_021E9CC0(void *);
extern int func_021E9CD0(void *);
extern void func_02034AC4(void *);
extern void func_02034A5C(void *);
extern void func_0220F3E8(void *);
extern u8 ov196_id[], ov198_id[];

int func_021E9B20(u8 *p)
{
    u32 i;
    switch (p[0x174]) {
    case 0:
        if ((u8)(p[0x12b] + 0xff) <= 1) func_021E9C60(*(void **)(p + 0x180), 0);
        else func_021E9C60(*(void **)(p + 0x180), 1);
        func_02034AC4(ov196_id);
        p[0x174]++;
        break;
    case 1:
        if (func_021E9C70(*(void **)(p + 0x180))) {
            func_021E9C80(*(void **)(p + 0x180));
            func_02034AC4(ov198_id);
            func_0220F3E8(p + 0x10c);
            p[0x174]++;
        }
        break;
    case 2:
        if (p[0x158]) {
            if (p[0x12b] != 5 && *(int *)(p + 0x13c) == 0) {
                for (i = 0; i < 3; i++) {
                    if (p[i + 0x154] != 0xff) {
                        func_021E9C90(*(void **)(p + 0x15c), i, p[i + 0x154]);
                        func_021E9CA0(*(void **)(p + 0x15c));
                        (*(u8 **)(p + 0x15c))[8] = 0;
                    }
                }
            }
            func_02034A5C(ov198_id);
            func_021E9CB0(*(void **)(p + 0x180));
            func_021E9CC0(*(void **)(p + 0x180));
            p[0x174]++;
        }
        break;
    case 3:
        if (func_021E9CD0(*(void **)(p + 0x180))) p[0x174]++;
        break;
    default:
        func_02034A5C(ov196_id);
        p[0x174] = 0;
        return 1;
    }
    return 0;
}

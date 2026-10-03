/*
 * function: func_021D171C
 * address: 0x021D171C
 * packet: pkt_ov093_021D171C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 * symbols:
 *   func_021D13A4 0x021D13A4 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021F878C 0x021F878C thumb ov094
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021D185C 0x021D185C thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021EA600 0x021EA600 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;
extern u32 func_021D13A4(void *);
extern void func_021B916C(u8 *p, u32 x);
extern u16 func_021B86DC(void **p);
extern void func_021F878C(u32 a);
extern u8 func_021B904C(u8 *p, int k);
extern unsigned short func_021BA020(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern void func_021D185C(void *, int, int);
extern int func_021F7EB4(void);
extern void func_021EA600(char *p);
extern int func_021EA710(u32 *p);
int func_021D171C(u8 *p, int *state)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0) return 1;
        mode = func_021D13A4(p);
        func_021B916C(*(void **)p, mode);
        if (mode == 1) func_021F878C(func_021B86DC(*(void **)p));
        if (mode <= 1) {
            idx = func_021B904C(*(void **)p, 0);
            func_021F7F58(func_021BA020(*(void **)p, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C(p, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(*(void **)(p + 0x54));
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(*(void **)(p + 0x54)) != 0) {
            idx = func_021B904C(*(void **)p, 0);
            if (idx == func_021B904C(*(void **)p, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = func_021D13A4(p);
            idx = func_021B904C(*(void **)p, 1);
            func_021F7F58(func_021BA020(*(void **)p, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C(p, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(*(void **)(p + 0x54));
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(*(void **)(p + 0x54)) != 0) return 1;
        break;
    }
    return 0;
}

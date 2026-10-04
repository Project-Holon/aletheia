/*
 * function: func_021D5D74
 * address: 0x021D5D74
 * packet: pkt_ov120_021D5D74
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker resolved: +0x2a calls verified unlabelled Thumb ov067 0x021B6498.
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_02028178 0x02028178 thumb
 *   func_02027974 0x02027974 thumb
 *   func_021D5F98 0x021D5F98 thumb ov120
 *   func_021D7858 0x021D7858 thumb ov120
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157170 0x02157170 thumb ov009
 *   func_021D5BEC 0x021D5BEC thumb ov120
 *   func_0202223C 0x0202223C thumb
 *   func_0200F7DC 0x0200F7DC thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern u32 func_021D6988(u8 *p);
extern int func_021B6498(u8 *p);
extern void func_02028178(u8 *p);
extern void func_02027974(void *);
extern void func_021D5F98(u8 *p);
extern void func_021D7858(u8 *p);
extern int func_0203CD98(void);
extern u32 func_02157170(int, int);
extern void func_021D5BEC(u8 *);
extern void func_0202223C(u32, u32);
extern void func_0200F7DC(void);
int func_021D5D74(int a, int b, int c, u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))p;
    int result = 1;
    if (callback) {
        if (func_0200FB24() == 0)
            callback(p);
        result = 0;
    }
    if (*(void **)(p + 0x34)) {
        void *q = (void *)func_021D6988(*(void **)(p + 0x3c));
        if (q == 0 || func_021B6498(q) == 0)
            func_02028178(*(void **)(p + 0x34));
    }
    if (*(void **)(p + 0x38))
        func_02027974(*(void **)(p + 0x38));
    func_021D5F98(*(void **)(p + 0x3c));
    func_021D7858(*(void **)(p + 0x40));
    if (func_0203CD98()) {
        if (func_0200FB24()) {
            switch (func_02157170(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                func_021D5BEC(p);
                break;
            case 2:
                *(int *)(*(u8 **)(p + 0x48) + 0x1b0) = 0;
                result = 1;
                func_0202223C(0, 0);
                func_0202223C(1, 0);
                break;
            case 3:
                func_0200F7DC();
                break;
            }
        }
    } else if (func_0200FB24()) {
        result = 1;
    }
    return result;
}

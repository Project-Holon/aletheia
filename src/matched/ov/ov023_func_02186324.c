/*
 * function: func_02186324
 * address:  0x02186324
 * packet:   pkt_ov023_02186324
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02186164  0x02186164  thumb  ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_02186304  0x02186304  thumb  ov023
 *   func_0218654C  0x0218654C  thumb  ov023
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02186164(u8 *p);
extern int func_02186558(u8 *p);
extern void func_02186480(u8 *p);
extern void func_02186304(u8 *p, int a);
extern int func_0218654C(u8 *p);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

int func_02186324(u8 *p)
{
    int st;
    int r;

    st = func_02186164(p);
    switch (st) {
    case 0:
        break;
    case 1:
        if (*(int *)(p + 0x198) > 0x10) {
            break;
        }
        if (func_02186558(p) != 1) {
            *(int *)(p + 0x9E78) = 1;
        }
        *(int *)(p + 0x19C) = 0x16;
        if (*(int *)(p + 0x9E70) != 0) {
            func_02186480(p);
            func_0204B878(*(void **)(p + 0xF0), 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (st < *(int *)(p + 0x1A8)) {
            if (*(int *)(p + 0x9E6C) == 2) {
                func_02186304(p, 0);
            } else if (*(int *)(p + 0x9E7C) == 0) {
                func_02186304(p, 1);
            } else {
                func_02186304(p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (st < *(int *)(p + 0x1A8)) {
        *(int *)(p + 0x1AC) = func_0218654C(p);
        r = func_02186558(p);
        *(int *)(p + 0x1B0) = r;
        if (*(int *)(p + 0x9E7C) != 0 && (r & *(int *)(p + 0x9E80)) == 0) {
            func_02186304(p, 1);
            *(int *)(p + 0x9E6C) = 1;
            *(int *)(p + 0x9E7C) = 0;
            *(int *)(p + 0x9E80) = 0;
        }
    }
    *(int *)(p + 0x1A8) = func_02186164(p);
    if (*(int *)(p + 0x1AC) < func_0218654C(p)) {
        *(int *)(p + 0x9E6C) = 2;
        *(int *)(p + 0x9E7C) = 1;
        *(int *)(p + 0x9E80) = func_02186558(p) ^ *(int *)(p + 0x1B0);
    }
    return 1;
}

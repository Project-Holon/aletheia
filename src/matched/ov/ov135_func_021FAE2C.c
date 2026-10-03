/*
 * function: func_021FAE2C
 * address: 0x021FAE2C
 * packet: pkt_ov135_021FAE2C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9A88 0x021F9A88 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B898 0x0204B898 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_021F9A88(void *, void *);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0204B898(struct Obj *p);
int func_021FAE2C(u8 *p)
{
    u32 sel = func_021F9A88(p, p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            func_0204B3DC(*(void **)(p + 8), 1);
            func_0204B878(*(void **)(p + 8), 19);
            *(int *)(p + 72) = 8;
            *(s16 *)(p + 56) = sel;
        }
    } else {
        func_0204B3DC(*(void **)(p + 8), 1);
        func_0204B878(*(void **)(p + 8), func_0204B898(*(void **)(p + 8)) + 9);
        *(int *)(p + 72) = 3;
        *(int *)(p + 76) = 8;
        *(s16 *)(p + 56) = -1;
    }
    return -1;
}

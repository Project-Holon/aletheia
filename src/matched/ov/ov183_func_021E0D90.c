/*
 * function: func_021E0D90
 * address: 0x021E0D90
 * packet: pkt_ov183_021E0D90
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0E3E alignment padding.
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021E0CE8(char *, int, int);
void func_021E0D90(char *p)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = func_0204B898(*(void **)(p + i * 28 + 0x194));
        if (state == 3) {
            if (!func_0204B98C(*(void **)(p + i * 28 + 0x194))) {
                func_0204B878(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
                if (*(int *)(p + 0x2fc) == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
                func_021E0CE8(p, 2, 0);
            }
        } else {
            if (state != *(int *)(p + i * 28 + 0x188)) func_0204B878(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
            if (func_0204B898(*(void **)(p + i * 28 + 0x194)) != 3) {
                if (*(int *)(p + 0x2fc) == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
            }
        }
    }
}

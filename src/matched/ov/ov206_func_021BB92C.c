/*
 * function: func_021BB92C
 * address: 0x021BB92C
 * packet: pkt_ov206_021BB92C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
void func_021BB92C(char *p, int index)
{
    int i;
    if (*(int *)(p + 0xe4) == 0) {
        for (i = 0; i < 2; i++) {
            if (*(int *)(p + index * 8 + i * 4 + 0xb8) != -1)
                func_0204B3B4((struct Obj *)(*(int *)(p + index * 8 + i * 4 + 0xd0)));
        }
        for (i = 0; i < 2; i++) {
            if (*(int *)(p + index * 8 + i * 4 + 0xb8) != -1) {
                func_0204A8D4(*(int *)(p + index * 8 + i * 4 + 0xb8));
                *(int *)(p + index * 8 + i * 4 + 0xb8) = -1;
            }
        }
    }
}

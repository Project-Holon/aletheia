/*
 * function: func_021D733C
 * address: 0x021D733C
 * packet: pkt_ov120_021D733C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_021D72C8 0x021D72C8 thumb ov120
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec;
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
extern int func_021D72C8(u8 *, int, int);
extern void func_0204B404(void *, const Vec *, u32);
void func_021D733C(u8 *p, int index, int count)
{
    Vec pos;
    if (*(void **)(p + 0x140) != 0) {
        func_0204B454(*(void **)(p + 0x140), (struct PtS *)&pos, 1);
        pos.y = func_021D72C8(p, index, count) + 26;
        func_0204B404(*(void **)(p + 0x140), &pos, 1);
    }
}

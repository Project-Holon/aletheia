/*
 * function: func_02022DCC
 * address:  0x02022DCC
 * packet:   pkt_02022DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02023CFC   0x02023CFC  thumb
 *   func_02023D18   0x02023D18  thumb
 *   func_02023D60   0x02023D60  thumb
 *   func_02023D40   0x02023D40  thumb
 *
 * Open one sprite/OBJ descriptor: a0 == 0 is the "close" spelling (one call
 * with mode 0 and no attribute writes), anything else opens with mode 1, sets
 * the 0x3f field, clears two zero slots through the six-argument entry and
 * finally stamps the 0x20 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022DCC.c \
 *       --func func_02022DCC --addr 0x02022DCC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
struct Struct_02023CFC;
extern void func_02023CFC(struct Struct_02023CFC *table, void *val, u32 idx);
extern void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC);
extern void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02023D40(void *obj, void *val, u32 f4, u32 f8);

void func_02022DCC(u32 a0, void *a1, u32 a2)
{
    if (a0 == 0) {
        func_02023CFC(a1, (void *)0, a2);
        return;
    }
    func_02023CFC(a1, (void *)1, a2);
    func_02023D18(a1, (void *)0x3f, 0, 0, a2);
    func_02023D60(a1, 0, 0, 0, 0, 0, a2);
    func_02023D40(a1, (void *)0x20, 0, a2);
}

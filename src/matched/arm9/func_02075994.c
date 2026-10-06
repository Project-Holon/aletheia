/*
 * function: func_02075994
 * address:  0x02075994
 * packet:   pkt_02075794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbols:
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *
 * Two relocation sites stay wildcarded, neither for want of C:
 *   +0064  bl func_02075A2C   `label`: 0x02075A2C's only branch image-wide is
 *                             this function's own call (asm, single caller).
 *                             It is inside THIS packet; the callee is parked
 *                             (byte-correct MATCH, its own `bl 0x02075968`
 *                             site has the same defect), so filing it does not
 *                             attest this site either.
 *   +0090  ABS32 g_02150178   `literal`: the only pool word naming 0x02150178
 *                             anywhere in the image, so own-pool-only.
 * The remaining six sites resolve (`label` x20/x20/x5/x20/x20, `literal` x5).
 * Spelled with the two bitfields at +0x118 as signed 1-bit fields; an
 * unsigned field emits `lsrs r0, r0, #0x1f` where the image has `asrs`, a
 * concrete two-byte diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02075994.c \
 *       --func func_02075994 --addr 0x02075994 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Obj75994 {
    u8  pad_00[0x118];
    s32 b0 : 1;
    s32 b1 : 1;
    s32 rest : 30;
    u8  pad_11c[0x5c];
    u32 cb;
};

extern u8  g_02150178[];
extern u8  g_0214EA90[];
extern void func_02086028(void *p);
extern void func_02086078(void *p);
extern void func_02073AB4(struct Obj75994 *o);
struct Obj;
extern void func_02075A2C(struct Obj *o);

void func_02075994(struct Obj75994 *o)
{
    u8 *p;

    func_02086028(g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0)
        func_02086028(p + 0x10c8);
    if (o->b1 != 0)
        func_02073AB4(o);
    if (o->b0 != 0)
        ((void (*)(struct Obj75994 *))o->cb)(o);
    func_02075A2C((struct Obj *)o);
    func_02086078(g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p == 0)
        return;
    func_02086078(p + 0x10c8);
}

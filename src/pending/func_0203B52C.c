/*
 * function: func_0203B52C
 * address:  0x0203B52C
 * packet:   pkt_0203B52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 168 concrete bytes are correct (the callback call
 * takes func_0203D650's return value in r0, which is why the function pointer
 * is loaded into r1).  Two unresolved sites, both ABS32 into the module-name
 * string block: 0x0203B4DC at +0x0098 and 0x0203B40C at +0x00a0.  Each has
 * exactly one pool word image-wide and both fall inside this compared range,
 * so `literal` has no second occurrence and `string` has no preceding
 * terminator.  Blocking class: none available, own-pool-only data.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_020393D0  0x020393D0  arm
 *   func_020393A8  0x020393A8  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203D650  0x0203D650  arm
 *   g_021469DC     0x021469DC  data
 *   str_0203B4DC   0x0203B4DC  data
 *   str_0203B40C   0x0203B40C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B52C.c \
 *       --func func_0203B52C --addr 0x0203B52C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32  g_021469DC;
extern char str_0203B4DC[];
extern char str_0203B40C[];

extern void *func_0203D798(void);
extern u32   func_020393D0(void);
extern u32   func_020393A8(void);
extern void  func_0203AD80(u32 ctx, void *tag, u32 val, u32 line);
extern u32   func_020399EC(void);
extern u32   func_02039ACC(void);
extern u32   func_0203D650(void);

struct Slot {
    u8  pad_00[0x2c];
    u32 f2c;
};

void func_0203B52C(struct Slot *p)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80(g_021469DC, str_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2c != 0) {
        ((void (*)(u32))p->f2c)(func_0203D650());
        p->f2c = 0;
    }
    func_0203AD80(g_021469DC, str_0203B40C, 0, 0x2a6);
}

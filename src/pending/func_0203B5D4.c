/*
 * function: func_0203B5D4
 * address:  0x0203B5D4
 * packet:   pkt_0203B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 180 concrete bytes are correct.  The one unresolved
 * site is the ABS32 to 0x0203B52C at +0x00a4 -- a module-name string whose
 * only pool word image-wide is inside this compared range, so neither
 * `literal` (no second occurrence) nor `string` (the preceding data is a
 * table, not a NUL-terminated string) can attest it.  Filing 0x0203B52C
 * itself does not help: the address is data, not the code at the same
 * address.  Blocking class: none available, own-pool-only data.
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_020393A8  0x020393A8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203B2A8  0x0203B2A8  arm
 *   func_0203D700  0x0203D700  arm
 *   func_0203AD80  0x0203AD80  arm
 *   g_021469DC     0x021469DC  data
 *   str_0203B52C   0x0203B52C  data
 *   str_0203B48C   0x0203B48C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B5D4.c \
 *       --func func_0203B5D4 --addr 0x0203B5D4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  g_021469DC;
extern char str_0203B52C[];
extern char str_0203B48C[];

extern void *func_0203D788(void);
extern u32   func_020393A8(void);
extern u8   *func_0203D798(void);
extern void  func_0203B2A8(u32 key);
extern void  func_0203D700(void);
extern void  func_0203AD80(u32 ctx, void *tag, u32 val, u32 line);

struct Vt {
    u8  pad_00[0x38];
    u32 (*f38)(u32 a);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

struct Slot {
    u8  pad_00[0x46];
    u16 f46;
    u8  pad_48[0xe];
    u8  f56;
};

void func_0203B5D4(struct Slot *p)
{
    struct Obj *q = (struct Obj *)func_0203D788();

    if (func_020393A8() != 0) {
        func_0203B2A8(*(u16 *)(func_0203D798() + 0x56));
        func_0203D700();
        func_0203AD80(g_021469DC, str_0203B52C, 0, 0x2c1);
        return;
    }
    if (p->f56 == 1)
        return;
    if (q->f340->f38(0) == 0)
        return;
    if (p->f46 != 0) {
        p->f46--;
        return;
    }
    func_0203AD80(g_021469DC, str_0203B48C, 0, 0x2d3);
}

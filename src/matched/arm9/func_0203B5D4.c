/*
 * function: func_0203B5D4
 * address:  0x0203B5D4
 * packet:   pkt_0203B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     promoted MATCH -> EXACT on 2026-09-21 (family wave 4).
 *
 * THE FIX WAS THE DECLARATION, NOT THE C.  The body is byte-identical to the
 * parked version; only the +0x00a4 site's spelling changed.  The earlier
 * header read that word as a module-name STRING (`str_0203B52C`, kind
 * `data`) and concluded no class could attest it.  It is not a string: it is
 * the CODE ADDRESS of func_0203B52C, handed to func_0203AD80 as the
 * reporting call's identifier tag, exactly the way func_0203B038 hands it
 * the no-op at 0x0203B018 and func_0203B52C hands it func_0203B4DC.  Spelt
 * `func_0203B52C 0x0203B52C arm` and passed as `(void *)func_0203B52C`, the
 * site resolves `sole-ref x1` -- sole-ref/code, since 0x0203B52C is exactly
 * a traced ARM function start, and that sub-kind needs no outside branch.
 *
 * The companion site at +0x00ac (0x0203B48C) already resolved `literal x8`
 * and is unchanged.
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_020393A8  0x020393A8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203B2A8  0x0203B2A8  arm
 *   func_0203D700  0x0203D700  arm
 *   func_0203AD80  0x0203AD80  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203B52C  0x0203B52C  arm
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
struct Slot;
extern void func_0203B52C(struct Slot *p);
extern char str_0203B48C[];

extern void *func_0203D788(void);
extern int func_020393A8(void);
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
        func_0203AD80(g_021469DC, (void *)func_0203B52C, 0, 0x2c1);
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

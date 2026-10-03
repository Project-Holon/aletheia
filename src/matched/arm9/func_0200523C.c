/*
 * unit:     no
 * function: func_0200523C
 * address:  0x0200523C
 * packet:   pkt_02005230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocking class: label. Seven `bl` sites in this range have no branch witness
 * anywhere else in the image, so their relocation fields stay wildcarded:
 *   0x02006F20 (row of this lane, still unfiled), 0x02034704, 0x02005B24,
 *   0x02006544, 0x020082DC, 0x020266E0, 0x02010DB4.
 * Every other site resolves (label / matched) and every concrete byte in the
 * 152-byte body plus its 24-byte pool reproduces: compiled 176 bytes against
 * the original's 176, 0 concrete differences.
 *
 * Two spellings the original needs and that are not guessable from the bytes:
 *   * the first two calls pass FS_OVERLAY_ID-style absolute symbols, not the
 *     numbers 10 and 11. `func_02034AC4(10)` compiles `movs r0, #0xa` (2 bytes,
 *     no pool word) where the original has `ldr r0, [pc, #0x94]` over a pool
 *     word 0x0000000A; declaring `extern u8 ov010_id[]` at 0x0000000A in the
 *     symbols block is what puts the pool word back. Same for 0x0000000B.
 *     (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md)
 *   * 0x02006C01 and 0x02006C2D are two Thumb function pointers. Written as
 *     plain integers mwcc folds the second to `adds r2, r1, #0x2c` off the
 *     first; written as `&func_02006C00` / `&func_02006C2C` the two ABS32
 *     relocations keep both pool words, which is the original's shape.
 *
 * symbols:
 *   func_02034704   0x02034704  arm
 *   func_0200FB6C   0x0200FB6C  thumb
 *   func_02006C00   0x02006C00  thumb
 *   func_02006C2C   0x02006C2C  thumb
 *   ov010_id        0x0000000A  data
 *   ov011_id        0x0000000B  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02034AC4(void *a0);
struct SaveCtrl;
struct Sub02007084Ctrl;
struct Sub02008700Obj;
extern void func_0201C41C(void *arg);
extern void func_0203CB34(u32 a, u32 b, u32 c, u32 d);
extern void func_02010794(int a0);
extern void func_020107CC(void);
extern void func_020312CC(int a0, void *a1, int a2);
extern struct SaveCtrl *func_02006F20(int heap);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 func_02008414(const void *p);
extern void func_02012FF0(void *val);
extern void func_0200F6B8(void);
extern void func_0200F6D8(u32 kind);
extern void func_02034704(void *a0);
extern void func_0201F344(u16 heap);
extern void func_020173D0(u32 heap);
extern void func_02005B24(void);
extern void func_02006544(int a0, void *a1, void *a2);
extern void func_0200530C(void *obj);
extern void func_020082DC(void);
extern void func_020266E0(u32 a0);
extern void func_02010DB4(void);

extern void func_0200FB6C(void);
extern void func_02006C00(u32 species, u32 form, u32 *out);
extern u32 func_02006C2C(u32 species, u32 form, void **rec, void **owner, u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch);
extern u8 ov010_id[];
extern u8 ov011_id[];

void func_0200523C(void)
{
    int v = 0xC;

    func_02034AC4(ov010_id);
    func_02034AC4(ov011_id);
    func_0201C41C(0);
    func_0203CB34(1, 0, 1, v);
    func_02010794(v);
    func_020107CC();
    func_020312CC(v - 0xD, (void *)0x020A0480, 0);
    func_02006F20(7);
    func_02008414(func_0200873C(func_020070A4()));
    func_02012FF0(func_020070A4());
    func_0200F6B8();
    func_0200F6D8(8);
    func_02034704((void *)&func_0200FB6C);
    func_0201F344(0);
    func_020173D0(0);
    func_02005B24();
    func_02006544(1, (void *)&func_02006C00, (void *)&func_02006C2C);
    func_0200530C(func_0200873C(func_020070A4()));
    func_020082DC();
    func_020266E0(1);
    func_02010DB4();
}

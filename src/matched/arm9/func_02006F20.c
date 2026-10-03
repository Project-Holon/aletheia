/*
 * function: func_02006F20
 * address:  0x02006F20
 * packet:   pkt_02006F20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4   0x02034AC4  arm
 *   func_02034A5C   0x02034A5C  arm
 *   func_02030734   0x02030734  arm
 *   func_0203192C   0x0203192C  arm
 *   func_02031AE0   0x02031AE0  arm
 *   func_020319C0   0x020319C0  arm
 *   func_02034714   0x02034714  arm
 *   func_021DFC20   0x021DFC20  thumb  ov228
 *   func_021DFE90   0x021DFE90  thumb  ov228
 *   func_021DFE98   0x021DFE98  thumb  ov228
 *   func_021DFDB8   0x021DFDB8  thumb  ov228
 *   sub_02008754    0x02008754  thumb
 *   sub_02008784    0x02008784  thumb
 *   sub_0200725C    0x0200725C  thumb
 *   sub_020072A4    0x020072A4  thumb
 *   sub_0200A5F8    0x0200A5F8  thumb
 *   sub_0200A7EC    0x0200A7EC  thumb
 *   ov228_id        0x000000E4  data
 *   sub_02006F20_File  0x020A7054  data
 *   sub_02006F20_Ptr   0x02146168  data
 *   g_0209D938      0x0209D938  data
 *   sub_02006F20_Msg   0x020A7064  data
 *
 * The constructor of "save_control.c" (the file name string at 0x020A7054 is
 * the one this passes to the debug allocator at 0x02030734, line 0x58).  It
 * loads the overlay that owns the save code, reads three mode bytes out of
 * it, allocates the 0x38 byte control block into the global at 0x02146168,
 * and then walks the nine save streams at +0x14 deciding which to open.
 *
 * 0x000000E4 is the overlay id, an absolute linker symbol and not the plain
 * integer 228: written as a literal it compiles `movs r0, #0xe4` with no
 * pool word, where the original has `ldr r0, [pc, #0x148]` over a pool word
 * 0x000000E4.  See
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * Both dispatches are dense PC-relative halfword tables over five cases, so
 * every low case label exists in the source even where the arm is empty;
 * see docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * WAVE 16 (docs/notes/func_02006F20.c.txt had it at 118 out and
 * MATCH-capped).  The cap went with the ov228 leaves matched this wave
 * (src/matched/func_021DFDB8.c, func_021DFE90.c, func_021DFE98.c; plus the
 * labelled func_021DFC20), carried by the ov228 hints above; func_021DFE90
 * takes the overlay work pointer (its body reads r0).  The bytes closed in
 * three steps: a fresh body with the switch value `r` tested as
 * (u32)(r - 1) <= 1 before sub_02008754 (167 out, size exact); an ENUM loop
 * counter over the nine slots, which keeps the image's unfolded `cmp r4, #9`
 * guard (10 out); and the loop written in its own shape, `i = 0; if (i <
 * MAX) { flags = &c->unk0C; do { ... i++; } while (i < MAX); }`, which puts
 * the flags pointer after the guard where the image computes it.  A `for`
 * with flags assigned inside the body instead keeps a second top test.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006F20.c \
 *       --func func_02006F20 --addr 0x02006F20 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct SaveCtrl
{
  u8 unk00;
  u8 unk01;
  u8 unk02;
  u8 unk03;
  u8 unk04;
  u8 unk05;
  u8 pad06[6];
  u32 unk0C;
  void *unk10;
  void *unk14[9];
};
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
typedef unsigned short u16;
struct State;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0203192C(void *p, int heap);
extern int func_02031AE0(struct State *o, u32 a1);
extern void func_020319C0(u8 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_021DFC20(u32 heap);
extern u8 func_021DFE90(u8 *p);
extern int func_021DFE98(u8 *p);
extern void func_021DFDB8(void *p);
extern u8 sub_02008754(void *sys);
extern int sub_02008784(void *sys, u32 index);
struct Ctrl;
extern u32 sub_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
struct Sub020072A4Ctrl;
extern void sub_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void *sub_0200A5F8(void *sys);
struct Big;
extern void sub_0200A7EC(struct Big *p, u8 value);
extern u8 ov228_id[];
extern const char sub_02006F20_File[];
extern const char sub_02006F20_Msg[];
extern struct SaveCtrl *sub_02006F20_Ptr;
extern u8 g_0209D938[];
typedef enum { SLOT_0, SLOT_1, SLOT_2, SLOT_3, SLOT_4, SLOT_5, SLOT_6, SLOT_7, SLOT_8, SLOT_MAX } Slot;

struct SaveCtrl *func_02006F20(int heap)
{
    struct SaveCtrl *c;
    void *ov;
    u8 mode;
    int sub;
    int r;
    int s;
    Slot i;
    u32 *flags;

    func_02034AC4((int)ov228_id);
    ov = func_021DFC20(heap);
    mode = func_021DFE90(ov);
    sub = func_021DFE98(ov);
    func_021DFDB8(ov);
    func_02034A5C((int)ov228_id);
    c = (struct SaveCtrl *)func_02030734(heap, 0x38, 1, sub_02006F20_File, 0x58);
    sub_02006F20_Ptr = c;
    c->unk00 = 1;
    c->unk02 = 1;
    c->unk01 = 0;
    c->unk04 = mode;
    c->unk05 = sub;
    c->unk10 = func_0203192C(g_0209D938, heap);
    r = func_02031AE0(c->unk10, 1);
    if ((u32)(r - 1) <= 1 && sub_02008754(c) == 1)
        r = 0;
    c->unk0C = 0;
    if (sub == 1)
        c->unk0C |= 0x800;
    switch (r) {
    case 1:
        c->unk02 = 0;
    case 2:
        c->unk00 = 0;
        c->unk01 = 1;
        if (r == 2)
            c->unk0C |= 1;
        i = 0;
        if (i < SLOT_MAX) {
            flags = &c->unk0C;
            do {
                if (sub_02008784(c, i) == 1) {
                    s = sub_0200725C((struct Ctrl *)c, i, 1);
                    sub_020072A4((struct Sub020072A4Ctrl *)c, i);
                    switch (s) {
                    case 1:
                    case 2:
                        if (i == 6)
                            sub_0200A7EC(sub_0200A5F8(c), 1);
                        break;
                    case 0:
                    case 3:
                    case 4:
                        *flags |= 1 << (i + 2);
                        if (i == 6)
                            sub_0200A7EC(sub_0200A5F8(c), 0);
                        break;
                    }
                } else if (i == 6) {
                    sub_0200A7EC(sub_0200A5F8(c), 0);
                }
                i++;
            } while (i < SLOT_MAX);
        }
        break;
    case 3:
        c->unk0C |= 2;
    case 0:
    case 4:
        func_020319C0(c->unk10);
        break;
    default:
        func_02034714(sub_02006F20_Msg, 0, sub_02006F20_Msg);
        break;
    }
    return c;
}

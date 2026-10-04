/*
 * function: func_0204DEE8
 * address:  0x0204DEE8
 * packet:   pkt_0204DD08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_020637D4  0x020637D4  arm
 *   func_0204D9B4  0x0204D9B4  arm
 *   func_02063F4C  0x02063F4C  arm
 *   func_02080C34  0x02080C34  arm
 *   func_02080C74  0x02080C74  arm
 *   func_0208068C  0x0208068C  arm
 *   func_020801F8  0x020801F8  arm
 *   func_0208083C  0x0208083C  arm
 *
 * The one-surface sibling of func_0204DD08 (same entry table, same 0x200
 * large-layer split, same bracketed double upload through func_0204D9B4's
 * engine select), uploading through func_02063F4C instead of func_02063E54.
 * Returns nothing: the trailing read-modify-write leaves r0 as garbage.
 *
 * Levers, all measured (wave 10): the two out-locals are declared `b` then
 * `a` (func_02062A98's out first), which puts `a` at sp+4 as the image has
 * it; and the 0x200 test is written small-arm-first
 * (`if (size < 0x200) flag = 0; else {...}`), which is what orders the
 * predicated `movlo sl,#0` before `movhs sl,#1`.  Either alone leaves 4-6
 * bytes out.  `off = idx * sizeof(struct Ent)` as a byte-offset local and
 * the entry re-derived from h->ents at the end are func_0204DD08's pins.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent    { u8 pad_00[0x14]; u32 unk_14; };
struct Holder { u8 pad_00[0xc]; struct Ent *ents; };

typedef signed int     s32;
struct NitroFileHeader;
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020637D4(struct Ent *ent);
extern u32 func_0204D9B4(u32 a, u32 b);
extern void func_02063F4C(void *b, void *a, u32 size, int mode, struct Ent *ent);
extern u16 func_02080C34(void);
extern u16 func_02080C74(void);
extern void func_0208068C(void);
extern void func_020801F8(int objExtPltt);
extern void func_0208083C(int sub_objExtPltt);

void func_0204DEE8(struct Holder *h, int idx, void *src, void *sel, u32 size)
{
    void *b;
    void *a;
    u32 off;
    struct Ent *ent;
    int flag;
    u32 saved;

    off = idx * sizeof(struct Ent);
    ent = (struct Ent *)((u8 *)h->ents + off);
    if (size < 0x200) {
        flag = 0;
    } else {
        size = (u16)(size - 0x200);
        flag = 1;
    }

    func_02062AD4(src, &a);
    if (!func_02062A98(src, &b)) {
        return;
    }
    func_020637D4(ent);

    if (func_0204D9B4((u32)sel, 0)) {
        saved = func_02080C34();
        if (flag) func_0208068C();
        func_02063F4C(b, a, size, 1, ent);
        if (flag) func_020801F8(saved);
    }
    if (func_0204D9B4((u32)sel, 1)) {
        saved = func_02080C74();
        if (flag) func_0208068C();
        func_02063F4C(b, a, size, 2, ent);
        if (flag) func_0208083C(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
}

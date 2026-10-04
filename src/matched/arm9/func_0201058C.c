/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_0201058C
 * address:  0x0201058C
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  label/overlay 0x02178098.  The `bl` at +0x5C targets an
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02178098 as .word data (0x680B4909), and this call is
 *           the only branch to it in the image.  SEED REQUEST: `ov014
 *           0x02178098 thumb`, evidence the bl at arm9 0x020105E8.  Every
 *           other site resolves and every concrete byte matches (520 of 520).
 *
 * symbols:
 *   g_021461E0     0x021461E0  data
 *   func_0203D798  0x0203D798  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CF10  0x0203CF10  arm
 *   func_0205D01C  0x0205D01C  arm
 *   func_02178098  0x02178098  thumb  ov014
 *   sub_020107FC   0x020107FC  thumb
 *   sub_020104F8   0x020104F8  thumb
 *   func_0201054C  0x0201054C  thumb
 *   func_0201057C  0x0201057C  thumb
 *
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in sub_020107FC, the connection state byte +0x67
 * and slot count +0x62 of the func_0203D798 context, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * func_0201045C fills, arming the four countdowns at +0x318..+0x324 that
 * sub_02010498 decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.
 *
 * Two declaration facts close it: func_0205D01C's third argument is a
 * 0x40-byte out record whose first word is the switch key (the frame is
 * sub sp,#0x60 plus the r3 pad; an `int *` gives sub sp,#0x24), and the
 * switch has explicit empty arms for 7 and 9 so the 13-entry halfword table
 * exists (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201058C.c \
 *       --func func_0201058C --addr 0x0201058C --thumb
 */
#include "../include/Obj03426.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021461E0;

extern void *func_0203D798(void);
extern int  func_0203D1B4(void);
extern u32 func_0203CF10(u32 a);
extern u8   func_02178098(u8 i);
struct WihInfo {
    int kind;          /* +0x00 */
    u8  rest[0x3C];    /* +0x04 */
};

extern int  func_0205D01C(u32 buf, u8 *rec, struct WihInfo *out);
extern int  sub_020107FC(void *key);
extern int  sub_020104F8(u8 *rec);
extern int func_0201054C(const u8 *obj);
struct Ctx;
extern u32  func_0201057C(const struct Ctx *rec);

u32 func_0201058C(void *key)
{
    u32 flags = 0;
    u8 *st = func_0203D798();
    int i;
    int j;
    u8 *rec;
    struct WihInfo info;
    u8 s;

    if (g_021461E0 == 0)
        return flags;

    if (sub_020107FC(key) != -1)
        flags |= 8;
    if (st[0x67] == 2 && func_0203D1B4() > 1)
        flags |= 4;

    for (i = 0; i < st[0x62]; i++) {
        if (func_0203CF10(i) != 0) {
            s = func_02178098(i);
            if (s >= 0x14 && s <= 0x1B)
                flags |= 0x10;
            else if (s == 9)
                flags |= 0x20;
        }
    }

    for (j = 0; j < *(u16 *)(g_021461E0 + 0x316); j++) {
        rec = g_021461E0 + j * 0xC0;
        if (sub_020104F8(rec)) {
            *(int *)(g_021461E0 + 0x318) = 600;
        } else if (func_0201054C(rec)) {
            *(int *)(g_021461E0 + 0x31C) = 600;
        } else if (func_0205D01C(*(u32 *)(g_021461E0 + 0x300), rec, &info)) {
            switch (info.kind) {
            case 0: case 1: case 2: case 3:
            case 10: case 11: case 12:
                *(int *)(g_021461E0 + 0x318) = 600;
                break;
            case 4: case 5: case 6: case 8:
                *(int *)(g_021461E0 + 0x31C) = 600;
                break;
            case 7: case 9:
                break;
            }
        } else if (((struct Obj03426 *)rec)->fA != 0) {
            if (func_0201057C((const struct Ctx *)rec) == 0)
                *(int *)(g_021461E0 + 0x320) = 400;
            else
                *(int *)(g_021461E0 + 0x324) = 400;
        }
    }

    if (*(int *)(g_021461E0 + 0x318) > 0)
        flags |= 0x40;
    if (*(int *)(g_021461E0 + 0x31C) > 0)
        flags |= 0x80;
    if (*(int *)(g_021461E0 + 0x320) > 0)
        flags |= 0x100;
    if (*(int *)(g_021461E0 + 0x324) > 0)
        flags |= 0x200;
    if (*(u16 *)(g_021461E0 + 0x30E) != 0)
        *(u16 *)(g_021461E0 + 0x30E) = *(u16 *)(g_021461E0 + 0x30E) - 1;

    if (flags == 0) {
        *(u16 *)(g_021461E0 + 0x312) = 0;
    } else if (*(u16 *)(g_021461E0 + 0x314) != 0 && *(u16 *)(g_021461E0 + 0x30E) == 0) {
        *(u16 *)(g_021461E0 + 0x312) = *(u16 *)(g_021461E0 + 0x314);
        *(u16 *)(g_021461E0 + 0x30E) = 400;
        *(u16 *)(g_021461E0 + 0x314) = 0;
    }
    *(u16 *)(g_021461E0 + 0x316) = 0;
    return flags | 2;
}

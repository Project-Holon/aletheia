/*
 * function: func_021BE658
 * address:  0x021BE658
 * packet:   pkt_021BE658
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_HideCursor   0x021B941C  thumb
 *   func_0200CA54   0x0200CA54  thumb
 *   func_021B940C   0x021B940C  thumb ov133
 *   d_021BEAE0      0x021BEAE0  data
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *
 * MATCH (byte-correct, 1 relocation site wildcarded).  All concrete bytes
 * reproduce exactly.
 *   +001C / +00B4  func_0200CA54: declared `thumb` (it was inferred ARM from
 *       the name); it is a member function of the EXACT game_unit
 *       src/matched/unit_0200C9EC.c (pkt_0200C9F4), so `matched` now carries
 *       both sites.  The earlier "unlabelled leaf" reading was wrong: it is
 *       unlabelled in the listing, but the unit source already reproduces it.
 *   +0070  FRAME_LIST_HideCursor (thumb): 0x021B941C is interior to func_021B940C in
 *       ov133 (no `func_` label at it anywhere), so `label`/`sole-ref/code`
 *       refuse it.  Needs that address seeded as a start, or a matched entry.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int TOUCHPANEL_HitTrg(const void *p);
struct Blk37;
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern u8 func_020355C4(void);
extern u32 func_0200CA54(struct Blk37 *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern void FRAME_LIST_HideCursor(u32);
extern int func_021B940C(u8 *p);

int func_021BE658(void *ctx_)
{
    u8 *ctx = (u8 *)ctx_;
    int v = TOUCHPANEL_HitTrg((void *)0x021BEAE0);

    if (v != -1) {
        if (v == 8) {
            if (func_0200CA54((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 0)
                return -1;
        }
        if (v == 9) {
            if (func_0200CA38((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 0)
                return -1;
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
        }
        if (v == 0xa) {
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
            if (func_020355C4() == 0) {
                func_020355D8(1);
                FRAME_LIST_HideCursor(*(u32 *)(ctx + 0xC2C));
            }
        }
        func_020355D8(1);
        return v;
    } else {
        if (func_020362DC() & 2) {
            func_020355D8(0);
            return 0xc;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0xb;
        }
        if (func_020362DC() & 8) {
            if (func_0200CA54((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 1) {
                func_020355D8(0);
                return 8;
            }
        }
        if (func_020362DC() & 4) {
            if (func_0200CA38((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 0)
                return -1;
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
            func_020355D8(0);
            return 9;
        }
        if (func_020362DC() & 0x800) {
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
            if (func_020355C4() == 1) {
                func_020355D8(0);
                func_021B940C((u8 *)(*(u32 *)(ctx + 0xC2C)));
            } else {
                func_020355D8(0);
            }
            return 0xa;
        }
        return v;
    }
}

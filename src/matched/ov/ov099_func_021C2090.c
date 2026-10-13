/*
 * function: func_021C2090
 * address: 0x021C2090
 * packet: pkt_ov099_021C2090
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Logic read from the listing: state at p+0x8F4 (1 -> clear, flag = 1, call func_020414AC(7)); loop i over 8 slots, idx = i + row(p+0x8EC)*8 + 1; mode = byte p[0x8CB+idx] ? (func_02009864(p->f4, idx-1, 9) != 0) : 2; sel = idx == p[0x8ED] 
 * 
 *  idx == p[0x8F3]; slot = idx == p[0x8ED] ? p[0x8EE] : 0; redraw when flag == 1 or sel; func_021C2224 then (mode != 2) func_021C2274 + BMP_WIN_MakeScreen + func_021C22E8, else the clear loop (func_02045770, BMP_Clear(.,0), BMP_WIN_TransferChars over the slot object and 2 sub objects at p+0x918+i*8+j*4). End: func_02041B6C(7), (6), BG_SYS_SetSubPlaneVisible(2,1), (8,1). Pool words verified against the listing.
 * 2026-10-05 wave D4 lane 04: EXACT. Fixes: window loads written as *(void **)(p + i*4 + 0x8F8) at each use (no w locals), px*16 and py*6 written inline at both calls (CSE temps, not named locals), px/py declared before sel.
 * func_021C2274 is called with 5 arguments here (p, obj, idx, slot, i) though its matched C reads 3; func_021C22E8 takes (p, window, idx, slot, x, y).
 * symbols:
 *   func_02009864 0x02009864 thumb
 *   func_021C2224 0x021C2224 thumb ov099
 *   func_021C2274 0x021C2274 thumb ov099
 *   func_021C22E8 0x021C22E8 thumb ov099
 *   func_020414AC 0x020414AC arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_021C2224(char *p, u32 a1, u32 a2, u32 mode, u8 slot);
extern void func_021C2274(char *p, void *window, int id, int slot, int i);
extern void func_021C22E8(char *p, void *window, int id, int flag, int x, int y);
extern void func_020414AC(u32 a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void func_021C2090(char *p)
{
    int i;
    int flag;
    int idx;
    int mode;
    int slot;
    int px;
    int py;
    int sel;

    if (*(int *)(p + 0x8F4) == 1) {
        *(int *)(p + 0x8F4) = 0;
        flag = 1;
        func_020414AC(7);
    } else {
        flag = 0;
    }
    for (i = 0; i < 8; i++) {
        idx = i + *(u8 *)(p + 0x8EC) * 8 + 1;
        if (*(u8 *)(p + 0x8CB + idx) != 0) {
            if (func_02009864(*(void **)(p + 4), idx - 1, 9) == 0) {
                mode = 0;
            } else {
                mode = 1;
            }
        } else {
            mode = 2;
        }
        px = i / 4;
        py = i % 4;
        if (idx == *(u8 *)(p + 0x8ED)) {
            slot = *(u8 *)(p + 0x8EE);
        } else {
            slot = 0;
        }
        if (idx == *(u8 *)(p + 0x8ED) || idx == *(u8 *)(p + 0x8F3)) {
            sel = 1;
        } else {
            sel = 0;
        }
        if (flag == 1 || sel == 1) {
            func_021C2224(p, (u8)(px * 16), (u8)(py * 6), (u8)mode, (u8)slot);
            if (mode != 2) {
                func_021C2274(p, *(void **)(p + i * 4 + 0x8F8), idx, slot, i);
                BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0x8F8));
                func_021C22E8(p, p + 0x918 + i * 8, idx, slot, px * 16, py * 6);
            } else {
                int j;
                BMP_Clear(func_02045770(*(void **)(p + i * 4 + 0x8F8)), 0);
                BMP_WIN_TransferChars(*(void **)(p + i * 4 + 0x8F8));
                for (j = 0; j < 2; j++) {
                    BMP_Clear(func_02045770(*(void **)(p + i * 8 + j * 4 + 0x918)), 0);
                    BMP_WIN_TransferChars(*(void **)(p + i * 8 + j * 4 + 0x918));
                }
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(6);
    BG_SYS_SetSubPlaneVisible(2, 1);
    BG_SYS_SetSubPlaneVisible(8, 1);
}

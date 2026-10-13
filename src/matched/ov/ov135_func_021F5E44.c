/*
 * function: func_021F5E44
 * address:  0x021F5E44
 * packet:   pkt_021F5E44
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
 * symbols:
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   func_021F5F9C  0x021F5F9C  thumb
 *   func_021F68A4  0x021F68A4  thumb
 *   func_021F5F60  0x021F5F60  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0xC4];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xD2C - 0xBF8];
    u32 arrows[2];
} Work;

extern const u8 tbl_02202DA4[][4];

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021F5F9C(int a, int b, int c);
extern void func_021F68A4(Work *p, int box);
extern void func_021F5F60(u32 cursor, int i);

void func_021F5E44(Work *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(moved);
        func_020061E4(0x548);
        return;
    }
    if (func_020362DC() & 0x40) {
        dir = 1;
    } else if (func_020362DC() & 0x80) {
        dir = 2;
    } else if (func_020362DC() & 0x20) {
        dir = 3;
    } else if (func_020362DC() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                func_0204B92C((struct Obj *)p->arrows[k], 1);
                CLACT_SetActorAnimSeq((struct Obj *)p->arrows[k], k + 0x26);
                p->box = func_021F5F9C(p->box, p->boxes, dir - 0x64);
                func_021F68A4(p, p->box);
                func_020061E4(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        func_020061E4(0x548);
    }
    func_021F5F60(p->cursor, p->slot);
}

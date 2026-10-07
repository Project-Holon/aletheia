/*
 * function: func_021C553C
 * address:  0x021C553C
 * packet:   pkt_ov021_021C553C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   func_020202EC 0x020202EC thumb
 *   func_02020350 0x02020350 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_021C5440 0x021C5440 thumb ov021
 *   func_021C54C8 0x021C54C8 thumb ov021
 *   func_020200CC 0x020200CC thumb
 *   func_02020344 0x02020344 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0200C480 0x0200C480 thumb
 *   func_021C59A8 0x021C59A8 thumb ov021
 *   func_021C58CC 0x021C58CC thumb ov021
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021C577C 0x021C577C thumb ov021
 *   func_020202FC 0x020202FC thumb
 */
#include "../../../matched/include/Obj00523.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Obj;
extern void func_020355D8(u8 v);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern u32 func_02020350(struct Obj *obj, u32 what);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021C5440(char *p, int b, int c, int *d);
extern void func_021C54C8(int *a, int b, int c, int *d);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020344(struct Obj *obj, u32 n);
extern void func_020061E4(u32 se);
extern u8 func_0200C480(u8 *a, int id, u8 pos);
extern int func_021C59A8(u32 a, u32 b, u32 c);
extern void func_021C58CC(char *p, u16 a, u16 b, u32 heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021C577C(void *list, int a, int b);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);

void func_021C553C(char *p)
{
    int flag;
    u16 c[2];
    u16 b[2];
    u16 a[2];
    int redraw;
    int sel;
    u32 n;
    int i;

    sel = -1;
    redraw = 0;
    flag = 0;
    func_020355D8(0);
    func_020202EC(((struct Obj00523 *)p)->f4, &c[1]);
    n = func_02020350(((struct Obj00523 *)p)->f4, 2);
    if (func_0203633C() & 0x40) {
        func_021C5440(p, c[1], n, &flag);
    } else if (func_0203633C() & 0x80) {
        func_021C54C8((int *)p, c[1], n, &flag);
    }
    if (flag == 0) {
        sel = func_020200CC(((struct Obj00523 *)p)->f4);
    }
    if (sel == -1) {
        if (func_020362DC() & 0x400) {
            sel = -2;
            func_020061E4(0x551);
        } else if (func_020362DC() & 0x800) {
            func_020202EC(((struct Obj00523 *)p)->f4, &c[0]);
            sel = func_02020344(((struct Obj00523 *)p)->f4, c[0]);
            func_020061E4(0x54C);
        } else if ((func_020362DC() & 4) && ((struct Obj00523 *)p)->f24 == 1) {
            func_020202EC(((struct Obj00523 *)p)->f4, &b[1]);
            sel = func_02020344(((struct Obj00523 *)p)->f4, b[1]);
            func_020061E4(0x54C);
        }
    }
    if (((struct Obj00523 *)p)->f24 == 0) {
        ((struct Obj00523 *)p)->f18 = sel;
    } else if (((struct Obj00523 *)p)->f24 == 1) {
        if (sel == -2) {
            redraw = 1;
        } else if (sel != -1) {
            sel = func_02020344(((struct Obj00523 *)p)->f4, (u16)(((struct Obj00523 *)p)->f1C + ((struct Obj00523 *)p)->f1E));
            func_020202EC(((struct Obj00523 *)p)->f4, &b[0]);
            if (((struct Obj00523 *)p)->f40 != 0) {
                sel = func_0200C480(((struct Obj00523 *)p)->f20, sel, 0xFF);
            } else {
                sel = func_0200C480(((struct Obj00523 *)p)->f20, sel, b[0]);
            }
            func_021C59A8((u32)p, (u32)(&a[0]), (u32)(&a[1]));
            if (b[0] - 1 == sel) {
                a[1]--;
            }
            func_021C58CC(p, a[0], a[1], ((struct Obj00523 *)p)->f34);
            redraw = 1;
        }
    }
    if ((func_020362DC() & 4) && ((struct Obj00523 *)p)->f24 == 0 && func_02020350(((struct Obj00523 *)p)->f4, 2) > 1) {
        func_020061E4(0x54C);
        redraw = 1;
    }
    if (redraw) {
        ((struct Obj00523 *)p)->f24 ^= 1;
        if (((struct Obj00523 *)p)->f24 == 0) {
            ((struct Obj00523 *)p)->f40 = 0;
            for (i = 0; i < 3; i++) {
                func_0204B3DC((struct Obj *)*(u32 *)(p + 0x28 + i * 4), 0);
            }
            func_021C577C(((struct Obj00523 *)p)->f4, 0, 0);
            return;
        }
        if (((struct Obj00523 *)p)->f24 == 1) {
            func_020202FC(((struct Obj00523 *)p)->f4, (u16 *)(p + 0x1C), (u16 *)(p + 0x1E));
            ((struct Obj00523 *)p)->f48 = 1;
        }
    }
}

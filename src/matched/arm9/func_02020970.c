/*
 * function: BMP_MENULIST_MoveCursor
 * address:  0x02020970
 * packet:   pkt_02020970
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_StepCursor  0x02020780  thumb
 *   BMP_MENULIST_EraseCursor  0x0202071C  thumb
 *   BMP_MENULIST_DrawCursor  0x020206C0  thumb
 *   BMP_MENULIST_ScrollRows  0x020208B8  thumb
 *   BMP_MENULIST_NotifyCursor  0x02020A34  thumb
 *   func_02045334  0x02045334  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_MoveCursor.c \
 *       --func BMP_MENULIST_MoveCursor --addr 0x02020970 --thumb
 *
 * Move the menu cursor count steps in direction dir (BMP_MENULIST_StepCursor does one
 * step and answers 0 = no move, 1 = cursor moved inside the window, 2 = the
 * list scrolled), then, if notify, redraw what changed.  Closed in wave 13
 * after the 2026-09-21 note (docs/notes/BMP_MENULIST_MoveCursor.c.txt) left it at 34
 * bytes out.  What closed it, in order of weight:
 *   - ALL THREE SCALAR PARAMETERS ARE NARROW (u8 here; u16 compiles the
 *     same).  u8 count is what gives the guard its `cmp r0,#0 / bls` with
 *     the reload from the home slot (u32 count gives `cmp #1 / blo` or folds
 *     onto r2); u8/u16 notify and dir are what schedule the three home
 *     stores ahead of the obj copy.
 *   - the guard is `i < count` with i already 0, around a do/while;
 *   - a skipped row (item value -3) re-runs the step WITHOUT advancing i:
 *     a goto to the top of the body, not a continue (continue reaches the
 *     condition);
 *   - `case 0: default: return 1;` written first; without case 0 the switch
 *     becomes a compare chain, with a separate default it duplicates.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem {
    u32 unk00;
    u32 unk04;
};

struct Obj {
    struct Elem *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8 pad10[0x40 - 0x10];
    u16 f40;
    u16 f42;
};

extern u8   BMP_MENULIST_StepCursor(struct Obj *obj, u8 dir);
extern void BMP_MENULIST_EraseCursor(struct Obj *obj, u32 n);
extern void BMP_MENULIST_DrawCursor(struct Obj *obj);
extern void BMP_MENULIST_ScrollRows(struct Obj *obj, int n, u32 flag);
extern void BMP_MENULIST_NotifyCursor(struct Obj *obj, void *arg);
struct Descriptor;
extern void func_02045334(struct Descriptor *win);

u32 BMP_MENULIST_MoveCursor(struct Obj *obj, u8 notify, u8 count, u8 dir)
{
    u8 acc;
    u8 moved;
    u8 i;
    u8 r;
    u16 saved;

    moved = 0;
    acc = 0;
    saved = obj->f42;
    i = 0;
    if (i < count) {
        do {
        again:
            r = BMP_MENULIST_StepCursor(obj, dir);
            acc |= r;
            if (r == 2) {
                moved++;
                if (obj->arr[obj->f40 + obj->f42].unk04 == (u32)-3)
                    goto again;
            }
            i++;
        } while (i < count);
    }
    if (notify != 0) {
        switch (acc) {
        case 0:
        default:
            return 1;
        case 1:
            BMP_MENULIST_EraseCursor(obj, saved);
            BMP_MENULIST_DrawCursor(obj);
            BMP_MENULIST_NotifyCursor(obj, 0);
            func_02045334((struct Descriptor *)obj->unk0C);
            break;
        case 2:
        case 3:
            BMP_MENULIST_EraseCursor(obj, saved);
            BMP_MENULIST_ScrollRows(obj, moved, dir);
            BMP_MENULIST_DrawCursor(obj);
            BMP_MENULIST_NotifyCursor(obj, 0);
            break;
        }
    }
    return 0;
}

/*
 * function: func_021A2564
 * address:  0x021A2564
 * packet:   pkt_ov021_021A2564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B53C  0x0204B53C  arm
 *   func_0204B528  0x0204B528  arm
 */

typedef struct { short x, y; } Pt;
typedef struct { char pad[0x774]; int *list; } Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 func_021A2C28(u8 *p);
void func_0204B53C(int a, Pt *p);
void func_0204B528(int a, Pt *p);

void func_021A2564(Obj *obj, int px, int py)
{
    int *p = obj->list;
    int h;
    int y;
    int x;
    Pt pt;

    if (p != 0) {
        x = (short)px;
        y = (short)py;
        do {
            h = func_021A2C28((u8 *)((int)p));
            func_0204B53C(h, &pt);
            pt.x = pt.x - x;
            pt.y = pt.y - y;
            func_0204B528(h, &pt);
            p = (int *)p[0x34 / 4];
        } while (p != obj->list);
    }
}

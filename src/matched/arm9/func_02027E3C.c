/*
 * function: func_02027E3C
 * address:  0x02027E3C
 * packet:   pkt_02027D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * app_taskmenu.c: the touch handler.  Builds a stack table of one
 * eight-pixel-tall hit rectangle per menu entry (0xff-terminated), hands it
 * to func_02035C08, and on a hit moves the cursor, repaints the old and the
 * new entry, and raises the confirm notification.
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02027B30  0x02027B30  thumb
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_02035C08(const void *key);
extern void func_020355D8(u8 v);
extern void func_02027B30(u32 item, u32 sub, int self);
extern void func_020061E4(u32 id);

void func_02027E3C(u8 *m)
{
    u8  rect[0x24];
    u32 top;
    u8  left;
    u8  i;
    int hit;
    int one;

    if (*(int *)(m + 0x2C) == 0) {
        top  = m[0x30];
        left = m[0x31];
    } else {
        top = (u8)(m[0x30] - m[0x32]);
        left = (u8)(m[0x31] - m[0x33] * m[0x24]);
    }

    for (i = 0; i < m[0x24]; i++) {
        rect[i * 4 + 0] = (u8)((left << 3) + m[0x33] * 8 * i);
        rect[i * 4 + 1] = (u8)((left << 3) + m[0x33] * 8 * (i + 1));
        rect[i * 4 + 2] = (u8)(top << 3);
        rect[i * 4 + 3] = (u8)(((top + m[0x32]) << 3) - 1);
    }
    rect[i * 4] = 0xff;

    hit = func_02035C08(rect);
    if (hit == ~0) {
        return;
    }
    one = 1;
    func_020355D8(one);
    func_02027B30(((u32 *)*(u32 **)(m + 0x18))[m[0]], *(u32 *)(m + 0x34), 0);
    m[0] = (u8)hit;
    *(int *)(m + 0xC) = one;
    func_02027B30(((u32 *)*(u32 **)(m + 0x18))[m[0]], *(u32 *)(m + 0x34), one);
    if (m[0] == 0) {
        func_020061E4(0x54C);
        return;
    }
    if (*(int *)(*(u8 **)(m + 0x1C) + m[0] * 0xC + 8) == 1) {
        func_020061E4(0x551);
        return;
    }
    func_020061E4(0x54C);
}

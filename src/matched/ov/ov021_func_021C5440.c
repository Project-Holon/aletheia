/*
 * function: func_021C5440
 * address:  0x021C5440
 * packet:   pkt_ov021_021C5440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Message-window step: opens the window and plays SE 0x548, or scrolls to
 * the cursor line. Load-bearing: int-typed line count (stops (c-1)-(n-1)
 * folding) and the u16 local for the line index.
 *
 * symbols:
 *   func_021C59A8  0x021C59A8  thumb  ov021
 *   func_021C58CC  0x021C58CC  thumb  ov021
 *   func_021C59F8  0x021C59F8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *msg;
    u8 pad8[0x1C];
    u32 f24;
    u8 pad28[0xC];
    u16 h34;
    u16 pad36;
    u8 pad38[8];
    u32 f40;
} S;

struct Obj;
extern u32 func_02020350(struct Obj *obj, u32 what);
extern void func_021C59A8(S *p, u32 a, u32 b);
extern void func_021C58CC(char *p, u16 a, u16 b, u32 heap);
extern void func_020061E4(u32 se);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_021C59F8(S *p, int v);

void func_021C5440(S *p, int mode, u32 c, u32 *done)
{
    int n;
    u16 tmp;
    u16 h;

    if (mode == 0) {
        n = func_02020350(p->msg, 3);
        func_021C59A8(p, 0, 0);
        func_021C58CC((char *)p, (c - 1) - (n - 1), n - 1, p->h34);
        if (p->f24 == 1)
            p->f40 = 1;
        func_020061E4(0x548);
        *done = 1;
    } else if (p->f40 == 1 && p->f24 == 1) {
        func_020202FC(p->msg, 0, &tmp);
        h = func_02020324(p->msg, tmp) >> 3;
        func_021C59F8(p, (h + 0xC) * 8);
        p->f40 = 0;
        *done = 1;
    }
}

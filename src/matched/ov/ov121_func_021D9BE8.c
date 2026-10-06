/*
 * function: func_021D9BE8
 * address: 0x021D9BE8
 * packet: pkt_ov121_021D9BE8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a Pair assignment.
 * symbols:
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x; int y; } Pair;
struct Bmp;
struct StrObj;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
void func_021D9BE8(u32 mode, const Pair *in, const void *bitmap, void *obj, int a, Pair *out)
{
    int x;
    int y;
    switch (mode) {
    case 0:
        *out = *in;
        return;
    case 1:
        x = (u32)func_020437DC(bitmap) / 2;
        y = (u32)func_020437E4(bitmap) / 2;
        x -= func_0201D304(obj, a, 0) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)func_020437E4(bitmap) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = func_020437DC(bitmap);
        x -= func_0201D304(obj, a, 0);
        if (x < 0) x = 0;
        out->x = x + in->x;
        out->y = in->y;
        break;
    }
}

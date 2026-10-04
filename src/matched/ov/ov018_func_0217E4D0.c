/*
 * function: func_0217E4D0
 * address:  0x0217E4D0
 * packet:   pkt_ov018_0217E4D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02025774  0x02025774  thumb
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B70(const struct BigObj *p);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_02025774(u8 *g, u32 a);

void func_0217E4D0(int *p)
{
    int h;

    h = (int)func_020120F4((const struct Ctx *)p[0]);
    if (*((u8 *)p + 0xe9) == 0 && func_02012B70((const struct BigObj *)h) == 1) {
        switch (p[0xdc / 4]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0204B3DC((struct Obj *)p[0x9c / 4], 0);
            func_02025774((u8 *)p[0xc0 / 4], 0);
            break;
        }
    }
}

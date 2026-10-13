/*
 * function: func_021C5BCC
 * address:  0x021C5BCC
 * packet:   pkt_ov111_021C5BCC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_02035C08  0x02035C08  arm
 *   TOUCHPANEL_HitPoint  0x02035D40  arm
 *   d_021C852C     0x021C852C  data  a1
 *   d_021C853C     0x021C853C  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
} Info;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

typedef struct {
    u8 pad0[0x28];
    Info *info;
    u8 pad2C[0x305C - 0x2C];
    u16 h305C;
    u8 pad305E[0x32EA - 0x305E];
    TouchPos raw;
    TouchPos cur;
    u8 pad32F2[0x32F6 - 0x32F2];
    u8 size;
    u8 pad32F7[0x330F - 0x32F7];
    u8 b330F;
} Work;

extern u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);
extern int func_02035C08(const void *rect);
struct Ctx;
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
extern const u8 d_021C852C[];
extern const u8 d_021C853C[];

void func_021C5BCC(Work *p, int side)
{
    u32 x, y;

    if (p->info->f4_5 || p->info->f4_4 == 1) {
        return;
    }
    if (TOUCHPANEL_GetPointCont(&x, &y)) {
        if (side == 0) {
            if (!func_02035C08(d_021C852C)) {
                p->b330F = 1;
            }
            if (p->b330F != 0 && !TOUCHPANEL_HitPoint((struct Ctx *)d_021C852C, x, y)) {
                p->raw.x = x;
                p->raw.y = y;
                p->raw.size = p->size;
                p->raw.active = 1;
                if (x < 0x80) {
                    p->h305C = 0;
                } else {
                    p->h305C = 1;
                }
            } else {
                p->raw.active = 0;
            }
        } else {
            if (!func_02035C08(d_021C853C)) {
                p->b330F = 1;
            }
            if (p->b330F != 0 && !TOUCHPANEL_HitPoint((struct Ctx *)d_021C853C, x, y)) {
                p->raw.x = ((x - 0x20) + p->h305C * 0xC0) / 2 + 0x20;
                p->raw.y = (y - 0x18) / 2 + 0x58;
                p->raw.size = p->size;
                p->raw.active = 1;
            } else {
                p->raw.active = 0;
            }
        }
    } else {
        p->raw.active = 0;
    }
    p->cur.x = p->raw.x;
    p->cur.y = p->raw.y;
    p->cur.size = p->raw.size;
    p->cur.active = p->raw.active;
}

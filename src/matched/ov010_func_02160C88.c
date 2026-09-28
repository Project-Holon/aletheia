/*
 * function: func_02160C88
 * address:  0x02160C88
 * packet:   pkt_ov010_02160C88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled (the listing folds it into func_02160A94's extent). Consume a
 * reply record: copy its result into the context and pick the next state.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Save {
    u8 pad00[0xC];
    u32 f0c;            /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
} Save;

typedef struct Ctx {
    u8 pad00[0xC];
    u32 state;          /* 0x0C */
    u8 pad10[0x18 - 0x10];
    Save *f18;          /* 0x18 */
    u8 pad1c[0x60 - 0x1C];
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u32 f64;            /* 0x64 */
    u32 f68;            /* 0x68 */
    u32 f6c;            /* 0x6C */
} Ctx;

typedef struct Req {
    u8 pad00[0x34];
    u32 f34;            /* 0x34 */
    u8 pad38[4];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
    u8 pad46[0x50 - 0x46];
    u32 f50;            /* 0x50 */
} Req;

int func_02160C88(Ctx *c, Req *r)
{
    c->f18->f2c = r->f3c;
    c->f60 = r->f3c;
    if (c->f6c == 1) {
        if (r->f3c == 8)
            return 1;
        return 0;
    }
    switch (r->f40) {
    case 0:
        if (r->f34 == 6 || c->f18->f0c == 2) {
            c->state = 2;
            return 4;
        }
        if (r->f3c == 8)
            return 1;
        return 0;
    case 1:
        c->state = 6;
        return 4;
    case 3:
        c->state = 2;
        return 4;
    case 10:
        c->state = 2;
        return 4;
    case 4:
    case 5:
        c->state = 6;
        c->f62 = r->f44;
        c->f64 = r->f50;
        return 4;
    case 6:
    case 7:
        c->state = 9;
        return 4;
    case 8:
    case 9:
        c->state = 10;
        c->f62 = r->f44;
        return 4;
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        c->f18->f28 = r->f40 - 11;
        return 2;
    case 15:
        c->state = 7;
        return 4;
    }
    return 1;
}

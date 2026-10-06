/*
 * function: func_02160A94
 * address:  0x02160A94
 * packet:   pkt_ov010_02160A94
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocate and fill the 0x98-byte request record for a link step: player
 * handles from the save, the 20-byte header copied out of the context, and
 * the next state (+0x34) chosen from the step kind and the peer's reply.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02030734  0x02030734  arm
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021C3E00  0x021C3E00  thumb  ov136
 *   ov136_id       0x00000088  data
 *   d_02172978     0x02172978  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Hdr20 {
    u32 w[5];
} Hdr20;

typedef struct Save {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
} Save;

typedef struct Ctx {
    u8 pad00[0x18];
    Save *f18;          /* 0x18 */
    u8 pad1c[0x4C - 0x1C];
    Hdr20 hdr;          /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u32 f64;            /* 0x64 */
    u32 f68;            /* 0x68 */
    u32 f6c;            /* 0x6C */
} Ctx;

typedef struct Src {
    u8 pad00[0xD];
    u8 f0d;             /* 0x0D */
    u8 pad0e;
    u8 f0f;             /* 0x0F */
    u8 pad10;
    u8 f11;             /* 0x11 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    u16 f14;            /* 0x14 */
    u8 pad16[0x2C - 0x16];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
} Src;

typedef struct Req {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0c[0x18 - 0x0C];
    void *f18;          /* 0x18 */
    Hdr20 hdr;          /* 0x1C */
    u16 f30;            /* 0x30 */
    u8 pad32[2];
    u32 f34;            /* 0x34 */
    u8 pad38[4];
    u32 f3c;            /* 0x3C */
    u8 pad40[4];
    u16 f44;            /* 0x44 */
    u16 f46;            /* 0x46 */
    u8 f48;             /* 0x48 */
    u8 pad49[0x50 - 0x49];
    u32 f50;            /* 0x50 */
    u8 pad54[0x5E - 0x54];
    u8 f5e;             /* 0x5E */
    u8 f5f;             /* 0x5F */
    u8 pad60[0x98 - 0x60];
} Req;

extern u8 ov136_id[];
extern const char d_02172978[];

typedef signed int     s32;
struct BigObj;
struct Sub02008F80Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_0200CA1C(void *sv);
extern u16 *func_020127A4(void *sv);
extern u8 func_02012984(const struct BigObj *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u32 func_021C3E00(u32 *p);

Req *func_02160A94(Ctx *c, int kind, int mode, Src *src)
{
    void *sv;
    Req *r;
    u32 v;

    sv = func_020120F4(*(void **)c->f18);
    r = func_02030734(4, 0x98, 1, d_02172978, 0x330);
    r->f00 = func_02012934(sv);
    r->hdr = c->hdr;
    r->f04 = func_0201292C(sv);
    r->f08 = func_02008FEC(sv);
    r->f18 = func_0200CA1C(sv);
    r->f34 = 0;
    r->f3c = c->f18->f2c;
    r->f46 = 0;
    v = 0xFF;
    r->f5e = v;
    r->f30 = *func_020127A4(sv);
    r->f5f = func_02012984(sv);
    if (kind == 5) {
        r->f3c = 0;
        r->f34 = 5;
        v += 0xD3;
        r->f44 = v;
        c->f6c = 1;
    } else if (mode == 0) {
        r->f3c = 0;
    } else if (mode == 2) {
        r->f44 = src->f38;
        if (src->f34 != 3 && src->f34 != 4 && src->f34 != 1 && src->f34 != 0x12)
            r->f3c = 0;
        switch (src->f34) {
        case 1:
            if (src->f2c == 2)
                r->f34 = 0;
            break;
        case 12:
            r->f34 = 0x10;
            break;
        case 2:
            r->f34 = 9;
            break;
        case 3:
        case 18:
            r->f34 = 10;
            break;
        case 4:
            r->f34 = 10;
            break;
        case 5:
            r->f34 = 5;
            break;
        case 6:
            r->f34 = 6;
            break;
        default:
            r->f34 = 9;
            break;
        }
    } else if (mode == 6) {
        switch (src->f12) {
        case 0:
        case 1:
            if (src->f0d == 2) {
                if (c->f68 == 6) {
                    r->f34 = 8;
                    r->f50 = c->f64;
                } else {
                    r->f34 = 7;
                }
                r->f44 = c->f62;
                r->f46 = src->f14;
                if (src->f12 == 0)
                    r->f48 = src->f11;
                else
                    r->f48 = 0xFF;
            } else {
                r->f34 = 0;
                r->f3c = src->f0f;
            }
            break;
        }
    } else if (mode == 9) {
        int res;

        func_02034AC4((u32)ov136_id);
        res = func_021C3E00((u32 *)src);
        func_02034A5C((u32)ov136_id);
        if (c->f68 == 0) {
            r->f34 = 0xB;
            r->f3c = c->f60;
            r->f44 = c->f62;
        } else if (c->f68 == 2) {
            if (res == 1) {
                r->f34 = 0xC;
                r->f3c = c->f60;
                r->f44 = c->f62;
            } else {
                r->f34 = 0;
                r->f3c = c->f60;
            }
        }
    } else if (mode == 10) {
        r->f34 = 5;
        r->f44 = c->f62;
    }
    return r;
}

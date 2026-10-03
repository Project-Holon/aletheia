/*
 * function: func_02160E08
 * address:  0x02160E08
 * packet:   pkt_ov010_02160E08
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocate and fill the 0x28-byte battle setup for mode 0 (from the
 * caller's record) or mode 6 (from the save, picking the first party
 * slot that passes the kind's checks). Levers: both source words read
 * into locals before the two stores, the kind == -1 arm written as the
 * else so it lands at the tail, func_0201AA18 returning int.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201897C  0x0201897C  thumb
 *   d_02172978     0x02172978  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Setup {
    void *party;        /* 0x00 */
    void *f04;          /* 0x04 */
    void *sys;          /* 0x08 */
    u8 f0c;             /* 0x0C */
    u8 f0d;             /* 0x0D */
    u8 count;           /* 0x0E */
    u8 slot;            /* 0x0F */
    u8 kind;            /* 0x10 */
    u8 pad11[3];
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
    u8 pad1C[4];
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
} Setup;

typedef struct Src {
    void *party;        /* 0x00 */
    u8 pad04[8];
    void *f0c;          /* 0x0C */
    u8 pad10[0x3C - 0x10];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 pad44;
    u16 f46;            /* 0x46 */
} Src;

typedef struct Holder {
    void *f00;
} Holder;

typedef struct Work {
    u8 pad00[0x18];
    Holder *f18;        /* 0x18 */
    u8 pad1C[0x68 - 0x1C];
    u32 f68;            /* 0x68 */
} Work;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Big;
struct BigObj;
struct Blk37;
struct Ctx;
struct Hdr;
struct Sub02008700Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200CA1C(void *sys);
extern u32 func_0200CA38(struct Blk37 *p);
extern int func_0201AA18(void *party);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *party, u32 i);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201897C(struct Hdr *p);
extern const char d_02172978[];

Setup *func_02160E08(Work *w, int kind, int mode, Src *src)
{
    Setup *s;
    void *sys;
    void *save;
    void *t;
    void *party;
    void *mon;
    void *link;
    int i;

    s = sub_02030734(4, sizeof(Setup), 1, d_02172978, 0x4DE);
    sys = func_020120F4(w->f18->f00);
    save = func_02012EBC(sys);
    t = func_0200CA1C(sys);
    s->f0c = 1;
    s->sys = sys;
    s->f24 = 0;
    s->f18 = func_0200CA38(t);
    if (mode == 0) {
        party = src->party;
        link = src->f0c;
        s->party = party;
        s->f04 = link;
        s->count = func_0201AA18(party);
        s->slot = src->f3c;
        switch (src->f40) {
        case 4:
            s->f14 = src->f46;
            s->f0d = 2;
            s->kind = 1;
            s->f20 = 0;
            w->f68 = 5;
            break;
        case 5:
            s->f14 = src->f46;
            s->f0d = 2;
            s->kind = 1;
            s->f20 = 0;
            w->f68 = 6;
            break;
        default:
            s->kind = 0;
            s->f0d = 0;
            s->f20 = 1;
            break;
        }
    } else if (mode == 6) {
        s->f04 = func_0200873C(save);
        s->party = func_02012934(sys);
        s->count = func_0201AA18(func_02012934(sys));
        s->slot = 0;
        s->f0d = 0;
        s->f20 = 1;
        if (kind != -1) {
            s->kind = kind;
            if (s->kind == 2) {
                party = func_02012934(sys);
                for (i = 0; i < func_0201AA18(party); i++) {
                    mon = func_0201AB28(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_0201897C(mon) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        s->slot = i;
                        break;
                    }
                }
            } else if (s->kind == 1) {
                party = func_02012934(sys);
                for (i = 0; i < func_0201AA18(party); i++) {
                    mon = func_0201AB28(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        s->slot = i;
                        break;
                    }
                }
            }
        } else {
            s->kind = 0;
        }
    }
    return s;
}

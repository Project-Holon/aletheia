/*
 * function: FLDMMDL_SysSearchUseMmdl
 * address:  0x0216DD1C
 * packet:   pkt_ov010_0216DD1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Iterator: advances *iter over the 0x100-byte records at +0x18 and
 * returns TRUE with *out set at the next record FLDMMDL_CheckStatusBit accepts.
 *
 * symbols:
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u8 data[0x100];
} Rec;

typedef struct Ctx {
    u8 pad[0x18];
    Rec *recs;
} Ctx;

extern u16 FLDMMDL_SysGetMmdlMax(void *p);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);

int FLDMMDL_SysSearchUseMmdl(Ctx *c, Rec **out, u32 *iter)
{
    u32 n;
    Rec *r;

    n = FLDMMDL_SysGetMmdlMax(c);
    if (*iter < n) {
        r = &c->recs[*iter];
        do {
            (*iter)++;
            if (FLDMMDL_CheckStatusBit((int)r, 1)) {
                *out = r;
                return 1;
            }
            r++;
        } while (*iter < n);
    }
    return 0;
}

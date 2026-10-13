/*
 * function: DSPi_MapAndLoadProcessImageCallback
 * address:  0x027054E4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSPi_ReadProcessImage 0x027053D4 arm twl
 *   DSPi_CommitWram 0x0270541C arm twl
 *   MI_GetWramMapStart 0x02730414 arm twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct Chan {
    u32 pad[5];
    void *file;
    u16 f18;
    u16 f1a;
    u32 f1c;
    u32 busy[2];
    u32 tabA[8];
    u32 tabB[8];
} Chan;
typedef struct Hdr {
    u16 pad0;
    u16 count;
    u32 pad4;
    u32 f8;
    u32 fC;
    u16 base;
} Hdr;
typedef struct Ent {
    u32 name0;
    u32 nameOff;
    u32 f8;
    u32 fC;
    u32 len;
    u32 off;
    u32 pad18[3];
    u32 flags;
} Ent;

static inline u32 clz32(u32 x)
{
    asm { clz x, x }
    return x;
}

extern s32 func_0208CD94(char *a, char *b);
extern s32 func_0208CC14(char *a, char *b);
extern void func_02082AC0(u32 v, void *dst, u32 n);
extern u32 MI_GetWramMapStart(s32 sel);
u32 DSPi_ReadProcessImage(Chan *p, u32 a, void *buf, s32 len);
u32 DSPi_CommitWram(Chan *c, s32 sel, u32 idx, s32 mode);

static inline void *chanPtr(Chan *c, s32 sel, s32 a)
{
    s32 q = a / 0x4000;
    s32 rem = a - q * 0x4000;
    u32 slot = sel == 1 ? c->tabA[q] : c->tabB[q];
    return (void *)(MI_GetWramMapStart(sel) + (slot << 15) + rem * 2);
}


s32 DSPi_MapAndLoadProcessImageCallback(Chan *c, Hdr *h, Ent *e)
{
    char buf[0x80];
    s32 selv[4];
    u32 sizev[4];
    u32 flagv[4];
    char *name = (char *)e;
    s32 ok = 1;
    s32 n = 0;
    s32 k;
    u32 size;
    s32 f;
    if (*(u32 *)name == 0) {
        u32 pos = h->f8 + h->fC * 0x12;
        if (!DSPi_ReadProcessImage(c, pos + e->nameOff, buf, 0x80)) {
            return n;
        }
        name = buf;
    }
    if (func_0208CD94(name, (char *)0x02732D54) == 0) {
        c->f1c |= 1;
    }
    if (e->flags & 8) {
        size = e->f8 * 2;
        f = (e->flags & 0x20) ? 1 : 0;
        if (func_0208CC14(name, (char *)0x02732D64)) {
            selv[n] = 1;
            sizev[n] = size;
            flagv[n] = f;
            n++;
        }
        if (func_0208CC14(name, (char *)0x02732D68)) {
            selv[n] = 1;
            sizev[n] = size + 0x20000;
            flagv[n] = f;
            n++;
        }
    }
    if (e->flags & 0x10) {
        size = e->fC * 2;
        f = (e->flags & 0x40) ? 1 : 0;
        if (func_0208CC14(name, (char *)0x02732D6C)) {
            selv[n] = 2;
            sizev[n] = size;
            flagv[n] = f;
            n++;
        }
        if (func_0208CC14(name, (char *)0x02732D70)) {
            selv[n] = 2;
            sizev[n] = size + 0x20000;
            flagv[n] = f;
            n++;
        }
    }
    for (k = 0; k < n; k++) {
        s32 sel = selv[k];
        s32 pos = sizev[k];
        s32 len = e->len;
        u32 off = e->off;
        while (len > 0) {
            s32 chunk = ((pos + 0x8000) & -0x8000) - pos;
            if (len <= chunk) {
                chunk = len;
            }
            if ((sel == 1 ? c->tabA[pos / 0x8000] : c->tabB[pos / 0x8000]) == (-0x8000 >> 15)) {
                s32 idx = pos / 0x8000;
                u16 *pm = sel == 1 ? &c->f18 : &c->f1a;
                u32 *busy = sel == 1 ? &c->busy[0] : &c->busy[1];
                u32 *tab = sel == 1 ? c->tabA : c->tabB;
                u32 x = *pm;
                s32 bit = 32 - clz32(~x & (x - 1));
                if (bit >= 8) {
                    ok = 0;
                    break;
                }
                tab[idx] = bit;
                *pm &= ~(1 << bit);
                *busy |= 1 << idx;
                if (!DSPi_CommitWram(c, sel, idx, 0)) {
                    ok = 0;
                    break;
                }
                func_02082AC0(0, chanPtr(c, sel, idx << 14), 0x8000);
            }
            if (flagv[k] == 0) {
                if (!DSPi_ReadProcessImage(c, off, chanPtr(c, sel, pos / 2), chunk)) {
                    ok = 0;
                    break;
                }
            }
            off += chunk;
            pos += chunk;
            len -= chunk;
        }
    }
    return ok;
}

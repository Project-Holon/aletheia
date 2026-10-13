/*
 * file:     unit_0206B7D0.c
 * unit:     yes
 * function: func_0206B7D0, func_0206B94C, func_0206BA18
 * address:  0x0206B7D0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *   g_02148DB4     0x02148DB4  data
 *   g_renderState     0x02148B4C  data
 *   g_020A1954     0x020A1954  data
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct Sub0206B7D0 Sub0206B7D0;

typedef struct Obj0206B7D0 Obj0206B7D0;

struct Sub0206B7D0 {
    u8    pad00[0x18];
    void *f18;
    u32 (*f1c)(u32 *out, void *ctx, u32 id);
    u8    pad20[0x4c - 0x20];
    u32   f4c[1];
};

struct Obj0206B7D0 {
    u8   *f00;
    Sub0206B7D0 *f04;
    u32   f08;
    u32   f0c;
    u32   f10;
    void (*f14)(Obj0206B7D0 *);
    u8    pad18[0x8e - 0x18];
    u8    f8e;
    u8    pad8f[0xac - 0x8f];
    u8    fac;
    u8    padad[0xb8 - 0xad];
    u32  *fb8;
    u8    padbc[0x184 - 0xbc];
    u32   f184;
};

typedef struct Obj0206B94C Obj0206B94C;

struct Obj0206B94C {
    u8   *f00;
    u32   f04;
    u32   f08;
    u32   f0c;
    u32   f10;
    u32   f14;
    void (*f18)(Obj0206B94C *);
    u8    pad1c[0x8f - 0x1c];
    u8    f8f;
};

typedef unsigned short u16;

typedef signed   short s16;

typedef struct Rec0206BA18 Rec0206BA18;

typedef struct Sub0206BA18 Sub0206BA18;

typedef struct Src0206BA18 Src0206BA18;

typedef struct Obj0206BA18 Obj0206BA18;

typedef struct Blob0206BA18 Blob0206BA18;

struct Rec0206BA18 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    s16 f20;
    s16 f22;
    u32 f24;
    u32 f28;
    u16 f2c;
    u16 f2e;
    u32 f30;
    u32 f34;
};

struct Sub0206BA18 {
    u32 f00;
    u32 f04;
    void *f08;
    void (*f0c)(Rec0206BA18 *, void *, u32);
    u8  pad10[0x38 - 0x10];
    Rec0206BA18 *f38;
    u32 f3c[1];
};

struct Src0206BA18 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u16 f1c;
    u16 f1e;
    u16 f20;
    u16 f22;
    u32 f24;
    u32 f28;
    u32 f2c;
};

typedef struct Ent0206BA18 {
    u8  pad00[0x1e];
    u16 f1e;
} Ent0206BA18;

typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} ResDict;

typedef struct {
    u16 sizeUnit;
    u16 ofsName;
    u8  data[4];
} EntryHdr;

struct Blob0206BA18 {
    u32     f00;
    ResDict dict;
};

struct Obj0206BA18 {
    u32   f00;
    Sub0206BA18 *f04;
    u32   f08;
    u8    pad0c[0x1c - 0x0c];
    void (*f1c)(Obj0206BA18 *);
    u8    pad20[0x90 - 0x20];
    u8    f90;
    u8    pad91[0xad - 0x91];
    u8    fad;
    u8    padae[0xb0 - 0xae];
    Rec0206BA18 *fb0;
    u8    padb4[0xbc - 0xb4];
    u32   fbc[(0xd8 - 0xbc) / 4];
    Blob0206BA18 *fd8;
    u8    paddc[0xf0 - 0xdc];
    void (*ff0)(Rec0206BA18 *);
    Rec0206BA18 ff4;
};

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
void func_0206B7D0(Obj0206B7D0 *p);
void func_0206B94C(Obj0206B94C *p);
void func_0206BA18(Obj0206BA18 *p, u32 kind, Src0206BA18 *src, u32 id);
extern u32  g_02148DB4[];
extern u32  g_renderState[];
extern u32  g_020A1954[];


/*
 * The three-byte opcode of the script object family (func_0206B94C is the
 * two-byte form one slot over).  Bit 9 of the flag word at +0x08 aborts; the
 * operand byte at f00[1] is cached at +0xac, bit 2 is set, the output cursor
 * at +0xb8 is pointed at the object's own +0x184 word, and the state byte at
 * +0x8e (read through the +0x14 hook, zero when the hook is null) selects
 * three stops.  Between stops 1 and 2 the value is produced either by the
 * sub-object's +0x1c resolver (guarded by its +0x18 handle and the bitmap at
 * +0x4c) or by f00[2] & 1, and after stop 2 bit 0 of the flag word mirrors
 * it.  The tail advances the program counter by three.
 *
 * 2.0/sp2 pin: docs/notes/func_0206B7D0.c.txt records a whole pass stuck at
 * 368 bytes against 380 under the project default dsi/1.1p1, diagnosed there
 * as the front end hoisting the `p->f14 ? p->f8e : 0` ternary above the field
 * stores.  It is not a source problem: this identical body is byte-exact
 * under ../2.0/sp2, the same front end its sibling func_0206B94C is pinned
 * to.
 */
void func_0206B7D0(Obj0206B7D0 *p)
{
    if (!(p->f08 & 0x200)) {
        u32 b;
        u32 st;
        u32 flag;

        b = p->f00[1];
        p->fac = b;
        p->f08 |= 4;
        p->fb8 = &p->f184;
        st = p->f14 ? p->f8e : 0;

        if (st == 1) {
            p->f08 &= ~0x40;
            p->f14(p);
            st = p->f14 ? p->f8e : 0;
            flag = p->f08 & 0x40;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            Sub0206B7D0 *s = p->f04;
            if (s->f18 == 0
                || (s->f4c[b >> 5] & (1u << (b & 0x1f))) == 0
                || s->f1c(p->fb8, s->f18, b) == 0) {
                p->fb8[0] = p->f00[2] & 1;
            }
        }
        if (st == 2) {
            p->f08 &= ~0x40;
            p->f14(p);
            st = p->f14 ? p->f8e : 0;
            flag = p->f08 & 0x40;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            if (*p->fb8) {
                p->f08 |= 1;
            } else {
                p->f08 &= ~1;
            }
        }
        if (st == 3) {
            p->f08 &= ~0x40;
            p->f14(p);
        }
    }
    p->f00 += 3;
}


/*
 * The two-byte opcode of the same script object func_0206B7D0 steps: bit 9
 * of the status word at +0x08 aborts, bit 0 gates the body, the state byte
 * at +0x8f (read through the +0x18 hook, zero when the hook is null) picks
 * the stop, and the tail advances the program counter at +0x00 by two.
 */
void func_0206B94C(Obj0206B94C *p)
{
    u32 v = p->f08;
    u32 st;
    u32 flag;

    if (!(v & 0x200) && (v & 1)) {
        st = p->f18 ? p->f8f : 0;
        if (st == 1) {
            p->f08 &= ~0x40;
            p->f18(p);
            st = p->f18 ? p->f8f : 0;
            flag = p->f08 & 0x40;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            u32 a = p->f00[1];
            if (!(p->f08 & 0x100)) {
                func_0206DDA4(0x14, &a, 1);
            }
        }
        if (st == 3) {
            p->f08 &= ~0x40;
            p->f18(p);
        }
    }
    p->f00 += 2;
}


static inline void *GetResDataByIdx(const ResDict *dict, u32 idx)
{
    if (dict != 0 && idx < dict->numEntry) {
        const EntryHdr *hdr = (const EntryHdr *)((const u8 *)dict + dict->ofsEntry);
        return (void *)((const u8 *)&hdr->data[0] + hdr->sizeUnit * idx);
    } else {
        return 0;
    }
}


static inline const Ent0206BA18 *GetMatDataByIdx(const Blob0206BA18 *mat, u32 idx)
{
    if (mat != 0) {
        const u32 *data = (const u32 *)GetResDataByIdx(&mat->dict, idx);
        if (data != 0) {
            return (const Ent0206BA18 *)((const u8 *)mat + *data);
        }
    }
    return 0;
}


/*
 * NitroSystem g3d SBC MAT opcode body, the internal default
 * (NNSi_G3dFuncSbc_MAT_InternalDefault shape): (rs, opFlag, matData, idxMat).
 * Resolves the 0x38-byte NNSG3dMatAnmResult (recorded / cached / scratch),
 * merges the material colours under the global state masks, reads the
 * optional texture-matrix trailer, then sends DIF_AMB/SPE_EMI/POLYGON_ATTR
 * and TEXIMAGE_PARAM/TEXPLTT_BASE as one packed-op buffer through
 * func_0206DDA4 (op word 0x00293130 = cmd[0], second op word 0x2b2a = cmd[4]).
 * Body from docs/notes/func_0206B7D0.c.txt (wave 7, 1164/127) with three
 * corrections that close it:
 *   - the material lookup is the NNS inline pair GetResDataByIdx (dict,
 *     `dict && idx < numEntry`, else 0) and GetMatDataByIdx with the NULL
 *     test of the material block INSIDE the inline and one shared
 *     `return 0` -- that shared return is the image's lone `mov r1,#0`
 *     that the b==0 guard branches to;
 *   - the texture-matrix trailer tests are NEGATED as NNS writes them
 *     (`if (!(flag & SCALEONE)) copy; else result->flag |= ...`), which is
 *     what if-converts the flag arm into ldrne/orrne/strne/bne;
 *   - the packed-op buffer: cmd[0] = 0x293130 passed as the op argument,
 *     cmd[4] = 0x2b2a (the old note had these two words swapped for a
 *     pointer to g_020A1954).
 */
void func_0206BA18(Obj0206BA18 *p, u32 kind, Src0206BA18 *src, u32 id)
{
    u32 st;
    u32 flag;
    Rec0206BA18 *r;
    u32 pkt[7];

    p->fad = id;
    p->f08 |= 8;
    p->fb0 = &p->ff4;
    st = p->f1c ? p->f90 : 0;

    if (st == 1) {
        p->f08 &= ~0x40;
        p->f1c(p);
        st = p->f1c ? p->f90 : 0;
        flag = p->f08 & 0x40;
    } else {
        flag = 0;
    }

    if (flag == 0) {
        Rec0206BA18 *base = p->f04->f38;

        if (base != 0 && !(p->f08 & 0x80)) {
            r = base + id;
        } else if ((kind == 0x20 || kind == 0x40)
                   && (p->fbc[id >> 5] & (1u << (id & 0x1f))) != 0) {
            if (base != 0) {
                r = base + id;
                goto done;
            }
            r = (Rec0206BA18 *)g_02148DB4 + id;
        } else {
            u16 m;
            const Ent0206BA18 *md;

            if (base != 0) {
                p->fbc[id >> 5] |= 1u << (id & 0x1f);
                r = p->f04->f38 + id;
            } else if (kind == 0x40) {
                p->fbc[id >> 5] |= 1u << (id & 0x1f);
                r = (Rec0206BA18 *)g_02148DB4 + id;
            } else {
                r = &p->ff4;
            }

            r->f00 = 0;

            md = GetMatDataByIdx(p->fd8, id);
            m = md->f1e;
            if (m & 0x20) {
                r->f00 |= 0x20;
            }

            r->f04 = (g_renderState[0x25] & ~g_020A1954[(src->f1e >> 6) & 7])
                   | (src->f04 & g_020A1954[(src->f1e >> 6) & 7]);
            r->f08 = (g_renderState[0x26] & ~g_020A1954[(src->f1e >> 9) & 7])
                   | (src->f08 & g_020A1954[(src->f1e >> 9) & 7]);
            r->f0c = (g_renderState[0x27] & ~src->f10) | (src->f0c & src->f10);
            r->f10 = src->f14;
            r->f14 = src->f1c;

            if (src->f1e & 1) {
                const u8 *q = (const u8 *)&src->f2c;

                if (!(src->f1e & 2)) {
                    const u32 *q32 = (const u32 *)q;
                    r->f18 = q32[0];
                    r->f1c = q32[1];
                    q += 2 * sizeof(u32);
                } else {
                    r->f00 |= 1;
                }
                if (!(src->f1e & 4)) {
                    const s16 *q16 = (const s16 *)q;
                    r->f20 = q16[0];
                    r->f22 = q16[1];
                    q += 2 * sizeof(s16);
                } else {
                    r->f00 |= 2;
                }
                if (!(src->f1e & 8)) {
                    const u32 *q32 = (const u32 *)q;
                    r->f24 = q32[0];
                    r->f28 = q32[1];
                } else {
                    r->f00 |= 4;
                }
                r->f00 |= 8;
            }

            if (p->f04->f08 != 0
                && (p->f04->f3c[id >> 5] & (1u << (id & 0x1f))) != 0) {
                p->f04->f0c(r, p->f04->f08, id);
            }
            if (r->f00 & 0x18) {
                r->f2c = src->f20;
                r->f2e = src->f22;
                r->f30 = src->f24;
                r->f34 = src->f28;
            }
        }
    done:
        p->fb0 = r;
    }

    if (st == 2) {
        p->f08 &= ~0x40;
        p->f1c(p);
        st = p->f1c ? p->f90 : 0;
        flag = p->f08 & 0x40;
    } else {
        flag = 0;
    }

    if (flag == 0) {
        r = p->fb0;
        if (r->f0c & 0x1f0000) {
            if (r->f00 & 0x20) {
                r->f0c &= ~0x1f0000u;
            }
            p->f08 &= ~2u;
            if (!(p->f08 & 0x100)) {
                pkt[0] = 0x293130;
                pkt[1] = r->f04;
                pkt[2] = r->f08;
                pkt[3] = r->f0c;
                pkt[4] = 0x2b2a;
                pkt[5] = r->f10;
                pkt[6] = r->f14;
                func_0206DDA4(pkt[0], &pkt[1], 6);
                if (r->f00 & 0x18) {
                    p->ff0(r);
                }
            }
        } else {
            p->f08 |= 2;
        }
    }

    if (st == 3) {
        p->f08 &= ~0x40;
        p->f1c(p);
    }
}

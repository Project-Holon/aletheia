/*
 * function: cert_item
 * address:  0x021602B8
 * packet:   pkt_ov009_021602B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  codegen, register allocation only.  Size 1192 B vs 1196 B; the
 *           whole switch, every arm including the recursive SEQUENCE/SET
 *           loops, the type==0xa0 default and the shared s+=len tail
 *           reproduce the vendor logic; ~245 concrete bytes differ.  The
 *           allocator mirrors the parameters (vendor level=r7, seq=r6,
 *           mode=r8, *ps=r4, &s=r5, len=r4; ours level=r8, seq=r7, mode=r6,
 *           *ps=r1, &s=r4, len=r5), so every arm's scratch registers and all
 *           branch displacements differ.  DWARF-order, source-order and
 *           grouped local declarations were tried (DWARF order is worse,
 *           714 B); `sub_seq`/`cert_date` naming did not move the params.
 *
 * lane T14 (2026-09-30): two fixes, size now 1196 = image, 714 -> 628
 *           concrete bytes (245 -> 228 rows).  (1) case 2, both seq arms:
 *           the object lays the `mode == 2` stores out *before* the
 *           `mode == 0` copy, so the arms are written `if (mode == 2) ...
 *           else if (mode == 0) ...` (mutually exclusive, semantics
 *           unchanged): -49 B.  (2) case 6: `object[i]` was loaded twice
 *           (strlen + memcmp); the object holds it in one register, so a
 *           `char *obj = (char *)object[i];` local is right: -37 B, and
 *           that is what made the size land on 1196.  Residue left: the
 *           parameter mirror (image level=r7, seq=r6, mode=r8, *ps=r4,
 *           &s=r5; ours r8/r7/r6/r1/r4) and, as a consequence, the branch
 *           *direction* in the two case-2 arms (image `cmp mode,#0 / beq
 *           copy-block`, ours `cmp mode,#2 / two streq / beq exit / cmp
 *           mode,#0 / bne exit`) plus the case-6 jump-table body order at
 *           +0244.
 *
 * sdk:      cert_item (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   cert_item_len  0x0216017C  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   cert_item      0x021602B8  arm  ov009
 *   strlen         0x0209477C  arm
 *   memcmp         0x020923F0  arm
 *   make_dn        0x021601CC  arm  ov009
 *   parse_time     0x02160238  arm  ov009
 *   object         0x021A1D48  data

 * lane U62 (2026-09-30): 1196/1196, 628 concrete (228 sites), unchanged. First divergence
 *           +000C `ldr r4, [fp]` | ours `ldr r1, [fp]`; the whole parameter map is rotated
 *           (image *ps into r4 and level/seq/mode into r7/r6/r8 where this draft has the
 *           parameters one slot apart), so every arm's scratch registers and all branch
 *           displacements follow. T14's two body fixes (case 2 arm order, case 6 `obj` local)
 *           still stand and are what took it to 1196. No new lever applies: the divergent
 *           regions are the switch arms' copy/spacing code, not intrinsic, zero-pool or
 *           alias-sensitive. Parked as the 4.0.0.1024/1025-class allocation rotation.
 *
 * lane wave8 (2026-09-30): confirmed the mirror is an allocator colouring tie, not
 *           source shape.  A named local for the dereference (`p = *ps; s = p + 1;
 *           type = *p;`, at block scope and at function scope, first/last among the
 *           declarations) reaches 1196 B / 626 concrete: it moves the *ps temporary
 *           off r1 into the callee-saved pool, but the allocator gives &s=r4 and
 *           *ps=r5 while the image has *ps=r4 and &s=r5 -- the same pair swap, and
 *           level/seq/mode stay r8/r7/r6 vs the image's r7/r6/r8.  Declaration order,
 *           block scope and initialiser-vs-bare spelling do not move the parameter
 *           rotation.  Reading `type` before `s` is worse (950 B), so the body order
 *           is right.  The draft body is kept at its faithful 628-byte form.
 */

struct _CPSSslConnection {
    unsigned char pad0[0x458];
    unsigned int f458;
    unsigned int f45c;
    unsigned char *f460;
    unsigned char *f464;
    unsigned char pad1[0x484 - 0x468];
    unsigned int f484;
    unsigned char *f488;
    unsigned int f48c;
    unsigned char *f490;
    unsigned char pad2[0x594 - 0x494];
    unsigned int f594;
    unsigned char pad3[0x5a0 - 0x598];
    unsigned int f5a0;
    unsigned char *f5a4;
    unsigned int f5a8;
    unsigned char f5ac;
    unsigned char f5ad;
    unsigned char f5ae;
    unsigned char f5af;
    unsigned char f5b0[0x5c];
    unsigned char pad4[0x80c - 0x60c];
    unsigned int f80c;
};

extern int cert_item_len(unsigned char **ps);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int strlen(char *s);
extern int memcmp(void *s1, void *s2, unsigned long n);
extern void make_dn(char *d, char *s, int len);
extern unsigned long parse_time(unsigned char *s, int type);
extern unsigned char *object[];

static int cert_item(struct _CPSSslConnection *con, unsigned char **ps,
                     int level, int seq, int mode)
{
    unsigned char *s;
    unsigned char *end;
    unsigned long cert_date;
    int len;
    int i;
    unsigned char type;
    char *iconnection;
    char *obj;

    iconnection = (char *)con;
    s = *ps + 1;
    type = **ps;
    len = cert_item_len(&s);
    if (len < 0 || len > 0x7d0)
        return 1;

    switch (type & 0x1f) {
    case 2:
        if (con->f5ad == 0)
            break;
        if (seq == 0) {
            while (*s == 0) {
                s++;
                len--;
            }
            if (mode == 2) {
                con->f484 = len;
                con->f488 = s;
            } else if (mode == 0) {
                if (len <= 0x100) {
                    MI_CpuCopy8(s, iconnection + 0x494, len);
                    con->f594 = len;
                }
            }
        } else if (seq == 1) {
            while (*s == 0) {
                s++;
                len--;
            }
            if (mode == 2) {
                con->f48c = len;
                con->f490 = s;
            } else if (mode == 0) {
                if (len <= 8) {
                    MI_CpuCopy8(s, iconnection + 0x598, len);
                    con->f5a0 = len;
                }
            }
        }
        break;
    case 3:
        i = 0;
        if (level == 1 && mode != 2) {
            con->f5a4 = s + 1;
            con->f5a8 = len - 1;
        }
        if (con->f5ad != 0) {
            s++;
            if (cert_item(con, &s, level, i, mode) != 0)
                return 1;
            con->f5ad = 0;
            goto done;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            obj = (char *)object[i];
            if (memcmp(s, obj, strlen(obj)) == 0) {
                switch (i) {
                case 1:
                case 2:
                    if (mode == 0)
                        con->f45c = i;
                    con->f5ad = i;
                    break;
                case 3:
                case 4:
                    if (mode != 2)
                        con->f458 = i;
                    break;
                case 5:
                    if (mode != 2)
                        con->f5ae = i;
                    break;
                }
                break;
            }
        }
        break;
    case 12:
    case 19:
    case 20:
    case 22:
        i = 0;
        if (mode != 2) {
            if (con->f5ac != 0) {
                make_dn(iconnection + 0x6b0, (char *)s, len);
                if (con->f5ae == 5 && len <= 0x4f) {
                    MI_CpuCopy8(s, iconnection + 0x7b0, len);
                    iconnection[0x7b0 + len] = 0;
                }
            } else {
                make_dn(iconnection + 0x5b0, (char *)s, len);
            }
        }
        con->f5ae = i;
        break;
    case 16:
        if (level == 0 && seq == 0 && mode != 2)
            con->f460 = s;
        end = s + len;
        for (i = 0; s < end; i++) {
            if (cert_item(con, &s, level + 1, i, mode) != 0)
                return 1;
        }
        if (level == 1 && seq == 0 && mode != 2)
            con->f464 = s;
        goto done;
    case 17:
        end = s + len;
        for (i = 0; s < end; i++) {
            if (cert_item(con, &s, level + 1, i, mode) != 0)
                return 1;
        }
        goto done;
    case 23:
    case 24:
        i = 1;
        cert_date = parse_time(s, type & 0x1f);
        if (mode != 2) {
            if (seq == 0) {
                if (con->f80c >= cert_date)
                    con->f5af = 1;
            } else {
                if (con->f80c > cert_date)
                    con->f5af = 0;
            }
        }
        s += len;
        con->f5ac = 1;
        goto done;
    default:
        if (type == 0xa0) {
            end = s + len;
            for (i = 0; s < end; i++) {
                if (cert_item(con, &s, level + 1, i, mode) != 0)
                    return 1;
            }
            goto done;
        }
        break;
    }

    s += len;
done:
    *ps = s;
    return 0;
}

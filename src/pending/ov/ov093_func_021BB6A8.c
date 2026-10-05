/*
 * function: func_021BB6A8
 * address:  0x021BB6A8
 * packet:   pkt_ov093_021BB6A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-05 (P17L9): best honest form is the indexed source s[j], 108/112 bytes, 26 differ
 *   (older notes in docs/notes/pkt_ov093_021BB6A8.c.txt). Colours, frame, pool zero, muls order all
 *   match; only the source load differs: original is `ldr r6,[r2]; adds r2,#4` (walking), the indexed
 *   form gives `ldr r6,[r2,r4]` and no bump. New finding: `for (j = 0; j < cnt; s++, j++) d[j] = s[j];`
 *   compiles to 112 bytes with 1 byte differing (load is still [r2,r4]) because a j-indexed source
 *   load keeps j in r0, cnt in r1, s in r2; every correct walking spelling (*s++, s[0]; s++, s++ in
 *   header, dp = &d[j] first, D-struct cursor, int j, const s, u32 * return type, s declared in block,
 *   do-while with guard, cnt inlined as n >> 2, cnt in for-init) gives j=r1,cnt=r2,s=r3 (51 bytes).
 *   The s[j] + s++ spelling reads s[2j], which the original does not, so it is not filed.
 *   Pragmas on the walking form: opt_lifetimes off 51, opt_propagation off 100, opt_common_subs off 69,
 *   opt_dead_assignments off 69. 18 compiles.
 *
 * symbols:
 *   func_021BB830  0x021BB830  thumb  ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 h; u32 x[2]; } E;
typedef struct { u32 v[3]; } D;
typedef struct {
    u8 pad0[0x14];
    E e[4];
    u8 pad1[0x70];
    D d[4];
    u8 c[4];
} P;

extern int func_021BB830(u8 *);
extern u32 func_021EEB64(void *, u32 *);

void func_021BB6A8(P *p)
{
    u32 i;
    u32 j;
    u32 n;
    u32 cnt;
    u32 *s;
    E *e;

    for (i = 0; i < 4; i++) {
        e = &p->e[i];
        p->c[i] = 0;
        if (func_021BB830((u8 *)e) != 0) {
            s = (u32 *)func_021EEB64((void *)e->h, &n);
            cnt = n >> 2;
            for (j = 0; j < cnt; j++) {
                p->d[i].v[j] = s[j];
                p->c[i]++;
            }
        }
    }
}

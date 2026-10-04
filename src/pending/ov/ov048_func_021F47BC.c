/*
 * function: func_021F47BC
 * address:  0x021F47BC
 * packet:   pkt_ov048_021F47BC
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * symbols:
 *   func_021F47BC  0x021F47BC  thumb  ov048
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   d_021F523C     0x021F523C  data  ov048  a4
 */

/*
 * 2026-10-04 (wave D2 lane05): DIFF, no change. Reading of the listing: the pool word 0x11A is loaded twice (ldr r0,[pc]) and the second use adds #2, and 0x7FFF sits in r6 for both heap-id builds. So the original does not CSE 0x11A across the first call, while this build keeps it in r6 (hence 0x7FFF in r4 and sum spilled). Needs a source form where 0x11A and 0x11C are not the same constant family, not tried beyond the variants above.
 */


/*
 * 2026-10-04 (wave D1 lane07): DIFF. Logic believed correct (404 vs 396 bytes).
 * Residue: in the original, 0x7FFF sits in r6 and sum in r4 (movs r4,#0 before the
 * first alloc call), 0x11A is reloaded (ldr; adds #2) for the second call. Mine hoists
 * 0x11A into r6 across the call, puts 0x7FFF in r4 and spills sum to [sp,#0x14]
 * (frame 0x18 and push r3 instead of 0x14). Tried: sum=0 placement, tag local u16/int/u32
 * with tag+2 or tag+=2, static inline heap helper, if/else-set instead of ternary
 * (that one fixed the compare shape).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct E {
    u8 b0;
    int f4;
    int f8;
    int fC;
    u32 f10;
    u16 h14;
    int f18;
    int f1C;
    int f20;
};

struct M {
    u16 h0;
    u8 b2;
    int f4;
    struct E **f8;
    int *fC;
    int f10;
    int f14;
    int f18;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
extern int func_0209C0A4(int a, int b);
extern void func_0204784C(u32 h, u16 i, int *v);
extern void func_020477A4(u32 h, u16 i);
extern void func_020477D4(u32 h, u16 i);
extern char d_021F523C[];

void func_021F47BC(struct M *p, int v)
{
    int *a;
    int *b;
    int i, sum, q, rem, j, t;
    struct E *e;

    q = v >> 12;
    sum = 0;
    a = (int *)func_02030734((u16)((p->h0 & 0x7FFF) | 0x8000), p->b2 * 4, 0, d_021F523C, 0x11A);
    b = (int *)func_02030734((u16)((p->h0 & 0x7FFF) | 0x8000), p->b2 * 4, 0, d_021F523C, 0x11C);
    p->f18 = v;
    for (i = 0; i < p->b2; i++) {
        p->fC[i] = 0;
        sum += p->f8[i]->f1C >> 12;
        if (i == 0) {
            a[i] = 0;
        } else {
            a[i] = a[i - 1] + (p->f8[i - 1]->f1C >> 12);
        }
    }
    if (p->b2 > 0) {
        rem = q % sum;
        for (i = 0; i < p->b2; i++) {
            e = p->f8[i];
            b[i] = rem - a[i];
            t = 0;
            if (b[i] > 0 && b[i] < (e->f20 >> 12)) {
                t = 1;
            }
            e->f4 = t;
            t = 0;
            if ((e->f1C >> 12) < b[i] && b[i] < (e->f20 >> 12)) {
                t = 1;
            }
            e->f8 = t;
            if (b[i] < 0) {
                b[i] = 0;
            }
            e->f18 = b[i] << 12;
            func_0204784C(e->f10, e->h14, &e->f18);
            if (e->f4) {
                func_020477A4(e->f10, e->h14);
            } else {
                func_020477D4(e->f10, e->h14);
            }
        }
    }
    if (p->b2 != 0 && q == 0) {
        e = p->f8[0];
        e->f4 = 1;
        func_020477A4(e->f10, e->h14);
    }
    for (i = 0; i < p->b2; i++) {
        j = (i + 1) % p->b2;
        t = 0;
        if (p->f8[i]->f8 != 0 && p->f8[j]->f4 == 0) {
            t = 1;
        }
        p->fC[j] = t;
    }
    func_020307B0(a);
    func_020307B0(b);
}

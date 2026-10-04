/*
 * function: func_021F3F30
 * address:  0x021F3F30
 * packet:   pkt_ov055_021F3F30
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x308-byte-offset object is typed as a struct (S) here: with raw
 * char* offsets the loop-invariant addresses are hoisted between two guards
 * and the else arm CSEs the load; struct member access matches.
 *
 * symbols:
 *   func_021F3B20  0x021F3B20  thumb  ov055
 *   func_021F3F9C  0x021F3F9C  thumb  ov055
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct E { char b[12]; } E;
typedef struct S {
    short lim[6];
    u8 n;
    u8 pad[13];
    E ent[2];
    short cnt[2];
} S;

extern u8 *func_021F3B20(char *);
extern void func_021F3F9C(const char *a, int b, const u16 *c, u8 *d, u16 e);

void func_021F3F30(S *p, char *q, int k)
{
    int i;

    for (i = 0; i < p->n; i++) {
        u8 *e;
        if (p->cnt[i] >= p->lim[k]) {
            e = func_021F3B20(q);
            if (e) {
                func_021F3F9C(q, (int)p, (const u16 *)(&p->ent[i]), e, 0);
                p->cnt[i] = 0;
            }
        } else {
            p->cnt[i]++;
        }
    }
}

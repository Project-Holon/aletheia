/*
 * function: HAND_SIDE_ToxicSpikesOnEnter
 * address:  0x068996D4
 * packet:   pkt_ov095_068996D4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * review 2026-10-05: parked for the user. EXACT* in c99 and c, but only with the cmpid() inline that
 *   returns a one-field struct to open an 8-byte frame hole; this may be a stand-in.
 * note:     2026-10-05 wave P14 C3. Older draft (docs/notes/pkt_ov095_068996D4.c.txt) was DIFF 18/172.
 *           The 12-byte frame (str r0,[sp] with sub sp,#0xc) comes from a one-field struct returned by an
 *           inline wrapper around the DE0 compare call; plain t pointer and unsigned loop counter (blo).
 *           Literal 3 gives the same bytes as a local n. Wrapping the other calls in a struct (alloc, id) also fits.
 * symbols:
 *   HAND_SIDE_GetStackCountByFactor  0x06898DE0  thumb
 *   func_06899780  0x06899780  thumb
 *   func_06899790  0x06899790  thumb
 *   func_068997A0  0x068997A0  thumb
 *   func_068997B0  0x068997B0  thumb
 *   func_068997C0  0x068997C0  thumb
 *   func_068997D0  0x068997D0  thumb
 *   func_068997E0  0x068997E0  thumb
 *   func_068997F0  0x068997F0  thumb
 *   func_06899800  0x06899800  thumb
 *   func_06899810  0x06899810  thumb
 *   func_06899820  0x06899820  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int HAND_SIDE_GetStackCountByFactor(int a, u32 b);
extern int func_06899780(int a);
extern int func_06899790(int a);
extern int func_068997A0(void *a, int b);
extern int func_068997B0(void *a, int b);
extern int func_068997C0(int a, int b);
extern u8 *func_068997D0(void *a, int b, int c);
extern void func_068997E0(void *a, void *t);
extern u32 *func_068997F0(void *a, int b, int c);
extern u32 func_06899800(void);
extern u32 func_06899810(void);
extern void func_06899820(void *a, void *q);

typedef struct { int v; } Id;
static inline Id cmpid(int a, u32 b) { Id r; r.v = HAND_SIDE_GetStackCountByFactor(a, b); return r; }

void HAND_SIDE_ToxicSpikesOnEnter(int a, void *p, int x)
{
    u8 v;
    u32 i;
    u8 *t;
    u32 *q;

    v = func_06899780(2);
    if (x == func_06899790(v) && func_068997A0(p, v) == 0) {
        if (func_068997C0(func_068997B0(p, v), 3) != 0) {
            t = func_068997D0(p, 0x1a, v);
            t[7] = x;
            t[4] = 3;
            for (i = 1; i < 3; i++)
                t[i + 4] = 0;
            if (t[4] > 1)
                t[5] |= 0x80;
            func_068997E0(p, t);
        } else {
            q = func_068997F0(p, 0xc, 0x1f);
            q[1] = 5;
            if ((u32)cmpid(a, x).v > 1)
                q[2] = func_06899800();
            else
                q[2] = func_06899810();
            *((u8 *)q + 0xf) = v;
            func_06899820(p, q);
        }
    }
}

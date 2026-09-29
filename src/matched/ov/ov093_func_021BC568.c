/*
 * function: func_021BC568
 * address:  0x021BC568
 * packet:   pkt_ov093_021BC568
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: the record array as p->e[i] of the S the EXACT twins use
 * (func_021BCA08, func_021BCAAC, func_021C804C: count at +0x782, 16-byte
 * records at +0x7e0), and the bitfield word read through an entry pointer
 * e = &p->e[i] (hoists p+0x7e0 into [sp+4] and reads e->b at #4); reading
 * p->e[i].b directly hoists p+0x7e4 instead and comes out 4 bytes short.
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E02DC  0x021E02DC  thumb  ov093
 *   func_021C6394  0x021C6394  thumb  ov093
 *   func_021E0394  0x021E0394  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 kind : 4; u32 pad : 3; u32 id : 16; u32 rest : 9; } B;
typedef struct { u8 *a; B b; u32 c; u32 d; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; } S;

extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(void *lock, u32 v, int line);
extern int func_021D59B4(void *p, int k);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
extern void func_021C6394(S *p, u8 *a, u16 key);
extern void func_021E0394(u8 *a, u16 key);

void func_021BC568(S *p)
{
    u32 lk = func_021CC8D8((u8 *)p + 0x1d74, 1425);
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 id;
        u8 *a;
        E *e;
        e = &p->e[i];
        if (e->b.kind == 1)
            id = e->b.id;
        else
            id = 0;
        if (id != 0) {
            a = p->e[i].a;
            if (func_021E02DC(a, id, func_021D59B4(a, 12))) {
                func_021C6394(p, a, id);
                func_021E0394(a, id);
            }
        }
    }
    func_021CC95C((u8 *)p + 0x1d74, lk, 0x5a0);
}

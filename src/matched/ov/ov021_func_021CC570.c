/*
 * function: func_021CC570
 * address:  0x021CC570
 * packet:   pkt_ov021_021CC570
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Launches overlay 0x6B (107) over an 8-byte record with the ov107 process
 * table at 0x021F6D78, parks the result in the script slot.
 *
 * MATCH, bytes exact. Blocker: the two pooled ABS32 words ov107_id (0x6B)
 * and d_021F6D78 (ov107 data, contested/no witness) have no witness, and
 * func_02014840 is not in match.py OVERLAY_ID_CONSUMERS, so the overlay-id
 * class refuses both. Dropping the ov107 token (data a4) does not help.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02014840  0x02014840  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   d_021DE5A8     0x021DE5A8  data
 *   ov107_id       0x0000006B  data
 *   d_021F6D78     0x021F6D78  data  ov107
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u8 f0;
    u8 pad1[3];
    u32 f4;
} Rec;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_0201210C(void *p);
extern Rec *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern u32 func_02014840(u32 sys, u32 x, u32 ovId, const void *proc, void *work, void *cb, void *rec);
extern void func_0215897C(u32 a, u32 b);
extern const char d_021DE5A8[];
extern const u8 d_021F6D78[];
extern u8 ov107_id[];

int func_021CC570(u32 unused, u32 a)
{
    void *s;
    void *sys;
    void *v;
    void *x;
    Rec *r;

    s = func_0215A5F4((void *)a);
    sys = func_0215A5DC((void *)a);
    v = func_0215A5E4((void *)a);
    x = func_0201210C((void *)sys);
    r = func_02030734(4, 8, 0, d_021DE5A8, 0x44);
    r->f0 = 0;
    r->f4 = v;
    func_0215897C(s, func_02014840(sys, x, (u32)ov107_id, d_021F6D78, r, 0, r));
    return 1;
}

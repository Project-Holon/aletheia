/*
 * function: func_021C2C44
 * address:  0x021C2C44
 * packet:   pkt_ov208_021C2C44
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note: 2026-10-04 (D2-13): also tried pos as `ObjPos pos[1]` passed as the array (same codegen, 12 bytes out). add r7,sp,#0x10 still lands after the memset call.
 * note:     2026-10-02 lane C2-02: only the placement of the hoisted 'add r7, sp, #0x10' differs (image computes it before the memset call; tried pointer local, u16 buf cast, declaration-time init).
 * note:     2026-10-04 (D1-08): also tried `ObjPos *pp = &pos` assigned just before the memset with fields stored through pp
 *            (86 bytes out: the call then passes r7 instead of a fresh `add r0, sp, #0x10`). The image passes a fresh
 *            sp+0x10 at both the memset and the func_0204B294 call yet stores the fields through r7.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B92C  0x0204B92C  arm
 *   data_021C8704  0x021C8704  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} ObjPos;

extern const u8 data_021C8704[7][9];
extern int func_020490F4(u32 id, u16 heap);
extern s32 func_0204AC18(int a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204A6C8(int a, u32 b, u32 c, u32 d, u16 e);
extern s32 func_0204AF28(int owner, u32 first, u32 second, u32 mode);
extern void func_02049238(int a);
extern void func_02082BCC(void *dst, int v, u32 n);
extern u32 func_0204B294(u32 res, u32 a, u32 b, u32 c, ObjPos *pos, u32 f, u32 heap);
extern void func_0204B3DC(u32 obj, int on);
extern void func_0204B688(u32 obj, u32 on);
extern void func_0204B92C(u32 obj, int v);

struct S {
    u32 f0;
    u8 pad4[0x80];
    int a84[6];
    u32 a9c[7];
};

void func_021C2C44(u16 *heap, struct S *st)
{
    int arc;
    u8 i;
    ObjPos pos;

    arc = func_020490F4(0x9f, *heap);
    i = 0;
    st->a84[1] = func_0204AC18(arc, 3, 0, 0, 0, 4, *heap);
    st->a84[0] = func_0204A6C8(arc, 0xd, 0, 0, *heap);
    st->a84[2] = func_0204AF28(arc, 0x1b, 0x2c, *heap);
    st->a84[4] = func_0204AC18(arc, 8, 1, 0x40, 0, 1, *heap);
    st->a84[3] = func_0204A6C8(arc, 0x18, 0, 1, *heap);
    st->a84[5] = func_0204AF28(arc, 0x1e, 0x2f, *heap);
    func_02049238(arc);
    func_02082BCC(&pos, 0, 8);
    do {
        const u8 *e = data_021C8704[i];
        pos.a = e[0];
        pos.b = e[1];
        pos.c = e[2];
        pos.d = e[3];
        pos.e = e[4];
        st->a9c[i] = func_0204B294(st->f0, st->a84[e[5]], st->a84[e[6]], st->a84[e[7]], &pos, e[8], *heap);
        func_0204B3DC(st->a9c[i], 1);
        func_0204B688(st->a9c[i], 1);
        i++;
    } while (i < 7);
    func_0204B92C(st->a9c[6], 1);
}

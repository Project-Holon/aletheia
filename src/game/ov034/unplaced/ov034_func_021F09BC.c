/*
 * function: func_021F09BC
 * address:  0x021F09BC
 * packet:   pkt_ov034_021F09BC
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  label (arm9 leaf). Every byte agrees; the one wildcard is the
 *   bl to func_020071C0, an unlabelled arm9 Thumb tail-call stub
 *   (ldr r0,[r0,#0x10]; ldr r3,[pc]; bx r3; .word 0x02031E69) with no
 *   witness outside this range. It is the integrator's. Verified leaf C
 *   (match.py one --thumb, no --region: MATCH, byte-correct, its own
 *   pool word to func_02031E68 unwitnessed):
 *     extern u32 func_02031E68(void *p);
 *     u32 func_020071C0(char *p) { return func_02031E68(*(void **)(p + 0x10)); }
 *
 * note 2026-10-05: the blocker leaf is now filed as src/matched/arm9/func_020071C0.c
 * (EXACT, verified with match.py one; its pool word to func_02031E68 needs the arm symbols line). This
 * file stays MATCH until the integrator regenerates the manifest so the witness resolves;
 * then it is EXACT with no change to the C.
 *
 * symbols:
 *   func_021F09BC 0x021F09BC thumb
 *   func_020071C0 0x020071C0 thumb
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern u32 func_020071C0(char *p);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204A600(void);
extern void func_0204A648(void);

void func_021F09BC(void *task, char *p)
{
    u32 t;

    if (*(int *)(p + 0x110) != 0) {
        t = func_020071C0(*(void **)(p + 4)) << 8;
        if (*(u16 *)(p + 0x126) != 8)
            (*(u16 *)(p + 0x126))++;
        if (t >= *(u32 *)(p + 0x11C) && *(u16 *)(p + 0x126) == 8
            && *(u16 *)(p + 0x124) < 10) {
            *(u32 *)(p + 0x11C) += *(u32 *)(p + 0x120);
            *(u16 *)(p + 0x126) = 0;
            func_0204B8C4(((void **)(p + 0x54))[*(u16 *)(p + 0x124) + 6], 0);
            func_0204B878(((void **)(p + 0x54))[*(u16 *)(p + 0x124) + 6], 1);
            func_0204B92C(((void **)(p + 0x54))[*(u16 *)(p + 0x124) + 6], 1);
            (*(u16 *)(p + 0x124))++;
        }
        func_0204A600();
        func_0204A648();
    }
}

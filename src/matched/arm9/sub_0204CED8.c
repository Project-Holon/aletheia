/*
 * unit:     no
 * function: CLACT_ApplyActorInit
 * address:  0x0204CED8
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorSurfacePosAxis  0x0204B49C  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *
 * Apply the seven-field request to the object: the two signed halfwords at
 * +0 and +2 are the two axes of the same setter, selected by a trailing
 * 0/1; the byte at +6 replaces the low eight bits of the flag word at
 * +0x60; the byte at +7 and the halfword at +4 go to their own setters, and
 * CLACT_StartActorAnim commits the result.
 *
 * `ldrsh` with no immediate offset form is the only evidence that the first
 * two fields are `s16` rather than `u16`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md); the third is
 * `ldrh`, so the request really does mix the two.
 *
 * The flag-word update is a plain `bic #0xff` / `orr`, with no shift on
 * either side, which places the field at bit 0 and fixes its width at
 * eight: the value comes from an `ldrb`, so nothing has to mask it first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ApplyActorInit.c \
 *       --func CLACT_ApplyActorInit --addr 0x0204CED8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Req {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u8  unk_06;
    u8  unk_07;
};

struct Obj {
    u8  pad_00[0x60];
    u32 low     : 8;
    u32 flag_hi : 24;
};

struct Actor;
extern void CLACT_SetActorSurfacePosAxis(struct Actor *o, s16 value, u32 space, u32 axis);
extern void CLACT_SetActorBgPriority(struct Obj *o, u8 value);
extern void CLACT_SetActorAnimSeq(struct Obj *o, u16 value);
extern void CLACT_StartActorAnim(struct Actor *a);

void CLACT_ApplyActorInit(struct Obj *o, const struct Req *r, u32 space)
{
    CLACT_SetActorSurfacePosAxis((struct Actor *)o, r->unk_00, space, 0);
    CLACT_SetActorSurfacePosAxis((struct Actor *)o, r->unk_02, space, 1);
    o->low = r->unk_06;
    CLACT_SetActorBgPriority(o, r->unk_07);
    CLACT_SetActorAnimSeq(o, r->unk_04);
    CLACT_StartActorAnim((struct Actor *)o);
}

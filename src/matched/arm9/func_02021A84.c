/*
 * function: PALANM_FadeTask
 * address:  0x02021A84
 * packet:   pkt_02021984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PALANM_StepBgFades   0x02021B2C  thumb
 *   PALANM_StepObjFades   0x02021B4C  thumb
 *   func_02030EAC   0x02030EAC  arm
 *
 * Per-frame tick on the slot header at p+0x118. Two halfword bitfields sit
 * there, each `lo:14, hi:2` (the +0x11A one is the field PALANM_SetTransBit
 * sets bits in), followed by a u8 latch at p+0x11C.
 *
 * If the latch is set, the tick is a teardown: clear the latch, clear both
 * lo fields and bit 14 of the +0x11A one, and call out through 0x02030EAC.
 * Otherwise, when the low two bits of the +0x118 field read 1 (the "running"
 * mode), copy that field's 14 bits over the +0x11A field, step all fourteen
 * channels (PALANM_StepBgFades for 0..3, PALANM_StepObjFades for 4..0xD), and when the
 * +0x118 field has drained to zero, clear bit 14 of +0x11A and call out.
 *
 * EXACT* only: the compiled function is 148 bytes and correct throughout;
 * the listing's 168-byte extent runs on past the literal pool at 0x02021B10
 * into an unlabelled leaf at 0x02021B18 (`movs r0,#0x46; lsls r0,#2;
 * ldrh r2,[r0,r5]; ... strb r2,[r0,r1]; bx lr` -- a no-lr-saving accessor,
 * so disasm.py never labelled it). Worth seeding into
 * layout/function_starts.txt; reported rather than edited here.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S02021A84 {
    char pad[0x118];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
    u8  latch;
};

extern void PALANM_StepBgFades(u8 *p);
extern void PALANM_StepObjFades(u8 *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void PALANM_FadeTask(void *a, struct S02021A84 *p)
{
    if (p->latch == 1) {
        p->latch = 0;
        p->b_lo = 0;
        p->a_big = 0;
        p->b_x = 0;
        func_02030EAC(a);
        return;
    }

    if (p->a_mode != 1) {
        return;
    }

    p->b_lo = p->a_big;
    PALANM_StepBgFades((u8 *)p);
    PALANM_StepObjFades((u8 *)p);
    if (p->a_big == 0) {
        p->b_x = 0;
        func_02030EAC(a);
    }
}

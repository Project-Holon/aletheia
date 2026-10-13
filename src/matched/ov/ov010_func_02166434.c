/*
 * function: func_02166434
 * address:  0x02166434
 * packet:   pkt_ov010_02166434
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads two 4-bit values (bitfields at bits 6..9 and 10..13 of the word at +0x50 of
 * the record behind INTRUDE_COMM_GetPartnerRecord) into the out parameters, or takes them
 * from the two ov010 accessors when INTRUDE_COMM_GetPartnerSlot answers 4.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   func_021673C4  0x021673C4  thumb  ov010
 *   func_021673A8  0x021673A8  thumb  ov010
 *   func_02158344  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetPartnerRecord  0x02176880  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern u32 func_02012138(const struct Ctx *p);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *a, void *b);
extern u8 func_021673C4(u8 *p);
extern u8 func_021673A8(u8 *p);
extern int func_02158344(int a0);
struct Rec {
    u8 pad[0x50];
    u32 : 6;
    u32 a : 4;
    u32 b : 4;
};

extern u8 *INTRUDE_COMM_GetPartnerRecord(u8 *p);

int func_02166434(void *a, u32 *out0, u32 *out1)
{
    void *t;
    u8 *sav;
    void *r;
    struct Rec *rec;

    t = func_020120F4(a);
    sav = func_0200E0B0(func_02012EBC(t));
    r = (void *)func_02012138(a);
    if (INTRUDE_COMM_GetPartnerSlot(r, t) == 4) {
        *out0 = func_021673C4(sav);
        *out1 = func_021673A8(sav);
        return 1;
    }
    r = (void *)func_02158344((int)r);
    if (r == 0) {
        *out0 = 0;
        *out1 = 0;
        return 0;
    }
    rec = (struct Rec *)INTRUDE_COMM_GetPartnerRecord(r);
    *out0 = rec->a;
    *out1 = rec->b;
    return 1;
}

/*
 * function: BUTTON_MAN_UpdateSlots
 * address:  0x02051C88
 * packet:   pkt_02051C88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A15E8    0x020A15E8  data
 *   TOUCHPANEL_GetCont 0x02035C38  arm
 *   TOUCHPANEL_HitCont 0x02035BA4  arm
 *   TOUCHPANEL_HitTrg 0x02035C08  arm
 *   TOUCHPANEL_GetTrg 0x02035C60  arm
 *
 * The per-frame slot refresh: every slot state byte is rewritten to
 * (a == i) or (b == i) by its previous value, then every slot is dispatched
 * through the handler table at 0x020A15E8 and each result other than -1 is
 * forwarded to c->cb(i, v, c->arg).  Returns whether a slot newly took the
 * hover.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 352/352, 19 bytes out for
 * five waves, docs/notes/pkt_02051C88.c.txt): the loop index is
 * `unsigned long`, not u32 (unsigned int).  With u32 the first loop's
 * index and the slots base swap ip / lr over 13 instructions; mwcc colours
 * long and int as different types (the same fact wave 16 found with
 * `long i, j` in 0x02048744).  The unsigned compare against the s32 slot
 * indices is kept, which is what holds the fourth 1 in fp.
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;
typedef unsigned short u16;
typedef signed short   s16;

struct Slot { u8 kind; u8 state; u8 pad[2]; };

struct Ctx {
    s32   f00;            /* 0x00 */
    u32   n;              /* 0x04 */
    void (*cb)(s32, s32, s32);  /* 0x08 */
    s32   arg;            /* 0x0c */
    struct Slot *slots;   /* 0x10 */
};

extern s32 (*const g_020A15E8[])(struct Slot *, s32, s32);

extern s32 TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_HitCont(const void *p);
extern int TOUCHPANEL_HitTrg(const void *p);
extern s32 TOUCHPANEL_GetTrg(void);

s32 BUTTON_MAN_UpdateSlots(struct Ctx *c)
{
    s32 a;
    s32 b;
    s32 h, sel;
    s32 ret = 0;
    unsigned long i;

    a = 0;
    h = TOUCHPANEL_GetCont();
    if (h != 0) {
        a = TOUCHPANEL_HitCont((const void *)c->f00);
        b = TOUCHPANEL_HitTrg((const void *)c->f00);
        sel = TOUCHPANEL_GetTrg();

        for (i = 0; i < c->n; i++) {
            if (c->slots[i].state != 0) {
                c->slots[i].state = (u8)((a == i) ? 1 : 0);
            } else {
                c->slots[i].state = (u8)((b == i) ? 1 : 0);
                if (c->slots[i].state != 0)
                    ret = 1;
            }
        }
    } else {
        sel = 0;
        for (i = 0; i < c->n; i++)
            c->slots[i].state = (u8)a;
    }

    for (i = 0; i < c->n; i++) {
        s32 v = g_020A15E8[c->slots[i].kind](&c->slots[i], h, sel);
        if (v != -1)
            c->cb((s32)i, v, c->arg);
    }

    return ret;
}

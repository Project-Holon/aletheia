/*
 * function: func_021EDC0C
 * address:  0x021EDC0C
 * packet:   pkt_ov170_021EDC0C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the u16 fill value reuses the colour-index local t (t = (u16)((t << 8) | t));
 *   a separate v local takes the spill slot above ty instead of below it.
 *
 * symbols:
 *   func_02007A18  0x02007A18  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   func_02082A48  0x02082A48  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Personal;
struct Sav;
struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void func_02082A48(u32 value, void *dest, u32 size);

void func_021EDC0C(int **a, int box, u8 *dest)
{
    void *e;
    u32 sv;
    u8 y, x, tx, ty;
    u8 i;
    u32 sp, t;
    u16 form;
    for (ty = 11, y = 0; y < 5; ty += 2, y++) {
        tx = 10;
        for (x = 0; x < 6; tx += 2, x++) {
            e = func_02007A18((void *)(*a)[1], box, x + y * 6);
            sv = POKE_TOOL_DecodeBoxParam(e);
            sp = func_02017E88(e, 5, 0);
            if (func_02017E88(e, 0xa9, 0)) {
                if (func_02017E88(e, 0x4c, 0) == 0) {
                    void *pd;
                    form = func_02017E88(e, 0x6f, 0);
                    pd = POKE_PERSONAL_Create((u16)sp, form, 0x4c);
                    t = (u16)POKE_PERSONAL_GetParam(pd, 0x21);
                    POKE_PERSONAL_Delete(pd);
                } else {
                    t = (sp == 490) ? 1 : 8;
                }
                t = (u16)(t + 16);
                t = (u16)((t << 8) | t);
                for (i = ty; i < ty + 2; i++)
                    func_02082A48(t, dest + ((((i & 7) << 3) + ((((i >> 3) << 2) + (tx >> 3)) << 6)) + (tx & 7)), 2);
            }
            POKE_TOOL_EncodeBoxParam(e, sv);
        }
    }
}

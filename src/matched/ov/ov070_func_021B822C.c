/*
 * function: ITEMMENU_CheckItemFilter
 * address:  0x021B822C
 * packet:   pkt_ov070_021B822C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021014  0x02021014  thumb
 *   func_0202136C  0x0202136C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    unsigned char pad00[0x1C];
    int f1C;
} Obj;

struct Rec;
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_0202136C(u16 v);

void ITEMMENU_CheckItemFilter(Obj *o, void *rec, u16 *p, u8 *out)
{
    if (func_02021014(rec, 6) != 0) {
        if (func_0202136C(*p) == 1)
            *out = 2;
        else if (*p == 0x1C2 && o->f1C == 1)
            *out = 1;
        else
            *out = 0;
    }
    if ((u16)(*p + 0xFD98) <= 1)
        *out = 0;
}

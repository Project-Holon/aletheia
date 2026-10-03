/*
 * function: func_021F1184
 * address:  0x021F1184
 * packet:   pkt_ov107_021F1184
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020173E8  0x020173E8  thumb
 *   func_02017550  0x02017550  thumb
 */

typedef struct {
    unsigned char f00;
    unsigned char pad01;
    unsigned short f02;
} Ov107List;

typedef struct {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short rest : 13;
} Ov107Flags;

typedef struct {
    unsigned char pad00[0x10];
    Ov107List *f10;
    unsigned char pad14[4];
    Ov107Flags f18;
} Ov107Ctx;

typedef unsigned int   u32;
u32 func_020173E8(void);
struct Sav;
void func_02017550(struct Sav *);

void func_021F1184(Ov107Ctx *p)
{
    Ov107List *list;
    unsigned char i;

    list = p->f10;
    list->f00 = 0;
    list->f02 = 0;
    for (i = 0; i < 6; i++) {
        func_02017550((struct Sav *)((unsigned char *)p->f10 + i * func_020173E8() + 4));
    }
    p->f18.b1 = 0;
    p->f18.b2 = 0;
}

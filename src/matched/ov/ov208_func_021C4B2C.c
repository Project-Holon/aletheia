/*
 * function: ov208_func_021C4B2C
 * address:  0x021C4B2C
 * packet:   pkt_ov208_021C4B2C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   ov208_func_021C4B60  0x021C4B60  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ov208Menu {
    u8  pad0[0x57c];
    u32 print[5];
};

struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void ov208_func_021C4B60(void *a0, struct Ov208Menu *p, int key, int i);

void ov208_func_021C4B2C(void *a0, struct Ov208Menu *p, int key)
{
    u8 i;

    for (i = 0; i < 5; i++) {
        PRINTSYS_QUE_Main((struct PrintSys *)p->print[i]);
        ov208_func_021C4B60(a0, p, key, i);
    }
}

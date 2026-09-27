/*
 * function: func_021F1060
 * address:  0x021F1060
 * packet:   pkt_ov107_021F1060
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags f18;
    Ov107Flags f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx;

void *func_021F1060(Ov107Ctx *p)
{
    return p->f0C;
}

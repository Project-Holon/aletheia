/*
 * function: func_021C6828
 * address:  0x021C6828
 * packet:   pkt_ov021_021C6828
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c; } V;
typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem;
typedef struct { u8 pad[0x2c]; } Item;
typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem *fC; } Mgr;
void func_021C6828(Mgr *m, int idx, int v)
{
    m->fC[idx].b5 = v;
}

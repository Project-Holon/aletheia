/*
 * function: func_0220BC70
 * address: 0x0220BC70
 * packet: pkt_ov198_0220BC70
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * precondition: game callers supply state 0..8; every case initializes s.
 * evidence: C88's nine callers pass constants0..8; F4E0 dominates BC24
 * with state-byte2180 stores0/4/6. C88 stores its bounded state at2177+9.
 * Domain and decoded-call audit: Wave30 S26/BC70-domain-review.md.
 * symbols:
 *   func_0220BD84 0x0220BD84 thumb ov198
 *   func_0220BD34 0x0220BD34 thumb ov198
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_02211BDA 0x02211BDA data a1
 *   d_02211B80 0x02211B80 data a1
 *   d_02211CB0 0x02211CB0 data a1
 *   d_02211BFE 0x02211BFE data a1
 *   d_02211C24 0x02211C24 data a1
 *   d_02211B98 0x02211B98 data a1
 *   d_02211BB6 0x02211BB6 data a1
 *   d_02211C68 0x02211C68 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Item { u8 a,b,c,d,e,f; } Item;
extern Item d_02211BDA[],d_02211B80[],d_02211CB0[],d_02211BFE[],d_02211C24[],d_02211B98[],d_02211BB6[],d_02211C68[];
extern void func_0220BD84(u8 *);
extern void func_0220BD34(u8 *);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void func_0220BC70(u8 *p,u32 state)
{
    Item *s;
    u32 i;
    func_0220BD84(p);
    func_0220BD34(p);
    switch(state) {
    case 0: case 8: s=d_02211BDA; p[0x2174]=6; break;
    case 1: s=d_02211B80; p[0x2174]=4; break;
    case 2: s=d_02211CB0; p[0x2174]=22; break;
    case 3: s=d_02211BFE; p[0x2174]=6; break;
    case 4: s=d_02211C24; p[0x2174]=11; break;
    case 5: s=d_02211B98; p[0x2174]=5; break;
    case 6: s=d_02211BB6; p[0x2174]=6; break;
    case 7: s=d_02211C68; p[0x2174]=12; break;
    }
    for(i=0;i<p[0x2174];i++,s++)
        *(void **)(p+i*8+0x1F70)=(void *)BMP_WIN_Create(s->a,s->b,s->c,s->d,s->e,s->f,1);
}

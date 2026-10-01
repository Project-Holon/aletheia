/*
 * function: func_021AB0AC
 * address:  0x021AB0AC
 * packet:   pkt_ov021_021AB0AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb
 *   func_02158768  0x02158768  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x5bc];
    u16 h5bc;
} D;

typedef struct {
    u32 f0;
    void *f4;
    int pad[2];
    D *f10;
} S;

extern u16 func_02188C84(u32 a);
extern int func_02158768(void *a0, u32 a1, int a2, u16 a3);

void func_021AB0AC(S *s, u16 v)
{
    s->f10->h5bc = v;
    func_02158768(s->f4, 0x2795, 0, func_02188C84(s->f0));
}

/*
 * function: TOWNMAP_GRH_InitTextBox
 * address:  0x021BB3E8
 * packet:   pkt_ov072_021BB3E8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   STRBUF_Create  0x020457B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} W;

extern void func_02082BCC(void *p, int v, int n);
typedef unsigned int   u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

void TOWNMAP_GRH_InitTextBox(W *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4)
{
    func_02082BCC(p, 0, 0x10);
    p->f8 = b;
    p->fc = c;
    p->f0 = BMP_WIN_Create(a, s0, s1, s2, s3, 0xe, 0);
    p->f4 = (int)STRBUF_Create(0xff, s4);
}

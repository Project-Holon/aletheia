/*
 * function: func_021FB578
 * address:  0x021FB578
 * packet:   pkt_021FB578
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BMP_OAM_SetDrawPriority  0x020259C4  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Node;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void BMP_OAM_SetDrawPriority(u8 *g, u32 a);

void func_021FB578(int *p, unsigned char b)
{
    CLACT_SetActorDrawPriority((struct Node *)p[0], b);
    BMP_OAM_SetDrawPriority((u8 *)p[1], (unsigned char)(b - 1));
}

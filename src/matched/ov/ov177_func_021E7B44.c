/*
 * function: func_021E7B44
 * address: 0x021E7B44
 * packet: pkt_ov177_021E7B44
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 *
 * symbols:
 *   BMP_WIN_ClearScreen  0x020456F8  arm  arm9
 */
typedef struct { void *pad0; void *res[8]; } Work;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021E7B44(Work *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->res[i] != 0) {
            BMP_WIN_ClearScreen(p->res[i]);
            func_020452E8(p->res[i]);
        }
    }
}

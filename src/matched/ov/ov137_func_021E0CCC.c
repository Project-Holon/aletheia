/*
 * function: GURU2_MAIN_DropEffectStateFall
 * address: 0x021E0CCC
 * packet: pkt_ov137_021E0CCC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int GURU2_MAIN_DropEffectStateFall(int *p)
{
    int *q = (int *)p[4];
    q[21] -= p[3];
    if (p[2] == 0 && q[21] <= 0x68000) {
        p[2] = 1;
        GFL_USE_PlaySeDefaultVolume(0x725);
    }
    if (q[21] <= 0x20000) {
        q[21] = 0x20000;
        p[0] = 2;
    }
    return 0;
}

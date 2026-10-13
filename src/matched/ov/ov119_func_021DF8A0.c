/*
 * function: func_021DF8A0
 * address: 0x021DF8A0
 * packet: pkt_ov119_021DF8A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Add index to object base before the far timer offset.
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021E67E0 0x021E67E0 thumb ov119
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
extern int func_021D8AA8(void *);
extern void func_021E67E0(void *, int, int);
typedef unsigned int   u32;
extern int GFL_USE_IsSeqPlaying(u32 a);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021DF8A0(void *p, int a, int b)
{
    if (func_021D8AA8(p)) {
        func_021E67E0(p,a,b);
        ((unsigned char *)p+b)[0x11e4]=60;
        if (!GFL_USE_IsSeqPlaying(0x54a)) GFL_USE_PlaySeDefaultVolume(0x54a);
    }
}

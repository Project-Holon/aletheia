/*
 * function: BTL_CLIENT_ForgetMoveSoundCallback
 * address: 0x021D2C7C
 * packet: pkt_ov093_021D2C7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void GFL_USE_PlaySeDefaultVolume(unsigned int);
extern int GFL_USE_IsSeqPlaying(unsigned int);
int BTL_CLIENT_ForgetMoveSoundCallback(int n)
{
    switch (n) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56b);
        break;
    case 5:
        if (GFL_USE_IsSeqPlaying(0x56b) != 0) return 1;
        break;
    }
    return 0;
}

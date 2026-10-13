/*
 * function: func_021BA050
 * address: 0x021BA050
 * packet: pkt_ov172_021BA050
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0208B4B8 0x0208B4B8 arm
 *   NNS_SndWaveOutIsPlaying 0x02072CC4 arm
 *   func_021BA1E4 0x021BA1E4 thumb ov172
 */
typedef unsigned int u32;
struct O;
extern void *func_0208B4B8(void);
extern int NNS_SndWaveOutIsPlaying(struct O *);
extern void func_021BA1E4(void *);
void func_021BA050(u32 *p)
{
    u32 n;
    if (p[2] == 1) {
        n = (u32)func_0208B4B8();
        if (n == 0) p[0] = 0;
        else {
            p[0] = n - p[1] + 4;
            if (p[0] > 51200) p[0] = 51200;
        }
    }
    if (p[3] == 1) {
        if (NNS_SndWaveOutIsPlaying((struct O *)p[8]) == 0) p[3] = 0;
    }
    func_021BA1E4(p);
}

/*
 * function: func_021C4184
 * address: 0x021C4184
 * packet: pkt_ov136_021C4184
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02024450 unlabelled Thumb leaf, owned by the integrator.
 *   int PMSI_PARAM_IsEnabled(unsigned short *p) { return *p != 0xFFFF; }
 * symbols:
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMSI_PARAM_InitSentenceId 0x020242C0 thumb
 *   d_021C77A0 0x021C77A0 data a1
 */
typedef unsigned char u8;
extern const u8 d_021C77A0[][3];
typedef unsigned short u16;
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMSI_PARAM_InitSentenceId(void *a, void *b, void *c);
void func_021C4184(void *a, u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled((const u16 *)(p + 0x16 + i * 8)) == 0) {
            if (d_021C77A0[p[0xB]][i] != 0xFF) PMSI_PARAM_InitSentenceId(p + 0x16 + i * 8, (void *)5, (void *)d_021C77A0[p[0xB]][i]);
        }
        if (d_021C77A0[p[0xB]][i] == 0xFF) p[0x2E + i] = 0;
        else p[0x2E + i] = 1;
    }
}

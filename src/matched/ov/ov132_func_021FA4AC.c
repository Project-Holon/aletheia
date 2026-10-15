/*
 * function: STA_ACT_AUDIENCE_ApplyChoices
 * address: 0x021FA4AC
 * packet: pkt_ov132_021FA4AC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_AUDIENCE_RandomizeRecords 0x021FA528 thumb ov132
 *   func_02005728 0x02005728 thumb
 */
typedef unsigned char u8;
extern void STA_ACT_AUDIENCE_RandomizeRecords(char *);
extern unsigned func_02005728(unsigned);
void STA_ACT_AUDIENCE_ApplyChoices(char *p)
{
    u8 i;
    u8 n = 0;
    u8 choices[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1ec) == 1) { choices[n] = i; n++; }
    }
    if (n == 0) STA_ACT_AUDIENCE_RandomizeRecords(p);
    else {
        for (i = 0; i < 60; i++) {
            *(u8 *)(p + i * 8 + 0x205) = func_02005728(60) + 1;
            *(u8 *)(p + i * 8 + 0x204) = choices[func_02005728(n)];
        }
    }
}

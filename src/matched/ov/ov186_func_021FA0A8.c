/*
 * function: BR_BTN_Init
 * address: 0x021FA0A8
 * packet: pkt_ov186_021FA0A8
 * region: ov186
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef struct { unsigned words[17]; } Record;
extern void MI_CpuFill8(void *, int, unsigned);
int BR_BTN_Init(unsigned char *ctx, Record *out)
{
    if (ctx[0x3b]) {
        ctx[0x3b]--;
        *out = (*(Record **)(ctx + 0x3c))[ctx[0x3b]];
        MI_CpuFill8(&(*(Record **)(ctx + 0x3c))[ctx[0x3b]], 0, 0x44);
        return 1;
    }
    return 0;
}

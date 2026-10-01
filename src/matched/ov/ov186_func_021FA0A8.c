/*
 * function: func_021FA0A8
 * address: 0x021FA0A8
 * packet: pkt_ov186_021FA0A8
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef struct { unsigned words[17]; } Record;
extern void func_02082BCC(void *, int, unsigned);
int func_021FA0A8(unsigned char *ctx, Record *out)
{
    if (ctx[0x3b]) {
        ctx[0x3b]--;
        *out = (*(Record **)(ctx + 0x3c))[ctx[0x3b]];
        func_02082BCC(&(*(Record **)(ctx + 0x3c))[ctx[0x3b]], 0, 0x44);
        return 1;
    }
    return 0;
}

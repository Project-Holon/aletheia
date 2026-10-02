/*
 * function: func_02168EB0
 * address: 0x02168EB0
 * packet: pkt_ov010_02168EB0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: pooled ov220_id is passed to func_02012444 r1, missing from
 * OVERLAY_ID_CONSUMERS. Its matched body stores a1 to payload[0]; matched
 * func_0201240C forwards item[0] as func_020120B4 r1 (known consumer).
 * The ov220 table hint is supported by that load chain; matcher refuses
 * it as contested until the ID site resolves. No code leaf blocks this.
 * symbols:
 *   func_020124E8 0x020124E8 thumb
 *   func_02012444 0x02012444 thumb
 *   d_021BA39C 0x021BA39C data ov220 a4
 *   ov220_id 0x000000DC data
 */
typedef unsigned char u8;
extern u8 *func_020124E8(void *);
extern void *func_02012444(void *, unsigned int, unsigned int, unsigned int);
extern const unsigned int d_021BA39C[];
extern unsigned char ov220_id[];
int func_02168EB0(void *a, int *state)
{
    u8 *p;
    p = func_020124E8(a);
    switch (*state) {
    case 0:
        func_02012444(a, (unsigned int)ov220_id, (unsigned int)d_021BA39C, (unsigned int)(p + 8));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

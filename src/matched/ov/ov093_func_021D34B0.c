/*
 * function: func_021D34B0
 * address: 0x021D34B0
 * packet: pkt_ov093_021D34B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 54 bytes followed by two zero alignment bytes.
 * symbols:
 *   func_021CD9E0 0x021CD9E0 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int func_021CD9E0(void *);
extern void func_021F7998(unsigned int);
extern int func_021F7EB4(void);
int func_021D34B0(char *p, int *state, unsigned int *q)
{
    if (*state == 0) {
        if (func_021CD9E0(p) != 0) return 1;
        func_021F7998(q[0]);
        (*state)++;
    } else {
        if (func_021F7EB4() == 0) return 1;
    }
    return 0;
}

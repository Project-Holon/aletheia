/*
 * function: func_021DEEF8
 * address: 0x021DEEF8
 * packet: pkt_ov121_021DEEF8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Assign the sentinel before the signed-byte load to retain movs/mvns.
 * symbols:
 *   d_021DFA8C 0x021DFA8C data a1
 */
extern const signed char d_021DFA8C[][2];
typedef enum { NO_DIGIT = -1 } Digit;
int func_021DEEF8(const signed char *p)
{
    unsigned i;
    Digit digit;
    int result;
    int value;
    result = 0;
    for (;;) {
        digit = NO_DIGIT;
        value = *p;
        for (i = 0; i < 23; i++) {
            if (value == d_021DFA8C[i][0]) {
                digit = d_021DFA8C[i][1];
                break;
            }
        }
        if (digit == -1) break;
        result = (result << 4) + digit;
        p++;
    }
    return result;
}

/*
 * function: func_021B6A88
 * address: 0x021B6A88
 * packet: pkt_ov172_021B6A88
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6B68 0x021B6B68 thumb ov172
 */
typedef unsigned char u8;
typedef signed short s16;
extern s16 func_021B6B68(u8, char *);
void func_021B6A88(char *input, s16 *output, int size, char *state)
{
    int i, count;
    char code;
    count = size / 2;
    for (i = 0; i < count; i++) {
        code = input[i];
        output[i * 2] = func_021B6B68(code & 15, state);
        output[i * 2 + 1] = func_021B6B68((code & 240) >> 4, state);
    }
}

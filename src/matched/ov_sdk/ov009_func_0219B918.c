/*
 * function: func_0219B918
 * address:  0x0219B918
 * packet:   pkt_ov009_0219B918
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gs_encrypt (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0219B7FC  0x0219B7FC  arm   ov009
 */

extern void func_0219B7FC(unsigned char *a, unsigned char *b);

void func_0219B918(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len)
{
    short counter;
    unsigned char x;
    unsigned char y;
    unsigned char state[256];
    unsigned char xorIndex;

    for (counter = 0; counter < 256; counter++)
        state[counter] = (unsigned char)counter;
    x = 0;
    y = 0;
    for (counter = 0; counter < 256; counter++) {
        y = (key[x] + state[counter] + y) % 256;
        x = (x + 1) % key_len;
        func_0219B7FC(&state[counter], &state[y]);
    }
    x = 0;
    y = 0;
    for (counter = 0; counter < buffer_len; counter++) {
        x = (buffer_ptr[counter] + x + 1) % 256;
        y = (state[x] + y) % 256;
        func_0219B7FC(&state[x], &state[y]);
        xorIndex = (state[x] + state[y]) % 256;
        buffer_ptr[counter] ^= state[xorIndex];
    }
}

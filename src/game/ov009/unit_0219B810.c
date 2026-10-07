/*
 * file:     unit_0219B810.c
 * unit:     yes
 * function: func_0219B810, func_0219B858, func_0219B918
 * address:  0x0219B810
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0219B810  0x0219B810  arm  ov009
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0219B7FC  0x0219B7FC  arm   ov009
 */
extern unsigned char func_0219B810(unsigned char c);
extern void func_0219B7FC(unsigned char *a, unsigned char *b);
void func_0219B858(unsigned char *ins, int size, unsigned char *result);
void func_0219B918(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);

static unsigned char encode_ct(unsigned char c)
{
    if (c < 26)
        return (unsigned char)(c + 'A');
    if (c < 52)
        return (unsigned char)(c + 'G');
    if (c < 62)
        return (unsigned char)(c - 4);
    if (c == 62)
        return '+';
    if (c == 63)
        return '/';
    return 0;
}


/*
 * sdk:      gs_encode (qr2.o)
 */
void func_0219B858(unsigned char *ins, int size, unsigned char *result)
{
    int i;
    int pos;
    unsigned char trip[3];
    unsigned char kwart[4];

    i = 0;
    while (i < size) {
        for (pos = 0; pos <= 2; pos++, i++) {
            if (i < size)
                trip[pos] = *ins++;
            else
                trip[pos] = 0;
        }
        kwart[0] = trip[0] >> 2;
        kwart[1] = ((trip[0] & 3) << 4) + (trip[1] >> 4);
        kwart[2] = ((trip[1] & 15) << 2) + (trip[2] >> 6);
        kwart[3] = trip[2] & 63;
        for (pos = 0; pos <= 3; pos++)
            *result++ = func_0219B810(kwart[pos]);
    }
    *result = 0;
}


/*
 * sdk:      gs_encrypt (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
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

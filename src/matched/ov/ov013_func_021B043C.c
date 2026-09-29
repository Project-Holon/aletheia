/*
 * function: func_021B043C
 * address:  0x021B043C
 * packet:   pkt_ov013_021B043C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021AFFE4  0x021AFFE4  arm  ov013
 *   func_021AF628  0x021AF628  arm  ov013
 *   func_021AF340  0x021AF340  arm  ov013
 */

typedef unsigned char u8;
typedef short s16;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

extern void func_021AFFE4(void *src, void *dst, int n, AdpcmState *st);
extern void func_021AF628(void *src, void *dst, int n, AdpcmState *st);
extern void func_021AF340(void *src, void *dst, int n, AdpcmState *st);

void func_021B043C(AdpcmState *hdr, void *dst, int n, int mode)
{
    AdpcmState st;

    st.pred = hdr->pred;
    st.index = hdr->index;
    switch (mode) {
    case 2:
        func_021AFFE4((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 3:
        func_021AF628((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 4:
        func_021AF340((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    }
}

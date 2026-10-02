/*
 * function: func_02174B08
 * address: 0x02174B08
 * packet: pkt_ov012_02174B08
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020146F8 0x020146F8 thumb
 *   ov110_id 0x0000006E data a1
 *   d_021C39D4 0x021C39D4 data ov110 a4
 */
typedef unsigned char u8;
extern void *func_020146F8(char *, int, int, int, int);
extern u8 ov110_id[];
extern const int d_021C39D4[];
int func_02174B08(char *a, u8 *p, int b, int c, int x, void **out, u8 *state)
{
    if (*state == 0) {
        *out = func_020146F8(a, b, (int)ov110_id, (int)d_021C39D4, c);
    } else {
        return 1;
    }
    (*state)++;
    return 0;
}

/*
 * function: func_02174284
 * address: 0x02174284
 * packet: pkt_ov012_02174284
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020146F8 0x020146F8 thumb
 *   ov111_id 0x0000006F data a1
 *   d_02172608 0x02172608 data a4
 */
typedef unsigned char u8;
extern void *func_020146F8(char *, int, int, int, int);
extern u8 ov111_id[];
extern const int d_02172608[];
int func_02174284(char *a, u8 *p, int b, int c, int x, void **out, u8 *state)
{
    if (*state == 0) {
        *out = func_020146F8(a, b, (int)ov111_id, (int)d_02172608, c);
    } else {
        return 1;
    }
    (*state)++;
    return 0;
}

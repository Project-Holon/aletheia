/*
 * function: func_021CA6C4
 * address: 0x021CA6C4
 * packet: pkt_ov093_021CA6C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C5418 0x021C5418 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *);
extern int func_021C5418(u8 *, u8 *, int);
struct Msg;
extern int func_021C99A0(void *, const struct Msg *);
int func_021CA6C4(u8 *p, const u8 *q)
{
    u8 *m = func_021B9934(*(char **)(p + 8), q[4]);
    if (!func_021D5B68(m) && func_021C5418(p, m, *(const int *)(q + 8))) {
        func_021C99A0(p, (const struct Msg *)(q + 12));
        return 1;
    }
    return 0;
}

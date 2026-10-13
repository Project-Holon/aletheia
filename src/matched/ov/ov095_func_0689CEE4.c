/*
 * function: BTL_POKESET_RemoveFainted
 * address: 0x0689CEE4
 * packet: pkt_ov095_0689CEE4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKESET_SeekStart 0x0689CC84 thumb ov095
 *   BTL_POKESET_SeekNext 0x0689CC8C thumb ov095
 *   BTL_POKESET_Remove 0x0689CC14 thumb ov095
 *   func_0689CF14 0x0689CF14 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;
struct Cursor {
    u32 arr[16];
    u8 _40[2];
    u8 f42;
    u8 _43;
    u8 f44;
};
extern void BTL_POKESET_SeekStart(char *p);
struct S;
extern int BTL_POKESET_SeekNext(struct S *s);
extern void BTL_POKESET_Remove(S *p, u32 id);
extern int func_0689CF14(u32 id);
void BTL_POKESET_RemoveFainted(S *p)
{
    u32 id;
    BTL_POKESET_SeekStart((char *)p);
    id = BTL_POKESET_SeekNext((struct S *)p);
    while (id) {
        if (func_0689CF14(id))
            BTL_POKESET_Remove(p, id);
        id = BTL_POKESET_SeekNext((struct S *)p);
    }
}

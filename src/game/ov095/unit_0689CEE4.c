/*
 * file:     unit_0689CEE4.c
 * function: func_0689CEE4
 * address: 0x0689CEE4
 * packet: pkt_ov095_0689CEE4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5B68  0x021D5B68  thumb
 *   func_0689CC84 0x0689CC84 thumb ov095
 *   func_0689CC8C 0x0689CC8C thumb ov095
 *   func_0689CC14 0x0689CC14 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    void *id[6];
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
    void *arr[16];
    u8 _40[2];
    u8 f42;
    u8 _43;
    u8 f44;
};
extern void func_0689CC84(char *p);
struct S;
extern void *func_0689CC8C(struct S *s);
extern void func_0689CC14(S *p, void *id);
extern int func_021D5B68(void *id);
void func_0689CEE4(S *p)
{
    void *id;
    func_0689CC84((char *)p);
    id = func_0689CC8C((struct S *)p);
    while (id) {
        if (func_021D5B68(id))
            func_0689CC14(p, id);
        id = func_0689CC8C((struct S *)p);
    }
}

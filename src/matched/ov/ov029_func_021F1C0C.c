/*
 * function: func_021F1C0C
 * address:  0x021F1C0C
 * packet:   pkt_ov029_021F1C0C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA20  0x0204BA20  arm
 */

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

extern int func_0204B294(int, int, int, int, S13Rec *, int, int);
extern void func_0204B3DC(int, int);
extern void func_0204BA20(int, int);

void func_021F1C0C(char *p)
{
    S13Rec s;

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x28;
    s.a = 0;
    s.b = 2;
    *(int *)(p + 0x164) = func_0204B294(*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                                        *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
    func_0204B3DC(*(int *)(p + 0x164), 0);
    func_0204BA20(*(int *)(p + 0x164), 0);

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x27;
    s.a = 0x14;
    s.b = 2;
    *(int *)(p + 0x168) = func_0204B294(*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                                        *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
    func_0204B3DC(*(int *)(p + 0x168), 0);
    func_0204BA20(*(int *)(p + 0x168), 0);

    s.x = 0x22;
    s.y = 0xaa;
    s.z = 0x10;
    s.a = 0;
    s.b = 2;
    *(int *)(p + 0x16c) = func_0204B294(*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                                        *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
    func_0204B3DC(*(int *)(p + 0x16c), 0);
    func_0204BA20(*(int *)(p + 0x16c), 0);
}

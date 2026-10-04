/*
 * function: func_021F1950
 * address:  0x021F1950
 * packet:   pkt_ov029_021F1950
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02043598  0x02043598  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA20  0x0204BA20  arm
 *   func_021F1910  0x021F1910  thumb  ov029
 *   func_021F1F80  0x021F1F80  thumb  ov029
 *   func_021F20AC  0x021F20AC  thumb  ov029
 *   d_021F3526     0x021F3526  data  ov029  a1
 *   d_021F3531     0x021F3531  data  ov029  a1
 *   d_021F353C     0x021F353C  data  ov029  a1
 *   d_021F3548     0x021F3548  data  ov029  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

extern void func_02043598(u32 mask, u32 enable);
extern int func_02085D3C(void);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_021F1910(char *p, int on);
extern void func_021F1F80(char *p);
extern void func_021F20AC(char *p);
extern const u8 d_021F3526[];
extern const u8 d_021F3531[];
extern const u8 d_021F353C[];
extern const int d_021F3548[];

void func_021F1950(char *p)
{
    int i;
    int j;
    S13Rec s;
    int *q;

    func_02043598(0x10, 1);
    j = 0;
    for (i = 0; i < 11; i++) {
        s.x = d_021F3531[i];
        s.y = d_021F353C[i];
        s.z = d_021F3526[i];
        if (s.z == 6 && func_02085D3C()) {
            s.z = 7;
        }
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x4b] = (int)func_0204B294((void *)*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                                *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
        func_0204B3DC((struct Obj *)q[0x4b], 0);
        func_0204BA20((struct Actor *)q[0x4b], 0);
    }
    func_021F1910(p, 0);
    for (j = 0; j < 3; j++) {
        s.x = 8;
        s.y = 8;
        s.z = d_021F3548[j];
        s.a = 0;
        s.b = 2;
        q = (int *)(p + j * 4);
        q[0x56] = (int)func_0204B294((void *)*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                                *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
        func_0204B3DC((struct Obj *)q[0x56], 0);
        func_0204BA20((struct Actor *)q[0x56], 0);
    }
    func_021F1F80(p);
    func_021F20AC(p);
}

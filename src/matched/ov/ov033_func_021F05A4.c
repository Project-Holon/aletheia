/*
 * function: func_021F05A4
 * address:  0x021F05A4
 * packet:   pkt_ov033_021F05A4
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0C44 0x021F0C44 thumb ov033
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   d_021F0DC8 0x021F0DC8 data ov033 a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pad : 7;
} Ent;

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern const Ent d_021F0DC8[];
struct Obj;
extern void func_021F0C44(char *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(void *, Pt *, u16);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B8C4(struct Obj *p, u32 value);

void func_021F05A4(char *p, int flag)
{
    Pt pt;

    func_021F0C44(p);
    if (flag == 0)
        return;
    if (*(int *)(p + 0x6C) != *(int *)(p + 0x68)) {
        func_0204B3DC(*(void **)(p + 0x50),
                      (*(int *)(p + 0x68) == 8 || *(int *)(p + 0x68) == 9) ? 0 : 1);
        func_0204B3DC(*(void **)(p + 0x5C), *(int *)(p + 0x68) == 8);
        pt.x = d_021F0DC8[*(int *)(p + 0x68)].x;
        pt.y = d_021F0DC8[*(int *)(p + 0x68)].y;
        func_0204B404(*(void **)(p + 0x50), &pt, 1);
        func_0204B878(*(void **)(p + 0x38), d_021F0DC8[*(int *)(p + 0x68)].a);
        func_0204B878(*(void **)(p + 0x44), d_021F0DC8[*(int *)(p + 0x68)].b);
        func_0204B878(*(void **)(p + 0x50), d_021F0DC8[*(int *)(p + 0x68)].c);
        *(int *)(p + 0x6C) = *(int *)(p + 0x68);
    }
    if (*(int *)(p + 0x68) == 8 && *(int *)(p + 0xA4) != 0) {
        func_0204B878(*(void **)(p + 0x5C), 0);
        func_0204B92C(*(void **)(p + 0x5C), 1);
        func_0204B8C4(*(void **)(p + 0x5C), 0);
        *(int *)(p + 0xA4) = 0;
    }
}

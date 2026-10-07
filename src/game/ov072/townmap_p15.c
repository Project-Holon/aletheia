/*
 * file:     townmap_p15.c
 * unit:     yes
 * function: func_021BB4B4, func_021BB534, func_021BB548, func_021BB5AC, func_021BB5B4, func_021BB5D4, func_021BB5E0
 * address:  0x021BB4B4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BB3E8  0x021BB3E8  thumb  ov072
 *   func_0204B404  0x0204B404  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B974  0x0204B974  arm
 *   func_021BB42C 0x021BB42C thumb ov072
 *   func_0204B95C  0x0204B95C  arm
 *   func_021BB49C  0x021BB49C  thumb  ov072
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02013E4C  0x02013E4C  thumb
 *   func_021BB448  0x021BB448  thumb  ov072
 */
struct Obj;
struct Vec2;
struct Actor;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Pt { u16 x; u16 y; };

extern void func_02082BCC(void *p, int v, int n);
extern void func_021BB3E8(void *p, u32 a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g, u16 h);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B84C(void *h, u32 a);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B974(struct Actor *a);
extern void func_021BB42C(void **p);
extern void func_0204B95C(struct Actor *a);
extern void func_021BB49C(void **p);
extern u32 func_0204B98C(struct Actor *a);
extern int func_021BA774(char *p, int i);
extern u32 func_02013E4C(u32 id);
extern void func_021BB448(u32 *p, u32 a, int x, int y);
void func_021BB4B4(u32 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021BB534(void *p);
void func_021BB548(u32 *p);
void func_021BB5AC(int *p, int x);
void func_021BB5B4(u32 *p,u32 v);
void func_021BB5D4(void *p, int heap);
void func_021BB5E0(void *p);


void func_021BB4B4(u32 *p, u32 a, u32 b, u32 c, u32 d, u16 e)
{
    struct Pt pt;

    func_02082BCC(p, 0, 0x20);
    p[4] = d;
    func_021BB3E8(p, a, b, c, 0, 0, 0x18, 3, e);
    pt.x = 0x80;
    pt.y = 0x60;
    func_0204B404((void *)p[4], (const struct Vec2 *)(&pt), 0);
    func_0204B84C((void *)p[4], 1);
    func_0204B800((void *)p[4], 1);
    func_0204B3DC((void *)p[4], 1);
    func_0204B878((void *)p[4], 0);
    func_0204B92C((void *)p[4], 1);
    func_0204B974((void *)p[4]);
}

void func_021BB534(void *p) { func_021BB42C(p); func_02082BCC(p,0,0x20); }


void func_021BB548(u32 *p)
{
    if (p[7] != 0) {
        p[7] = 0;
        func_0204B878((void *)p[4], 0);
        func_0204B95C((void *)p[4]);
        func_0204B3DC((void *)p[4], 1);
        func_021BB49C((void **)p);
        p[6] = 1;
    }
    if (p[6] != 0 && func_0204B98C((struct Actor *)p[4]) == 0) {
        func_021BB448(p, func_02013E4C((u16)func_021BA774((char *)p[5], 0)), 0x10, 2);
        func_0204B974((void *)p[4]);
        p[6] = 0;
    }
}

void func_021BB5AC(int *p, int x)
{
    p[7] = 1;
    p[5] = x;
}

void func_021BB5B4(u32 *p,u32 v) { func_0204B3DC((void *)p[4],v); if(v==0) { p[7]=0; p[6]=0; func_021BB49C((void **)p); } }


void func_021BB5D4(void *p, int heap)
{
    func_02082BCC(p, 0, 0x30);
}


void func_021BB5E0(void *p)
{
    func_02082BCC(p, 0, 0x30);
}

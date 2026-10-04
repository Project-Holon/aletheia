/*
 * function: func_021BF308
 * address: 0x021BF308
 * packet: pkt_ov208_021BF308
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_021BC3A8 0x021BC3A8 thumb ov208
 *   func_021BCF4C 0x021BCF4C thumb ov208
 *   func_021BDC80 0x021BDC80 thumb ov208
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   d_021C851C 0x021C851C data ov208 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Index { INDEX_ZERO = 0 };
struct Pos { u16 x, y, z, pad; };
extern const u8 d_021C851C[];
extern void *func_021BC3B4(int);
extern char *func_021BC3A8(int);
extern int func_021BCF4C(char *);
extern int func_021BDC80(char *p);
extern void *func_020490F4(u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,u32);
/* Caller consumes r0 from the legacy void-returning allocation wrapper. */
extern u32 func_0204B294(u32,u32,u32,u32,struct Pos *,u16,u16);
struct Obj;
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B688(u32,u32);
void func_021BF308(u16 *heap, char *p, int key)
{
    struct Pos pos;
    void *scene;
    int owner;
    void *arc;
    enum Index i;
    u16 flag;
    scene = func_021BC3B4(key);
    owner = func_021BCF4C(func_021BC3A8(key));
    i = 0;
    arc = func_020490F4(0x9f, *heap);
    *(u32 *)(p + 0x9c) = func_021BDC80(scene);
    *(u32 *)(p + 0xa0) = func_0204A6C8(arc, 0xd, 0, 0, *heap);
    *(u32 *)(p + 0xa4) = func_0204AF28(arc, 0x1b, 0x2c, *heap);
    func_02049238(arc);
    flag = (u16)i;
    do {
        char *q;
        const u8 *t;
        func_02082BCC(&pos, 0, 8);
        t = d_021C851C + i * 9;
        q = p + i * 20;
        q[0x20] = t[2];
        q[0x21] = t[3];
        q[0x22] = t[4];
        q[0x23] = t[5];
        *(u16 *)(q + 0x24) = t[6];
        *(u16 *)(q + 0x26) = t[7];
        q[0x28] = t[8];
        *(u32 *)(q + 0x2c) = 0;
        pos.x = t[0];
        pos.y = t[1];
        pos.z = *(u16 *)(q + 0x24);
        *(u32 *)(q + 0x1c) = func_0204B294(owner, *(u32 *)(p + 0xa0), *(u32 *)(p + 0x9c), *(u32 *)(p + 0xa4), &pos, flag, *heap);
        func_0204B92C((struct Obj *)*(u32 *)(q + 0x1c), 1);
        func_0204B688(*(u32 *)(q + 0x1c), 1);
        i = (u8)(i + 1);
    } while ((u32)i < 6);
}

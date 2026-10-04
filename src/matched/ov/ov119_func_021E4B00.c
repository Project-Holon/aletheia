/*
 * function: func_021E4B00
 * address:  0x021E4B00
 * packet:   pkt_ov119_021E4B00
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * lever:    the slot base read in the compares and the end store is spelled ((u8 *)(p + row * 5) + j)[K]
 *           and the update stores plain, so 1.1p1 CSEs only the first group; the last three object
 *           reads use (u32)j * 4 so they recompute after the copy; the VRAM base is an enum local
 *           (operand order of 0x06600000 + addr, as in ov094_func_02204CC0).
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E4984 0x021E4984 thumb ov119
 *   func_021E49DC 0x021E49DC thumb ov119
 *   func_021E4AD0 0x021E4AD0 thumb ov119
 *   func_021E496C 0x021E496C thumb ov119
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_0204B454 0x0204B454 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02017E88 0x02017E88 thumb
 *   func_021E4A84 0x021E4A84 thumb ov119
 */
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u16 id; u8 b2, b3; } Ent;
typedef struct { s16 x, y; } Pt;
typedef struct { int a, b, c, d[6]; } Info;
struct Obj;
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021E4984(int v, int a, int b, char *p, int *out);
extern Ent *func_021E49DC(int a, int b, char *p);
extern void func_021E4AD0(char *p, int a1, int a2, int a3, int a4, int a5);
extern void func_021E496C(int x, int y, u16 *out);
extern void func_0204B7C8(void *, Info *);
extern int func_021D8AF4(int, char *);
extern int func_021D8B0C(int, int);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern int func_02061CA4(int, int, int, int);
extern void func_02082D44(int src, int dst, int n);
extern int func_0201BBE8(int);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *p, u32 v);
extern int func_02017E88(int, int, int);
extern int func_021E4A84(char *p, int i);
void func_021E4B00(char *p, int v, int a, int row, int flag)
{
    int j, rec, id, b2, b3, idx, n;
    Ent *e;
    Info info;
    int kind;
    u16 pos[2];
    Pt pt;
    enum { VRAM_BASE = 0x06600000 } vram;
    if (a == *(int *)(p + 0xf74) && func_020355C4() == 0) {
        func_0204B3DC(((void **)(p + row * 20 + 0xbb0))[*(int *)(p + 0xf78)], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = func_021E4984(v, a, j, p, &kind);
        e = func_021E49DC(a, j, p);
        if (e == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        if (e->id == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        ((u8 *)(p + row * 5) + j)[0xd90] = a;
        b2 = e->b2;
        id = e->id;
        b3 = e->b3;
        if (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 == ((u8 *)(p + row * 5) + j)[0xd18]
            && b3 == ((u8 *)(p + row * 5) + j)[0xd54]) {
            func_0204B3DC(*(void **)(p + row * 20 + j * 4 + 0xac0), 1);
            func_021E4AD0(p, a, j, rec, kind, row);
        } else if (id != *(u16 *)(p + row * 10 + j * 2 + 0xca0)
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 != ((u8 *)(p + row * 5) + j)[0xd18])
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b3 != ((u8 *)(p + row * 5) + j)[0xd54])) {
            *(u16 *)(p + row * 10 + j * 2 + 0xca0) = id;
            *(u8 *)(p + row * 5 + j + 0xd18) = b2;
            *(u8 *)(p + row * 5 + j + 0xd54) = b3;
            func_021E496C(a, j, pos);
            func_0204B7C8(*(void **)(p + row * 20 + j * 4 + 0xac0), &info);
            n = func_021D8AF4(a, p);
            idx = func_021D8B0C(a, j);
            idx += n * 30;
            func_0204B454((struct Actor *)*(void **)(p + row * 20 + j * 4 + 0xac0), (struct PtS *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (func_02061CA4(0x23, info.c, *(int *)(p + 0x1184) + idx * 0x200, 0x200) == 0) {
                    vram = VRAM_BASE;
                    func_02082D44(*(int *)(p + 0x1184) + idx * 0x200, vram + info.c, 0x200);
                }
            } else {
                vram = VRAM_BASE;
                func_02082D44(*(int *)(p + 0x1184) + idx * 0x200, vram + info.c, 0x200);
            }
            func_021E4AD0(p, a, j, rec, kind, row);
            func_0204B6F4(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), func_0201BBE8(rec), 1);
            func_0204B92C(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 0);
            func_0204B3DC(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 1);
        }
        if (func_02017E88(rec, 0x4c, 0) == 0 && func_021E4A84(p, id)) {
            ((u8 *)(p + row * 5) + j)[0xebc] = 1;
        }
    }
}

/*
 * function: func_021E467C
 * address:  0x021E467C
 * packet:   pkt_ov119_021E467C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void *func_0204ACEC(void *, int, int, int, int);
extern void *func_0204AF28(void *, int, int, int);
extern void *func_0204A6C8(void *, int, int, int, int);
extern void *func_0204B294(void *, void *, void *, void *, ObjTmpl *, int, int);
extern void func_0204B92C(void *, int);
extern void func_0204B3DC(void *, int);
extern void func_02049238(void *);
void func_021E467C(char *p)
{
    int i, j, z;
    void *arc;
    char *q;
    ObjTmpl t;
    arc = func_020490F4(7, *(u16 *)(p + 0x5f4));
    *(void **)(p + 0x87c) = func_0204ACEC(arc, func_0201BC3C(), 1, 0x60, *(u16 *)(p + 0x5f4));
    *(void **)(p + 0x8ac) = func_0204AF28(arc, func_0201BC78(), func_0201BCB4(), *(u16 *)(p + 0x5f4));
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.prio = 1;
            t.pal = 0x10;
            t.mode = 3;
            q = p + i * 20 + j * 4;
            *(void **)(q + 0x9cc) = func_0204A6C8(arc, 0x51b, z, 1, *(u16 *)(p + 0x5f4));
            *(void **)(q + 0xac0) = func_0204B294(*(void **)(p + 0x9c4), *(void **)(q + 0x9cc),
                *(void **)(p + 0x87c), *(void **)(p + 0x8ac), &t, 1, *(u16 *)(p + 0x5f4));
            t.prio = z;
            t.pal = 0xf;
            *(void **)(q + 0xbb0) = func_0204B294(*(void **)(p + 0x9c4), *(void **)(p + 0x894),
                *(void **)(p + 0x880), *(void **)(p + 0x8b0), &t, 1, *(u16 *)(p + 0x5f4));
            func_0204B92C(*(void **)(q + 0xac0), z);
            func_0204B3DC(*(void **)(q + 0xac0), z);
            func_0204B3DC(*(void **)(q + 0xbb0), z);
            func_0204B92C(*(void **)(q + 0xbb0), 1);
        }
    }
    func_02049238(arc);
}

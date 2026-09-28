/*
 * function: func_021F5CA4
 * address:  0x021F5CA4
 * packet:   pkt_021F5CA4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
 * symbols:
 *   tbl_02202E24  0x02202E24  data  a1
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0xBF4];
    u32 cursor;
} Work;

extern int func_02035C08(const void *key);
extern void func_0204B3DC(u32 obj, int on);
extern void func_020355D8(int v);
extern const u8 tbl_02202E24[];

int func_021F5CA4(Work *p)
{
    int r = func_02035C08(tbl_02202E24);

    if (r != -1) {
        func_0204B3DC(p->cursor, 0);
        func_020355D8(1);
    }
    return r;
}

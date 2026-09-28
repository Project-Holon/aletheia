/*
 * function: func_021F84EC
 * address:  0x021F84EC
 * packet:   pkt_021F84EC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_0204A298  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   g_02203C00     0x02203C00  data  ov135
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_02203C00[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern void *func_0204A298(u32 archive_id, u32 member, u32 kind, u32 heap, u32 *size);
extern void func_020307B0(void *p);

u8 *func_021F84EC(u32 id)
{
    u32 size;
    u32 i;
    u8 *buf;
    u16 *tbl;
    u32 n;

    buf = func_02030734(0x48, 0x28A, 0, (const char *)g_02203C00, 0x796);
    func_02082AC0(0, buf, 0x28A);
    tbl = func_0204A298(0x62, 4, 0, (u16)id, &size);
    n = size / 2;
    for (i = 0; i < n; i++) {
        if (tbl[i] < 0x28A) {
            buf[tbl[i]] = 1;
        }
    }
    func_020307B0(tbl);
    return buf;
}

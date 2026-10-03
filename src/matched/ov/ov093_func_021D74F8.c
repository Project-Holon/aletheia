/*
 * function: func_021D74F8
 * address:  0x021D74F8
 * packet:   pkt_ov093_021D74F8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021F3ECC     0x021F3ECC  data
 *   data_021F3AB4  0x021F3AB4  data
 *   func_02034714  0x02034714  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl;

extern Tbl g_021F3ECC;
extern char data_021F3AB4[];
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_021D74F8(int line)
{
    Tbl *p = &g_021F3ECC;
    while (p->count < 0x60) {
        if (p->keys[p->count] == 0) break;
        p->count++;
    }
    if (p->count < 0x5F) {
        p->keys[p->count++] = 1;
    } else {
        func_02034714(data_021F3AB4, 0, data_021F3AB4);
    }
}

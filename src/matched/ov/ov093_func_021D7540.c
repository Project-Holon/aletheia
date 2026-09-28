/*
 * function: func_021D7540
 * address:  0x021D7540
 * packet:   pkt_ov093_021D7540
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021F3ECC     0x021F3ECC  data
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
void func_021D7540(int line)
{
    Tbl *p = &g_021F3ECC;
    u16 i;
    if (p->count != 0) {
        i = p->count;
        while (i < 0x60 && p->keys[i] != 0) {
            p->keys[i++] = 0;
        }
        p->count--;
        p->keys[p->count] = 0;
        if (p->count != 0) {
            while (p->count != 0) {
                p->count--;
                if (p->keys[p->count] == 1) {
                    p->count++;
                    return;
                }
            }
        }
    }
}

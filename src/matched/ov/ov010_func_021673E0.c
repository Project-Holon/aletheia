/*
 * function: func_021673E0
 * address:  0x021673E0
 * packet:   pkt_ov010_021673E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Copies `count` 4-byte entries starting at index `start` out of the
 * shared list under its lock into a cleared buffer of `cap` entries, and
 * answers how many leading entries are in use (non-zero 11-bit id).
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0200E06C  0x0200E06C  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0200E024  0x0200E024  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0200E06C(char *p);
extern void func_0200E024(void *p);

u8 func_021673E0(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count)
{
    int i;

    i = 0;
    MI_CpuFill8(out, 0, cap * 4);
    func_0200E06C((char *)list);
    MI_CpuCopy8(&list[start], out, count * 4);
    func_0200E024(list);
    for (i = 0; i < count; i++) {
        if (out[i].id == 0)
            break;
    }
    return i;
}

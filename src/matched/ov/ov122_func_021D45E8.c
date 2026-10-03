/*
 * function: func_021D45E8
 * address: 0x021D45E8
 * packet: pkt_ov122_021D45E8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes after the return, next function 021D4630.
 * symbols:
 *   func_02051C6C 0x02051C6C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 */
extern void func_02051C6C(void *);
typedef unsigned int   u32;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_0201F7A8(void *, unsigned);
extern void func_020452E8(struct Descriptor *d);
void func_021D45E8(char *p)
{
    int i;
    char *q;
    if (*(void **)(p + 0x40)) func_02051C6C(*(void **)(p + 0x40));
    *(int *)(p + 0x40) = 0;
    for (i = 0; i < 11; i++) {
        q = p + i * 4;
        if (*(void **)(q + 0x10)) {
            func_020456F8(*(void **)(q + 0x10));
            func_02041B6C(5);
            func_0201F7A8(*(void **)(q + 0x10), 2);
            func_020452E8(*(void **)(q + 0x10));
        }
        *(int *)(q + 0x10) = 0;
    }
    *(int *)(p + 0x348) = 0;
}

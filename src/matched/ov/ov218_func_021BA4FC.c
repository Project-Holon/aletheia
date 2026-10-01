/*
 * function: func_021BA4FC
 * address: 0x021BA4FC
 * packet: pkt_ov218_021BA4FC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
extern unsigned func_0204B3F4(void *);
extern void func_0204B3DC(void *, unsigned);
void func_021BA4FC(char *ctx)
{
    int i;
    void *item;
    if (*(int *)(ctx + 0x32c) != 0) {
        *(int *)(ctx + 0x32c) = 0;
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x294 + i * 4);
            if (func_0204B3F4(item) != 0)
                func_0204B3DC(item, 0);
        }
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x2b0 + i * 4);
            if (func_0204B3F4(item) != 0)
                func_0204B3DC(item, 0);
        }
    }
}

/*
 * function: func_02211190
 * address: 0x02211190
 * packet: pkt_ov198_02211190
 * region: ov198
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   func_02210F84 0x02210F84 thumb ov198
 *   func_02210F98 0x02210F98 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
extern int func_022110D4(u8 *, int);
extern u32 func_02210F04(u32, u32);
extern int func_02210F84(char **, unsigned);
extern int func_02210F98(u8 *, int);
extern void *func_02045EC0(void *, u32);
extern void func_02045808(void *);
extern void func_0201EEF4(void *, u32, void *);
extern void func_0201F250(void *, void *, void *);
int func_02211190(u8 *p)
{
    u8 *row;
    int idx;
    void *text;
    idx = func_022110D4(p, (*(u8 **)p)[0x20]);
    row = p + 4 + idx * 0x4c;
    if (func_02210F04((u32)p, idx) == 1) {
        text = func_02045EC0(*(void **)(p + 0x1ea0), 0x5a);
        func_0201F250(*(void **)(p + 0x1ea4), *(void **)(p + 0x1ea8), text);
        func_02045808(text);
        return 0;
    }
    if (func_02210F84((char **)p, (*(u8 **)p)[0x20]) == 0) {
        if (func_02210F84((char **)p, idx) == 1)
            text = func_02045EC0(*(void **)(p + 0x1ea0), 0x6b);
        else
            text = func_02045EC0(*(void **)(p + 0x1ea0), 0x6a);
        func_0201EEF4(*(void **)(p + 0x1ea4), 0, *(void **)row);
        func_0201F250(*(void **)(p + 0x1ea4), *(void **)(p + 0x1ea8), text);
        func_02045808(text);
        return 0;
    }
    if (func_02210F98(p, (*(u8 **)p)[0x20]) == 1) {
        text = func_02045EC0(*(void **)(p + 0x1ea0), 0x56);
        func_0201EEF4(*(void **)(p + 0x1ea4), 0, *(void **)row);
        func_0201F250(*(void **)(p + 0x1ea4), *(void **)(p + 0x1ea8), text);
        func_02045808(text);
        return 0;
    }
    if (*(u16 *)(row + 0x10) != 0) {
        text = func_02045EC0(*(void **)(p + 0x1ea0), 0x56);
        func_0201EEF4(*(void **)(p + 0x1ea4), 0, *(void **)row);
        func_0201F250(*(void **)(p + 0x1ea4), *(void **)(p + 0x1ea8), text);
        func_02045808(text);
        return 0;
    }
    return 1;
}

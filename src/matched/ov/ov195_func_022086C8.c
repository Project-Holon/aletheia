/*
 * function: func_022086C8
 * address:  0x022086C8
 * packet:   pkt_022086C8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F7C 0x02208F7C data
 *   func_02030734 0x02030734 arm
 *   func_0207ADC4 0x0207ADC4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct Node {
    u16 f00;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u8 pad40[4];
} Node;

extern char d_02208F7C[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0207ADC4(void *);

Node *func_022086C8(u16 heap, u16 n)
{
    Node *p = func_02030734(heap, n * sizeof(Node), 1, d_02208F7C, 0xe8);
    u16 i;

    for (i = 0; i < n; i++) {
        p[i].tx = 0;
        p[i].ty = 0;
        p[i].tz = 0;
        p[i].sx = 0x1000;
        p[i].sy = 0x1000;
        p[i].sz = 0x1000;
        func_0207ADC4(p[i].mtx);
    }
    return p;
}

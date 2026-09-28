/*
 * function: func_02156F68
 * address:  0x02156F68
 * packet:   pkt_ov010_02156F68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_02172754  0x02172754  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Stage {
    void *f00;          /* 0x00 */
    void *f04[4];       /* 0x04 */
    u8 pad14[0x20 - 0x14];
} Stage;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern const char d_02172754[];

Stage *func_02156F68(u32 heap, void *p)
{
    Stage *s;
    u8 i;

    s = func_02030734(heap, 0x20, 0, d_02172754, 0xBE);
    s->f00 = p;
    for (i = 0; i < 4; i++)
        s->f04[i] = 0;
    return s;
}

/*
 * function: func_0220602C
 * address:  0x0220602C
 * packet:   pkt_0220602C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02014D2C 0x02014D2C thumb
 *   func_02206664 0x02206664 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x4a];
    void *mcss;
    u8 pad50[0x5c - 0x50];
    u32 f5c;
} Owner;

extern void func_02014D2C(void *mcss);
extern void func_02206664(Owner *o);

void func_0220602C(Owner *o)
{
    if (o->f5c != 0)
        func_02014D2C(o->mcss);
    else
        func_02206664(o);
}

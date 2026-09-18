/*
 * function: func_020253D4
 * address:  0x020253D4
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_020253D4(u8 *p, u32 id, u32 bank)
{
    u32 curr = id;
    int offset = 1;
    u32 next;
    u32 val;

    if (bank == 0) {
        offset = 0;
    }
    p += offset << 4;

    val = (p + id)[6];
    next = id;
    if (id != val) {
        return;
    }

    do {
        p[curr + 6] = 0xff;
        next++;
        val = (p + next)[6];
        curr = next;
    } while (id == val);
}

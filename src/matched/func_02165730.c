/*
 * function: func_02165730
 * address:  0x02165730
 * packet:   pkt_02165730
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 *
 * symbols:
 *   func_0202744C   0x0202744C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0202744C(void *, int);

void func_02165730(void *a0)
{
    *(u16 *)((char *)a0 + 0x30) = 0x2D;
    func_0202744C(a0, 0x2D);
}


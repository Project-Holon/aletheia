/*
 * function: TPOKE_Delete
 * address:  0x0202A170
 * packet:   pkt_0202A170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
typedef struct { void *p0; void *p1; } XmlReader;
void TPOKE_Delete(XmlReader *reader)
{
    func_020307B0(reader->p1);
    func_020307B0(reader->p0);
    func_020307B0(reader);
}
